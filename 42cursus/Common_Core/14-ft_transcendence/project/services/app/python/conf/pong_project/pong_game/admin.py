from django.contrib import admin
from .models import Tournament, TournamentParticipant, Game, MatchRequest, Lobby

@admin.register(Tournament)
class TournamentAdmin(admin.ModelAdmin):
    list_display = ['name', 'status', 'max_participants', 'current_round', 'created_at']
    list_filter = ['status']
    search_fields = ['name']

@admin.register(TournamentParticipant)
class TournamentParticipantAdmin(admin.ModelAdmin):
    list_display = ['alias', 'tournament']
    list_filter = ['tournament']
    search_fields = ['alias', 'tournament__name']

@admin.register(Game)
class GameAdmin(admin.ModelAdmin):
    list_display = ['id', 'player1', 'player2', 'player2_alias', 'score_player1', 'score_player2', 'status', 'is_single_game', 'date_played']
    list_filter = ['status', 'is_single_game', 'date_played']
    search_fields = ['player1__username', 'player2__username', 'player2_alias']

@admin.register(MatchRequest)
class MatchRequestAdmin(admin.ModelAdmin):
    list_display = ('player', 'created_at', 'is_active')
    list_filter = ('is_active',)
    search_fields = ('player__username',)

@admin.register(Lobby)
class LobbyAdmin(admin.ModelAdmin):
    list_display = ('name', 'creator', 'max_players', 'is_active', 'created_at')
    list_filter = ('is_active',)
    search_fields = ('name', 'creator__username')