const SingleGameView = {
    init: function(player1Name, player2Name) {
        this.canvas = document.getElementById('pongCanvas');
        this.ctx = this.canvas.getContext('2d');
        this.setupGame(player1Name, player2Name);

        
        this.setupGameEventListeners();

        
        this.canvas.style.display = 'block';

        // Inizia il loop di gioco
        this.gameActive = true;
        this.gameLoop();
    },

    setupGame: function(player1Name, player2Name) {
        this.ball = { x: 450, y: 350, radius: 10, dx: 3, dy: 3 };
        this.player1Paddle = { x: 20, y: 300, width: 10, height: 100, dy: 0 };
        this.player2Paddle = { x: 870, y: 300, width: 10, height: 100, dy: 0 };
        this.score = { player1: 0, player2: 0 };
        this.player1Name = player1Name || this.player1Name || 'Player 1';
        this.player2Name = player2Name || this.player2Name || 'Player 2';
        console.log('Player 1 Name:', this.player1Name);
        console.log('Player 2 Name:', this.player2Name);
        this.gameActive = true;
        this.keysPressed = {}; 
    },

    setupGameEventListeners: function() {
        document.addEventListener('keydown', this.handleKeyDown.bind(this));
        document.addEventListener('keyup', this.handleKeyUp.bind(this));
    },

    setupEventListeners: function() {
        const player2TypeSelect = document.getElementById('player2Type');
        if (player2TypeSelect) {
            player2TypeSelect.addEventListener('change', function() {
                const registeredUserFields = document.getElementById('registeredUserFields');
                registeredUserFields.style.display = this.value === 'registered' ? 'block' : 'none';
            });
        }
    },

    handleKeyDown: function(e) {
        this.keysPressed[e.key] = true;
    },

    handleKeyUp: function(e) {
        this.keysPressed[e.key] = false;
    },

    updatePaddles: function() {
        // Giocatore 1 (W e S)
        if (this.keysPressed['w'] || this.keysPressed['W']) {
            this.player1Paddle.dy = -6;
        } else if (this.keysPressed['s'] || this.keysPressed['S']) {
            this.player1Paddle.dy = 6;
        } else {
            this.player1Paddle.dy = 0;
        }

        // Giocatore 2 (Freccia su e Freccia giù)
        if (this.keysPressed['ArrowUp']) {
            this.player2Paddle.dy = -6;
        } else if (this.keysPressed['ArrowDown']) {
            this.player2Paddle.dy = 6;
        } else {
            this.player2Paddle.dy = 0;
        }

        // Aggiorna la posizione delle racchette
        this.player1Paddle.y += this.player1Paddle.dy;
        this.player2Paddle.y += this.player2Paddle.dy;

        // Limita le racchette all'interno del canvas
        this.player1Paddle.y = Math.max(0, Math.min(this.canvas.height - this.player1Paddle.height, this.player1Paddle.y));
        this.player2Paddle.y = Math.max(0, Math.min(this.canvas.height - this.player2Paddle.height, this.player2Paddle.y));
    },

    gameLoop: function() {
        if (!this.gameActive) return;

        this.update();
        this.draw();
        this.animationId = requestAnimationFrame(() => {
            this.gameLoop();
        });
    },

    update: function() {
        // Aggiorna le racchette
        this.updatePaddles();

        // Aggiorna la posizione della palla
        this.ball.x += this.ball.dx;
        this.ball.y += this.ball.dy;

        // Collisione con i bordi superiore e inferiore
        if (this.ball.y - this.ball.radius < 0 || this.ball.y + this.ball.radius > this.canvas.height) {
            this.ball.dy *= -1;
        }

        // Collisione con le racchette
        if (this.checkPaddleCollision(this.player1Paddle) || this.checkPaddleCollision(this.player2Paddle)) {
            this.ball.dx *= -1.05; // Aumenta leggermente la velocità ad ogni rimbalzo
        }

        // Segna punti
        if (this.ball.x < 0) {
            this.score.player2++;
            this.resetBall();
        } else if (this.ball.x > this.canvas.width) {
            this.score.player1++;
            this.resetBall();
        }

        // Controlla se la partita è finita
        if (this.score.player1 >= 11 || this.score.player2 >= 11) {
            this.endGame();
        }
    },

    checkPaddleCollision: function(paddle) {
        return (
            this.ball.x - this.ball.radius < paddle.x + paddle.width &&
            this.ball.x + this.ball.radius > paddle.x &&
            this.ball.y > paddle.y &&
            this.ball.y < paddle.y + paddle.height
        );
    },

    resetBall: function() {
        this.ball.x = this.canvas.width / 2;
        this.ball.y = this.canvas.height / 2;
        this.ball.dx = (Math.random() > 0.5 ? 1 : -1) * 3; // Velocità iniziale ridotta
        this.ball.dy = (Math.random() > 0.5 ? 1 : -1) * 3;
    },

    draw: function() {
        // Pulisci il canvas e imposta il colore di sfondo
        this.ctx.fillStyle = 'black';
        this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);

        // Disegna la linea centrale
        this.ctx.beginPath();
        this.ctx.setLineDash([10, 10]);
        this.ctx.moveTo(this.canvas.width / 2, 0);
        this.ctx.lineTo(this.canvas.width / 2, this.canvas.height);
        this.ctx.strokeStyle = 'white';
        this.ctx.stroke();
        this.ctx.setLineDash([]); // Reset del tratteggio

        // Disegna le racchette
        this.ctx.fillStyle = 'white';
        this.ctx.fillRect(this.player1Paddle.x, this.player1Paddle.y, this.player1Paddle.width, this.player1Paddle.height);
        this.ctx.fillRect(this.player2Paddle.x, this.player2Paddle.y, this.player2Paddle.width, this.player2Paddle.height);

        // Disegna la palla
        this.ctx.beginPath();
        this.ctx.arc(this.ball.x, this.ball.y, this.ball.radius, 0, Math.PI * 2);
        this.ctx.fill();

        // Disegna il punteggio e i nomi dei giocatori
        this.ctx.font = '20px Arial';
        this.ctx.fillText(`${this.player1Name}: ${this.score.player1}`, 50, 30);
        this.ctx.fillText(`${this.player2Name}: ${this.score.player2}`, this.canvas.width - 200, 30);
    },

    endGame: function() {
        this.gameActive = false;
        cancelAnimationFrame(this.animationId);

        // Determina il vincitore
        const winner = this.score.player1 > this.score.player2 ? this.player1Name : this.player2Name;

        // Mostra il risultato
        this.ctx.fillStyle = 'white';
        this.ctx.font = '30px Arial';
        this.ctx.fillText(`Game Over! ${winner} wins!`, this.canvas.width / 2 - 150, this.canvas.height / 2);

        // Salva il risultato e aggiorna le statistiche
        this.saveGameResult();
    },

    saveGameResult: function() {
        const gameData = {
            score_player1: this.score.player1,
            score_player2: this.score.player2,
            status: 'FINISHED'
        };
    
        fetch(`/api/single-game/${this.gameId}/`, {
            method: 'PUT',
            headers: {
                'Content-Type': 'application/json',
                'Authorization': `Bearer ${localStorage.getItem('access_token')}`
            },
            body: JSON.stringify(gameData)
        })
        .then(response => {
            if (!response.ok) {
                return response.json().then(data => {
                    throw new Error(data.error || JSON.stringify(data) || 'Errore sconosciuto');
                });
            }
            return response.json();
        })
        .then(data => {
            console.log('Game result saved:', data);
            alert('Partita terminata e risultato salvato!');
            // Reindirizza al profilo
            window.location.hash = '#profile';
        })
        .catch(error => {
            console.error('Error saving game result:', error.message);
            alert('Errore nel salvare il risultato della partita: ' + error.message);
        });
    },

    render: function() {
        const app = document.getElementById('app');
        app.innerHTML = `
            <div class="container mt-4">
                <h2>Single Game</h2>
                <div class="row">
                    <div class="col-md-6">
                        <form id="player2Form">
                            <div class="mb-3">
                                <label for="player2Name" class="form-label">Player 2 Name:</label>
                                <input type="text" class="form-control" id="player2Name" required>
                            </div>
                            <div class="mb-3">
                                <label for="player2Type" class="form-label">Player 2 Type:</label>
                                <select class="form-select" id="player2Type">
                                    <option value="alias">Temporary Alias</option>
                                    <option value="registered">Registered User</option>
                                </select>
                            </div>
                            <div id="registeredUserFields" style="display:none;">
                                <div class="mb-3">
                                    <label for="player2Username" class="form-label">Username:</label>
                                    <input type="text" class="form-control" id="player2Username">
                                </div>
                            </div>
                            <button type="submit" class="btn btn-primary">Start Game</button>
                        </form>
                    </div>
                    <div class="col-md-6">
                        <canvas id="pongCanvas" width="900" height="700" style="border:1px solid #000000; display: none;"></canvas>
                    </div>
                </div>
            </div>
        `;

        this.setupEventListeners();

        document.getElementById('player2Form').addEventListener('submit', (e) => {
            e.preventDefault();
            const player2Name = document.getElementById('player2Name').value;
            const player2Type = document.getElementById('player2Type').value;
            const player2Username = player2Type === 'registered' ? document.getElementById('player2Username').value : player2Name;

            if (!player2Username) {
                alert('Per favore, inserisci un nome per il giocatore 2.');
                return;
            }

            fetch('/api/single-game/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                },
                body: JSON.stringify({
                    player2_type: player2Type,
                    player2_name: player2Username
                })
            })
            .then(response => {
                if (!response.ok) {
                    return response.json().then(data => {
                        throw new Error(data.error || 'Errore sconosciuto');
                    });
                }
                return response.json();
            })
            .then(data => {
                console.log('Game created:', data);
                this.gameId = data.id;
            
                // Ottenere il nome dell'utente corrente
                const currentUser = this.getCurrentUsername();
                console.log('Utente corrente:', currentUser);
            
                // Nascondi il form e mostra il canvas
                document.getElementById('player2Form').style.display = 'none';
                document.getElementById('pongCanvas').style.display = 'block';
            
                // Inizializza il gioco
                this.init(currentUser || 'Player 1', player2Username);
            })
            .catch(error => {
                console.error('Error creating game:', error.message);
                alert('Errore nella creazione del gioco: ' + error.message);
            });
        });
    },

    getCurrentUsername: function() {
        const token = localStorage.getItem('access_token');
        if (!token) {
            return null;
        }
    
        const payloadBase64Url = token.split('.')[1];
        if (!payloadBase64Url) {
            return null;
        }
    
        // Converti da Base64URL a Base64 e aggiungi padding
        let payloadBase64 = payloadBase64Url.replace(/-/g, '+').replace(/_/g, '/');
        while (payloadBase64.length % 4) {
            payloadBase64 += '=';
        }
    
        try {
            const payloadJson = atob(payloadBase64);
            const payload = JSON.parse(payloadJson);
            const username = payload.username || payload.email || payload.user_id || null;
            console.log('Nome utente ottenuto dal token:', username);
            return username;
        } catch (e) {
            console.error('Errore nella decodifica del token JWT:', e);
            return null;
        }
    },
};