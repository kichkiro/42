from django.urls import path
from . import views
from .views import (
    GameListCreateView, GameDetailView, StartGameView, UpdateScoreView,
    MatchmakingView, CancelMatchmakingView, SingleGameView,
    LobbyListCreateView, LobbyDetailView, JoinLobbyView,
    StartMatchView, TournamentMatchDetailView, MyTokenObtainPairView,
    CreateTournamentView, TournamentAPIView, TournamentListView, TournamentDetailView,
    JoinTournamentAPIView, SubmitMatchResultView, TournamentStatusView,
    UserDashboardView, ReadNotificationView
)

urlpatterns = [
    path('', views.index, name='index'),
    path('games/', GameListCreateView.as_view(), name='game-list-create'),
    path('games/<int:pk>/', GameDetailView.as_view(), name='game-detail'),
    path('api/single-game/', SingleGameView.as_view(), name='single_game'),
    path('api/single-game/<int:pk>/', SingleGameView.as_view(), name='update_single_game'),
    path('api/user/stats/', views.UserStatsView.as_view(), name='user-stats'),
    path('api/friends/', views.FriendListView.as_view(), name='friend-list'),
    path('api/friends/add/', views.AddFriendView.as_view(), name='add-friend'),
    path('api/token/', MyTokenObtainPairView.as_view(), name='token_obtain_pair'),
    path('games/start/', StartGameView.as_view(), name='start-game'),
    path('games/<int:pk>/update-score/', UpdateScoreView.as_view(), name='update-score'),
    path('matchmaking/', MatchmakingView.as_view(), name='matchmaking'),
    path('matchmaking/cancel/', CancelMatchmakingView.as_view(), name='cancel-matchmaking'),
    path('lobbies/', LobbyListCreateView.as_view(), name='lobby-list-create'),
    path('lobbies/<int:pk>/', LobbyDetailView.as_view(), name='lobby-detail'),
    path('lobbies/<int:pk>/join/', JoinLobbyView.as_view(), name='join-lobby'),
    path('tournaments/create/', CreateTournamentView.as_view(), name='create-tournament'),
    path('api/tournament/', TournamentAPIView.as_view(), name='tournament_api'),
    path('api/tournament/<int:pk>/join/', JoinTournamentAPIView.as_view(), name='join-tournament'),
    path('tournaments/', TournamentListView.as_view(), name='tournament-list'),
    path('api/tournament/<int:pk>/', TournamentDetailView.as_view(), name='tournament-detail'),
    path('api/tournament/<int:tournament_id>/match/<int:match_id>/start/', StartMatchView.as_view(), name='start-match'),
    path('api/tournament/<int:tournament_id>/match/<int:match_id>/', TournamentMatchDetailView.as_view(), name='tournament-match-detail'),
    path('api/tournament/<int:tournament_id>/match/<int:match_id>/submit-score/', SubmitMatchResultView.as_view(), name='submit-score'),
    path('tournaments/<int:pk>/status/', TournamentStatusView.as_view(), name='tournament-status'),
    path('dashboard/', UserDashboardView.as_view(), name='user-dashboard'),
    path('notifications/<int:pk>/read/', ReadNotificationView.as_view(), name='read-notification'),
    path('chat/<str:room_name>/', views.chat_room, name='chat_room'),
]