import logging
from rest_framework import serializers
from .models import CustomUser, Match

logger = logging.getLogger(__name__)

class UserSerializer(serializers.ModelSerializer):
    avatar = serializers.ImageField(required=False)
    confirm_password = serializers.CharField(write_only=True, required=False)
    password = serializers.CharField(write_only=True, required=False)
    followers_count = serializers.SerializerMethodField()
    following_count = serializers.SerializerMethodField()
    is_online = serializers.BooleanField(read_only=True)
    match_history = serializers.SerializerMethodField()

    class Meta:
        model = CustomUser
        fields = ['id', 'username', 'email', 'password', 'confirm_password', 'avatar', 'games_played', 'games_won_count', 'total_score', 'win_rate', 'followers_count', 'following_count', 'is_online', 'match_history']
        read_only_fields = ['id', 'games_played', 'games_won_count', 'total_score', 'win_rate', 'match_history']
        extra_kwargs = {'password': {'write_only': True}}

    def get_followers_count(self, obj):
        return obj.followers.count()
    
    def get_match_history(self, obj):
        from pong_game.serializers import GameSerializer  # Importa qui per evitare import circolari
        games = obj.match_history
        serializer = GameSerializer(games, many=True)
        return serializer.data

    def get_following_count(self, obj):
        return obj.following.count()

    def validate(self, data):
        if 'password' in data and 'confirm_password' in data:
            if data['password'] != data['confirm_password']:
                raise serializers.ValidationError("Le password non corrispondono.")
        if 'email' in data and data['email'] == '':
            data.pop('email')
        return data

    def create(self, validated_data):
        validated_data.pop('confirm_password', None)
        user = CustomUser.objects.create_user(
            username=validated_data['username'],
            email=validated_data.get('email', ''),
            password=validated_data['password']
        )
        return user

    def update(self, instance, validated_data):
        avatar = validated_data.pop('avatar', None)
        if avatar:
            instance.avatar = avatar
        password = validated_data.pop('password', None)
        confirm_password = validated_data.pop('confirm_password', None)
        
        if password:
            if confirm_password and password != confirm_password:
                raise serializers.ValidationError("Le password non corrispondono.")
            instance.set_password(password)
        
        for attr, value in validated_data.items():
            setattr(instance, attr, value)
        
        instance.save()
        return instance
    
class MatchSerializer(serializers.ModelSerializer):
    player1 = serializers.StringRelatedField()
    player2 = serializers.StringRelatedField()
    winner = serializers.StringRelatedField()

    class Meta:
        model = Match
        fields = ['id', 'player1', 'player2', 'player1_score', 'player2_score', 'date_played', 'winner']