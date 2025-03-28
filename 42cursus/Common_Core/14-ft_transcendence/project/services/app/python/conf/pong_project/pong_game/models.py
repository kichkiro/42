import random
from django.db import models
from django.conf import settings
from django.utils import timezone
from django.core.exceptions import ValidationError
from django.contrib.auth import get_user_model

User = get_user_model()

class Notification(models.Model):
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='notifications')
    message = models.CharField(max_length=255)
    created_at = models.DateTimeField(auto_now_add=True)
    is_read = models.BooleanField(default=False)

    def __str__(self):
        return f"Notification for {self.user.username}: {self.message}"

class PlayerStats(models.Model):
    user = models.OneToOneField(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='stats')
    tournaments_won = models.IntegerField(default=0)
    tournaments_participated = models.IntegerField(default=0)
    highest_score = models.IntegerField(default=0)
    total_time_played = models.DurationField(default=timezone.timedelta())

    def __str__(self):
        return f"Stats for {self.user.username}"

class Tournament(models.Model):
    name = models.CharField(max_length=100)
    creator = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='created_tournaments')
    max_participants = models.IntegerField()
    status = models.CharField(max_length=20, choices=[
        ('REGISTRATION', 'Registration Open'),
        ('IN_PROGRESS', 'In Progress'),
        ('FINISHED', 'Finished')
    ], default='REGISTRATION')
    current_round = models.IntegerField(default=1)
    created_at = models.DateTimeField(auto_now_add=True)

    @classmethod
    def get_active_tournament(cls):
        return cls.objects.filter(status__in=['REGISTRATION', 'IN_PROGRESS']).first()

    @classmethod
    def can_create_new(cls):
        return not cls.objects.filter(status__in=['REGISTRATION', 'IN_PROGRESS']).exists()

    def clean(self):
        super().clean()
        if self.max_participants not in [2, 4, 8, 16, 32]:
            raise ValidationError({"max_participants": "Il numero di partecipanti deve essere 2, 4, 8, 16 o 32."})

    def save(self, *args, **kwargs):
        self.full_clean()
        super().save(*args, **kwargs)
        
    def is_full(self):
        return self.participants.count() >= self.max_participants

    def start_if_full(self):
        if self.is_full():
            self.start_tournament()

    def generate_matches(self):
        participants = list(self.participants.all())
        if len(participants) < 2:
            raise ValidationError("Non ci sono abbastanza partecipanti per generare le partite.")
        
        random.shuffle(participants)
        
        for i in range(0, len(participants), 2):
            if i + 1 < len(participants):
                TournamentMatch.objects.create(
                    tournament=self,
                    player1=participants[i],
                    player2=participants[i+1],
                    round=self.current_round
                )

    def start_tournament(self):
        if self.status != 'REGISTRATION' or not self.is_full():
            return False
        self.status = 'IN_PROGRESS'
        self.save()
        self.generate_matches()
        return True

    def advance_tournament(self):
        current_matches = self.matches.filter(round=self.current_round, winner__isnull=False)
        if current_matches.count() == self.matches.filter(round=self.current_round).count():
            winners = [match.winner for match in current_matches]
            if len(winners) == 1:
                self.status = 'FINISHED'
                self.save()
            else:
                self.current_round += 1
                self.save()
                # Crea le partite per il prossimo round
                for i in range(0, len(winners), 2):
                    if i+1 < len(winners):
                        TournamentMatch.objects.create(
                            tournament=self,
                            player1=winners[i],
                            player2=winners[i+1],
                            round=self.current_round
                        )
                    else:
                        # Se c'è un numero dispari di vincitori, l'ultimo passa automaticamente al round successivo
                        TournamentMatch.objects.create(
                            tournament=self,
                            player1=winners[i],
                            player2=None,
                            round=self.current_round
                        )

class TournamentParticipant(models.Model):
    tournament = models.ForeignKey(Tournament, on_delete=models.CASCADE, related_name='participants')
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.SET_NULL, null=True, blank=True)
    alias = models.CharField(max_length=50)
    eliminated = models.BooleanField(default=False)

    class Meta:
        unique_together = ('tournament', 'alias')

    def __str__(self):
        return f"{self.alias} in {self.tournament.name}"

class TournamentMatch(models.Model):
    tournament = models.ForeignKey(Tournament, on_delete=models.CASCADE, related_name='matches')
    player1 = models.ForeignKey(TournamentParticipant, on_delete=models.CASCADE, related_name='matches_as_player1')
    player2 = models.ForeignKey(TournamentParticipant, on_delete=models.CASCADE, related_name='matches_as_player2')
    winner = models.ForeignKey(TournamentParticipant, on_delete=models.SET_NULL, null=True, blank=True, related_name='matches_won')
    round = models.IntegerField()
    score_player1 = models.IntegerField(default=0)
    score_player2 = models.IntegerField(default=0)

    def __str__(self):
        return f"{self.player1.alias} vs {self.player2.alias} in {self.tournament.name} (Round {self.round})"
    
class Game(models.Model):
    player1 = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='games_as_player1')
    player2 = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='games_as_player2', null=True, blank=True)
    player2_alias = models.CharField(max_length=50, null=True, blank=True)
    score_player1 = models.IntegerField(default=0)
    score_player2 = models.IntegerField(default=0)
    date_played = models.DateTimeField(auto_now_add=True)
    winner = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='games_won', null=True, blank=True)
    status = models.CharField(max_length=20, choices=[
        ('WAITING', 'Waiting'),
        ('IN_PROGRESS', 'In Progress'),
        ('FINISHED', 'Finished')
    ], default='WAITING')
    is_single_game = models.BooleanField(default=False)

    def __str__(self):
        return f"Game {self.id}: {self.player1.username} vs {self.player2.username if self.player2 else self.player2_alias}"

    def save(self, *args, **kwargs):
        is_new = self.pk is None
        super().save(*args, **kwargs)

        if is_new and self.status == 'FINISHED':
            self.player1.games_played += 1
            self.player1.total_score += self.score_player1
            
            if self.player2:
                self.player2.games_played += 1
                self.player2.total_score += self.score_player2

            if self.winner:
                self.winner.games_won_count += 1

            self.player1.save()
            if self.player2:
                self.player2.save()

    # @classmethod
    # def create_from_match_requests(cls, request1, request2):
    #     game = cls.objects.create(
    #         player1=request1.player,
    #         player2=request2.player,
    #         status='WAITING'
    #     )
    #     request1.is_active = False
    #     request2.is_active = False
    #     request1.save()
    #     request2.save()
    #     return game

class MatchRequest(models.Model):
    player = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    created_at = models.DateTimeField(auto_now_add=True)
    is_active = models.BooleanField(default=True)

    def __str__(self):
        return f"Match request by {self.player.username}"
    
class Lobby(models.Model):
    name = models.CharField(max_length=100)
    creator = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='created_lobbies')
    players = models.ManyToManyField(settings.AUTH_USER_MODEL, related_name='joined_lobbies')
    max_players = models.IntegerField(default=2)
    is_active = models.BooleanField(default=True)
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.name

class ChatMessage(models.Model):
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    room = models.CharField(max_length=255)
    content = models.TextField()
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.user.username}: {self.content} [{self.timestamp}]'