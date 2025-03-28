const RegisterView = {
    render: function() {
        const app = document.getElementById('app');
        app.innerHTML = `
            <h2>Register</h2>
            <form id="register-form">
                <input type="text" id="username" placeholder="Username" required>
                <input type="email" id="email" placeholder="Email" required>
                <input type="password" id="password" placeholder="Password" required>
                <input type="password" id="confirm-password" placeholder="Confirm Password" required>
                <button type="submit">Register</button>
            </form>
            <p id="register-message"></p>
        `;
        this.attachEventListeners();
    },

    attachEventListeners: function() {
        const form = document.getElementById('register-form');
        form.addEventListener('submit', this.handleRegister);
    },

    handleRegister: async function(e) {
        e.preventDefault();
        const username = document.getElementById('username').value;
        const email = document.getElementById('email').value;
        const password = document.getElementById('password').value;
        const confirmPassword = document.getElementById('confirm-password').value;
        const messageElement = document.getElementById('register-message');
    
        // Controllo lato client
        if (password !== confirmPassword) {
            messageElement.textContent = 'Le password non corrispondono.';
            return;
        }
    
        try {
            const response = await fetch('/api/accounts/register/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'X-CSRFToken': getCookie('csrftoken')
                },
                credentials: 'include',
                body: JSON.stringify({ username, email, password, confirm_password: confirmPassword }),
            });
    
            console.log('Response status:', response.status);
            const data = await response.json();
            console.log('Response data:', data);
    
            if (response.ok) {
                messageElement.textContent = 'Registrazione avvenuta con successo! Effettua il login.';
                setTimeout(() => {
                    window.location.hash = '#login';
                }, 2000);
            } else {
                messageElement.textContent = `Registrazione fallita: ${data.message || JSON.stringify(data)}`;
            }
        } catch (error) {
            console.error('Error:', error);
            messageElement.textContent = 'Si è verificato un errore. Riprova più tardi.';
        }
    }
};

// Funzione per ottenere il valore del cookie CSRF
function getCookie(name) {
    let cookieValue = null;
    if (document.cookie && document.cookie !== '') {
        const cookies = document.cookie.split(';');
        for (let i = 0; i < cookies.length; i++) {
            const cookie = cookies[i].trim();
            if (cookie.substring(0, name.length + 1) === (name + '=')) {
                cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
                break;
            }
        }
    }
    return cookieValue;
}