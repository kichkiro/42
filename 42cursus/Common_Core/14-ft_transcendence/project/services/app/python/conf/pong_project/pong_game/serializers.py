from rest_framework import serializers
from .models import Game, Lobby, MatchRequest, Tournament, TournamentParticipant, TournamentMatch, Notification, PlayerStats
from accounts.serializers import UserSerializer
from django.contrib.auth import get_user_model
from rest_framework_simplejwt.serializers import TokenObtainPairSerializer

CustomUser = get_user_model()
User = get_user_model()

class MyTokenObtainPairSerializer(TokenObtainPairSerializer):
    @classmethod
    def get_token(cls, user):
        token = super().get_token(user)

        # Aggiungi campi personalizzati al payload
        token['username'] = user.username

        return token

class GameSerializer(serializers.ModelSerializer):
    player1 = serializers.HiddenField(default=serializers.CurrentUserDefault())
    player2 = serializers.PrimaryKeyRelatedField(queryset=User.objects.all(), required=False, allow_null=True)
    winner = serializers.PrimaryKeyRelatedField(read_only=True, allow_null=True)
    player1_username = serializers.CharField(source='player1.username', read_only=True)
    player2_username = serializers.CharField(source='player2.username', read_only=True, allow_null=True)
    winner_username = serializers.CharField(source='winner.username', read_only=True, allow_null=True)
    player2_alias = serializers.CharField(required=False, allow_blank=True)

    class Meta:
        model = Game
        fields = [
            'id',
            'player1', 'player1_username',
            'player2', 'player2_username', 'player2_alias',
            'score_player1', 'score_player2',
            'winner', 'winner_username',
            'status', 'date_played', 'is_single_game',
        ]
        read_only_fields = ['id', 'date_played', 'winner', 'player1', 'player1_username', 'player2_username', 'winner_username']

    def create(self, validated_data):
        request = self.context.get('request')
        validated_data['player1'] = request.user

        if 'player2_alias' in validated_data:
            validated_data['player2'] = None

        return super().create(validated_data)

class MatchRequestSerializer(serializers.ModelSerializer):
    player = UserSerializer(read_only=True)

    class Meta:
        model = MatchRequest
        fields = '__all__'

class LobbySerializer(serializers.ModelSerializer):
    class Meta:
        model = Lobby
        fields = ['id', 'name', 'creator', 'players', 'max_players', 'is_active', 'created_at']
        read_only_fields = ['creator', 'players', 'is_active', 'created_at']

class TournamentParticipantSerializer(serializers.ModelSerializer):
    class Meta:
        model = TournamentParticipant
        fields = ['id', 'alias', 'eliminated']

class TournamentMatchSerializer(serializers.ModelSerializer):
    player1_alias = serializers.CharField(source='player1.alias', read_only=True)
    player2_alias = serializers.CharField(source='player2.alias', read_only=True)
    winner_alias = serializers.CharField(source='winner.alias', read_only=True)

    class Meta:
        model = TournamentMatch
        fields = ['id', 'player1_alias', 'player2_alias', 'winner_alias', 'score_player1', 'score_player2', 'round']

class TournamentSerializer(serializers.ModelSerializer):
    creator = serializers.PrimaryKeyRelatedField(read_only=True)
    participants = TournamentParticipantSerializer(many=True, read_only=True)
    matches = TournamentMatchSerializer(many=True, read_only=True)

    class Meta:
        model = Tournament
        fields = ['id', 'name', 'creator', 'max_participants', 'status', 'current_round', 'created_at', 'participants', 'matches']
        read_only_fields = ('creator',)

    def validate_max_participants(self, value):
        if value not in [2, 4, 8, 16, 32]:
            raise serializers.ValidationError("Il numero di partecipanti deve essere 2, 4, 8, 16 o 32.")
        return value
        
class NotificationSerializer(serializers.ModelSerializer):
    class Meta:
        model = Notification
        fields = ['id', 'message', 'created_at', 'is_read']

class PlayerStatsSerializer(serializers.ModelSerializer):
    class Meta:
        model = PlayerStats
        fields = ['tournaments_won', 'tournaments_participated', 'highest_score', 'total_time_played']