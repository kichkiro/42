from django.utils import timezone
from django.utils.deprecation import MiddlewareMixin

class UpdateLastActivityMiddleware:
    def __init__(self, get_response):
        self.get_response = get_response

    def __call__(self, request):
        if request.user.is_authenticated:
            request.user.last_activity = timezone.now()
            request.user.save(update_fields=['last_activity'])
        return self.get_response(request)
    
class DisableCSRFMiddleware(MiddlewareMixin):
    def process_request(self, request):
        setattr(request, '_dont_enforce_csrf_checks', True)