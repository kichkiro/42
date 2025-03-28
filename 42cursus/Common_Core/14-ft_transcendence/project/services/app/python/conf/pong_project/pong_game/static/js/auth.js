const auth = {
    isAuthenticated: function() {
        return localStorage.getItem('access_token') !== null;
    },

    login: async function(username, password) {
        try {
            const response = await fetch('/api/accounts/token/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ username, password }),
            });
    
            const data = await response.json();
    
            if (response.status === 202) {
                if (data.requires_2fa) {
                    localStorage.setItem('temp_user_id', data.user_id); // Memorizza temporaneamente l'user_id
                    return { requires_2fa: true, user_id: data.user_id };
                } else if (data.requires_2fa_setup) {
                    this.setToken(data.access);
                    localStorage.setItem('refresh_token', data.refresh);
                    return { requires_2fa_setup: true };
                }
            } else if (response.ok) {
                this.setToken(data.access);
                return { success: true };
            } else {
                return { error: data.error || 'Login failed. Please check your credentials.' };
            }
        } catch (error) {
            console.error('Error:', error);
            return { error: 'An error occurred. Please try again later.' };
        }
    },

    verify2FA: async function(username, token) {
        console.log(`Attempting 2FA verification for user ${username} with token ${token}`);
        if (!username || !token) {
            console.error('username or token is missing');
            return { error: 'Username or token is missing' };
        }
        try {
            const response = await fetch('/api/accounts/2fa/verify/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ username: username, token: token }),
            });
    
            console.log('Response status:', response.status);
    
            const data = await response.json();
            console.log('Response data:', data);
    
            if (!response.ok) {
                throw new Error(data.error || 'Verification failed');
            }
    
            this.setToken(data.access);
            return { success: true };
        } catch (error) {
            console.error('2FA verification failed:', error);
            return { error: error.message || 'Invalid 2FA code.' };
        }
    },

    setToken: function(token) {
        localStorage.setItem('access_token', token);
        this.updateNavbar();
        document.dispatchEvent(new Event('authChanged'));
    },

    logout: function() {
        localStorage.removeItem('access_token');
        this.updateNavbar();
        window.location.hash = '#home';
        document.dispatchEvent(new Event('authChanged'));
    },
    
    updateNavbar: function() {
        const loginLink = document.getElementById('login-link');
        const registerLink = document.getElementById('register-link');
        const logoutLink = document.getElementById('logout-link');
        const profileLink = document.getElementById('profile-link');
        const gameLink = document.getElementById('game-link');
        const tournamentLink = document.getElementById('tournament-link');
        const singleGameLink = document.getElementById('singlegame-link'); 

        if (this.isAuthenticated()) {
            loginLink.style.display = 'none';
            registerLink.style.display = 'none';
            logoutLink.style.display = 'block';
            profileLink.style.display = 'block';
            gameLink.style.display = 'none';
            tournamentLink.style.display = 'block';
            singleGameLink.style.display = 'block'; 
        } else {
            loginLink.style.display = 'block';
            registerLink.style.display = 'block';
            logoutLink.style.display = 'none';
            profileLink.style.display = 'none';
            gameLink.style.display = 'none';
            tournamentLink.style.display = 'none';
            singleGameLink.style.display = 'none';  
        }
    },

    getCurrentUser: function() {
        const token = localStorage.getItem('access_token');
        if (!token) return null;

        // Decodifica il payload del token JWT
        const base64Url = token.split('.')[1];
        const base64 = base64Url.replace(/-/g, '+').replace(/_/g, '/');
        const jsonPayload = decodeURIComponent(atob(base64).split('').map(function(c) {
            return '%' + ('00' + c.charCodeAt(0).toString(16)).slice(-2);
        }).join(''));

        const payload = JSON.parse(jsonPayload);
        return {
            id: payload.user_id,
            username: payload.username
        };
    },

    init: function() {
        this.updateNavbar();
        document.getElementById('logout-link').addEventListener('click', (e) => {
            e.preventDefault();
            this.logout();
        });
    }
};