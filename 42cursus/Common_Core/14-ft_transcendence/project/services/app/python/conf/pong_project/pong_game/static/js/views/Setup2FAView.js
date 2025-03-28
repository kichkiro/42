const Setup2FAView = {
    render: async function() {
        const app = document.getElementById('app');
        app.innerHTML = `
            <h2>Setup Two-Factor Authentication (2FA)</h2>
            <ol>
                <li>Install Google Authenticator on your mobile device:
                    <ul>
                        <li><a href="https://play.google.com/store/apps/details?id=com.google.android.apps.authenticator2" target="_blank">Android</a></li>
                        <li><a href="https://apps.apple.com/us/app/google-authenticator/id388497605" target="_blank">iOS</a></li>
                    </ul>
                </li>
                <li>Open Google Authenticator and tap the '+' icon</li>
                <li>Choose 'Scan a QR code' and scan the image below:</li>
            </ol>
            <div id="qr-code"></div>
            <p>After scanning, you'll see a 6-digit code in the app. This code changes every 30 seconds.</p>
            <form id="setup-2fa-form">
                <input type="text" id="2fa-setup-code" placeholder="Enter the 6-digit code" required>
                <button type="submit">Confirm</button>
            </form>
            <p id="setup-message"></p>
            <p><strong>Important:</strong> Keep the Google Authenticator app installed. You'll need it to generate a new 6-digit code every time you log in.</p>
        `;
        
        await this.loadQRCode();
        this.attachEventListeners();
    },

    loadQRCode: async function() {
        try {
            const response = await fetch('/api/accounts/2fa/setup/', {
                method: 'GET',
                headers: {
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                }
            });
            const data = await response.json();
            if (response.ok) {
                document.getElementById('qr-code').innerHTML = `<img src="data:image/svg+xml;base64,${data.qr_code}" alt="2FA QR Code">`;
            } else {
                document.getElementById('setup-message').textContent = 'Failed to load QR code.';
            }
        } catch (error) {
            console.error('Error:', error);
            document.getElementById('setup-message').textContent = 'An error occurred while loading the QR code.';
        }
    },

    attachEventListeners: function() {
        const form = document.getElementById('setup-2fa-form');
        form.addEventListener('submit', this.handleSetup2FA);
    },

    handleSetup2FA: async function(e) {
        e.preventDefault();
        const code = document.getElementById('2fa-setup-code').value;
        const messageElement = document.getElementById('setup-message');

        try {
            const response = await fetch('/api/accounts/2fa/setup/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                },
                body: JSON.stringify({ token: code })
            });
            const data = await response.json();
            if (response.ok) {
                messageElement.textContent = '2FA setup successful!';
                setTimeout(() => {
                    window.location.hash = '#home';
                }, 1000);
            } else {
                messageElement.textContent = data.message || 'Failed to setup 2FA.';
            }
        } catch (error) {
            console.error('Error:', error);
            messageElement.textContent = 'An error occurred. Please try again.';
        }
    }
};