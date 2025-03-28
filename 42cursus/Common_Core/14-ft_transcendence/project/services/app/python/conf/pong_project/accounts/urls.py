from django.urls import path, include
from .views import UserDetailView, RegisterView, UserStatsView, MatchHistoryView, FollowUserView, UnfollowUserView, TwoFactorSetupView, CustomTokenObtainPairView, Verify2FAView
from two_factor.urls import urlpatterns as tf_urls

urlpatterns = [
    path('me/', UserDetailView.as_view(), name='user-detail'),
    path('register/', RegisterView.as_view(), name='register'),
    path('stats/', UserStatsView.as_view(), name='user-stats'),
    path('profile/', UserDetailView.as_view(), name='user-profile'),
    path('matches/', MatchHistoryView.as_view(), name='user-match-history'),
    path('follow/<int:pk>/', FollowUserView.as_view(), name='follow-user'),
    path('unfollow/<int:pk>/', UnfollowUserView.as_view(), name='unfollow-user'),
    
    # Nuovi percorsi per 2FA
    path('token/', CustomTokenObtainPairView.as_view(), name='token_obtain_pair'),
    path('2fa/verify/', Verify2FAView.as_view(), name='2fa-verify'),
    path('2fa/setup/', TwoFactorSetupView.as_view(), name='2fa-setup'),
    
    
    # Includi i percorsi 2FA standard
    path('', include(tf_urls)),
]