from django.contrib.auth.models import AbstractUser
from django.db import models
from django.utils import timezone
from datetime import timedelta

class CustomUser(AbstractUser):
    avatar = models.ImageField(upload_to='avatars/', null=True, blank=True)
    games_played = models.IntegerField(default=0)
    games_won_count = models.IntegerField(default=0)
    total_score = models.IntegerField(default=0)
    last_activity = models.DateTimeField(default=timezone.now)
    followers = models.ManyToManyField('self', symmetrical=False, related_name='following')
    friends = models.ManyToManyField('self', symmetrical=True, blank=True)

    @property
    def is_online(self):
        return self.last_activity > timezone.now() - timedelta(minutes=5)

    @property
    def win_rate(self):
        if self.games_played > 0:
            return (self.games_won_count / self.games_played) * 100
        return 0
    
    @property
    def match_history(self):
        from pong_game.models import Game
        return Game.objects.filter(models.Q(player1=self) | models.Q(player2=self))

    def __str__(self):
        return self.username

class Match(models.Model):
    player1 = models.ForeignKey(CustomUser, on_delete=models.CASCADE, related_name='matches_as_player1')
    player2 = models.ForeignKey(CustomUser, on_delete=models.CASCADE, related_name='matches_as_player2')
    player1_score = models.IntegerField()
    player2_score = models.IntegerField()
    date_played = models.DateTimeField(auto_now_add=True)
    winner = models.ForeignKey(CustomUser, on_delete=models.CASCADE, related_name='matches_won', null=True)

    def __str__(self):
        return f"{self.player1.username} vs {self.player2.username} - {self.date_played}"