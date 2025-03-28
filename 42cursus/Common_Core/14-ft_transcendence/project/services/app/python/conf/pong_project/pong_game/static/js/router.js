const router = {
    routes: {
        '': HomeView,
        'home': HomeView,
        'login': LoginView,
        'register': RegisterView,
        'game': GameView,
        'profile': ProfileView,
        'tournament': TournamentView,
        'singlegame': SingleGameView,
        'setup2fa': Setup2FAView 
    },

    init: function() {
        this.navigate(this.getFragment());
        window.addEventListener('hashchange', () => {
            this.navigate(this.getFragment());
        });
    },

    getFragment: function() {
        return location.hash.slice(1).toLowerCase() || 'home';
    },

    navigate: function(route) {
        console.log('Navigating to:', route);

        if (!auth.isAuthenticated() && !['', 'home', 'login', 'register', 'setup2fa'].includes(route)) {
            console.log('User not authenticated. Redirecting to login.');
            window.location.hash = '#login';
            return;
        }

        if (route.startsWith('tournament/')) {
            const tournamentId = route.split('/')[1];
            TournamentView.render(tournamentId);
        } else if (route.startsWith('game/')) {
            const [, tournamentId, gameId] = route.split('/');
            GameView.render(tournamentId, gameId);
        } else if (route === 'singlegame') {
            SingleGameView.render();
        } else {
            const view = this.routes[route];
            if (view) {
                view.render();
            } else {
                console.error('No route found for', route);
                HomeView.render();  // Fallback to home view if route not found
            }
        }
    }
};