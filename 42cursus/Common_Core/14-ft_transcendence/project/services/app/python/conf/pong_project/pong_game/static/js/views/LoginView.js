const LoginView = {
    render: function() {
        const app = document.getElementById('app');
        app.innerHTML = `
            <h2>Login</h2>
            <form id="login-form">
                <input type="text" id="username" placeholder="Username" required>
                <input type="password" id="password" placeholder="Password" required>
                <button type="submit">Login</button>
            </form>
            <p id="login-message"></p>
        `;
        this.attachEventListeners();
    },

    attachEventListeners: function() {
        const form = document.getElementById('login-form');
        form.addEventListener('submit', this.handleLogin.bind(this));
    },

    handleLogin: async function(e) {
        e.preventDefault();
        const username = document.getElementById('username').value;
        const password = document.getElementById('password').value;
        const messageElement = document.getElementById('login-message');
    
        const result = await auth.login(username, password);
    
        if (result.success) {
            messageElement.textContent = 'Login successful!';
            setTimeout(() => {
                window.location.hash = '#home';
            }, 1000);
        } else if (result.requires_2fa) {
            // Salva l'username per l'uso successivo nella verifica 2FA
            this.username = username;
            this.show2FAForm();
        } else if (result.requires_2fa_setup) {
            messageElement.textContent = 'Please set up 2FA for your account.';
            setTimeout(() => {
                window.location.hash = '#setup2fa';
            }, 1000);
        } else {
            messageElement.textContent = result.error;
        }
    },

    show2FAForm: function() {
        const app = document.getElementById('app');
        app.innerHTML = `
            <h2>Enter 2FA Code</h2>
            <p>Open Google Authenticator on your mobile device and enter the 6-digit code for this account:</p>
            <form id="2fa-form">
                <input type="text" id="2fa-code" placeholder="Enter 6-digit code" required>
                <button type="submit">Verify</button>
            </form>
            <p id="2fa-message"></p>
        `;
        const form = document.getElementById('2fa-form');
        form.addEventListener('submit', this.handle2FAVerification.bind(this));
    },

    handle2FAVerification: async function(event) {
        event.preventDefault();
        const token = document.getElementById('2fa-code').value;
        const username = this.username; // Usa l'username salvato
        console.log(`Verifying 2FA for user ${username} with token ${token}`);
        const result = await auth.verify2FA(username, token);
        const messageElement = document.getElementById('2fa-message');
        if (result.success) {
            messageElement.textContent = '2FA verification successful!';
            setTimeout(() => {
                window.location.hash = '#home';
            }, 1000);
        } else {
            messageElement.textContent = result.error || 'Verification failed';
        }
    },
};