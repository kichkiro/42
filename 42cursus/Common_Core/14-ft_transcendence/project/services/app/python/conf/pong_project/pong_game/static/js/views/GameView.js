const GameView = {
    canvas: null,
    ctx: null,
    gameLoop: null,
    ball: { x: 400, y: 200, radius: 10, dx: 3.5, dy: 3.5 }, // Increased ball speed
    paddle1: { x: 10, y: 175, width: 10, height: 50, dy: 4 }, // Increased paddle speed
    paddle2: { x: 780, y: 175, width: 10, height: 50, dy: 4 }, // Increased paddle speed
    score1: 0,
    score2: 0,
    keys: {},
    isTournamentGame: false,
    tournamentId: null,
    player1Name: 'Player 1',
    player2Name: 'Player 2',
    gameId: null,

    render: async function(tournamentId = null, matchId = null) {
        console.log("Rendering game view with tournamentId:", tournamentId, "matchId:", matchId);
        this.tournamentId = tournamentId;
        this.gameId = matchId;
        this.isTournamentGame = Boolean(tournamentId && matchId);
        console.log("isTournamentGame set to:", this.isTournamentGame);
        const app = document.getElementById('app');
    
        if (this.isTournamentGame) {
            try {
                const matchData = await this.getMatchData(tournamentId, matchId);
                this.player1Name = matchData.player1_alias;
                this.player2Name = matchData.player2_alias;
                console.log("Match data loaded:", matchData);
            } catch (error) {
                console.error('Error fetching match data:', error);
                app.innerHTML = '<p>Error loading match data.</p>';
                return;
            }
        } else {
            this.player1Name = 'Player 1';
            this.player2Name = 'Player 2';
        }
    
        app.innerHTML = `
            <div class="container mt-5">
                <h2>${this.isTournamentGame ? 'Tournament' : ''} Pong Game</h2>
                <canvas id="pongCanvas" width="800" height="400" style="border:1px solid #000000;"></canvas>
                <div class="mt-3">
                    <button id="startGame" class="btn btn-primary">Start Game</button>
                </div>
                <div class="mt-3">
                    <p>${this.player1Name} Controls: W (up), S (down)</p>
                    <p>${this.player2Name} Controls: Arrow Up, Arrow Down</p>
                </div>
            </div>
        `;
    
        this.initGame(this.tournamentId, this.gameId, this.player1Name, this.player2Name);
    },

    initGame: function(tournamentId, gameId, player1Alias, player2Alias) {
        this.canvas = document.getElementById('pongCanvas');
        this.ctx = this.canvas.getContext('2d');
        
        this.isTournamentGame = !!tournamentId;
        this.tournamentId = tournamentId;
        this.gameId = gameId;
        
        // Aggiorna i nomi dei giocatori solo se sono forniti
        if (player1Alias) this.player1Name = player1Alias;
        if (player2Alias) this.player2Name = player2Alias;
        
        console.log("Game initialized:", {
            isTournamentGame: this.isTournamentGame,
            tournamentId: this.tournamentId,
            gameId: this.gameId,
            player1Name: this.player1Name,
            player2Name: this.player2Name
        });
    
        document.getElementById('startGame').addEventListener('click', () => this.startGame());
        document.addEventListener('keydown', (e) => this.keys[e.code] = true);
        document.addEventListener('keyup', (e) => this.keys[e.code] = false);
    },

    startGame: async function() {
        console.log("Starting game, isTournamentGame before:", this.isTournamentGame);
        this.score1 = 0;
        this.score2 = 0;
        this.resetBall();
        if (this.isTournamentGame) {
            await this.startTournamentGame();
        }
        if (this.gameLoop) clearInterval(this.gameLoop);
        this.gameLoop = setInterval(() => this.update(), 1000 / 45); // Increased to 45 FPS for smoother gameplay
        console.log("Game started, isTournamentGame after:", this.isTournamentGame);
    },

    startTournamentGame: async function() {
        console.log("Starting tournament game", this.tournamentId, this.gameId);
        try {
            const response = await fetch(`/api/tournament/${this.tournamentId}/match/${this.gameId}/start/`, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                }
            });
            if (response.ok) {
                const data = await response.json();
                console.log("Tournament game started successfully", data);
                // Aggiorna i nomi dei giocatori se necessario
                this.player1Name = data.player1_alias;
                this.player2Name = data.player2_alias;
            } else {
                console.error('Failed to start tournament game');
            }
        } catch (error) {
            console.error('Error starting tournament game:', error);
        }
    },

    resetBall: function() {
        this.ball.x = this.canvas.width / 2;
        this.ball.y = this.canvas.height / 2;
        this.ball.dx = 3.5 * (Math.random() > 0.5 ? 1 : -1); // Increased initial ball speed
        this.ball.dy = 3.5 * (Math.random() > 0.5 ? 1 : -1); // Increased initial ball speed
    },

    update: function() {
        this.movePaddles();
        this.moveBall();
        this.checkCollisions();
        this.draw();
    },

    movePaddles: function() {
        const paddleSpeed = 4; // Increased paddle speed
        // Player 1 controls
        if (this.keys['KeyW'] && this.paddle1.y > 0) this.paddle1.y -= paddleSpeed;
        if (this.keys['KeyS'] && this.paddle1.y < this.canvas.height - this.paddle1.height) this.paddle1.y += paddleSpeed;
        
        // Player 2 controls
        if (this.keys['ArrowUp'] && this.paddle2.y > 0) this.paddle2.y -= paddleSpeed;
        if (this.keys['ArrowDown'] && this.paddle2.y < this.canvas.height - this.paddle2.height) this.paddle2.y += paddleSpeed;
    },

    moveBall: function() {
        this.ball.x += this.ball.dx;
        this.ball.y += this.ball.dy;
    },

    checkCollisions: function() {
        // Collisions with top and bottom edges
        if (this.ball.y - this.ball.radius < 0 || this.ball.y + this.ball.radius > this.canvas.height) {
            this.ball.dy *= -1;
        }

        // Collisions with paddles
        if (
            (this.ball.x - this.ball.radius < this.paddle1.x + this.paddle1.width && this.ball.y > this.paddle1.y && this.ball.y < this.paddle1.y + this.paddle1.height) ||
            (this.ball.x + this.ball.radius > this.paddle2.x && this.ball.y > this.paddle2.y && this.ball.y < this.paddle2.y + this.paddle2.height)
        ) {
            this.ball.dx *= -1.07; // Slightly increase speed on paddle hit
        }

        // Punteggio
        if (this.ball.x < 0) {
            this.score2++;
            this.resetBall();
        } else if (this.ball.x > this.canvas.width) {
            this.score1++;
            this.resetBall();
        }

        // Fine del gioco
        if (this.score1 >= 2 || this.score2 >= 2) {
            const currentIsTournamentGame = this.isTournamentGame;
            this.endGame();  // Chiama direttamente endGame invece di usare alert
            this.isTournamentGame = currentIsTournamentGame;
        }
    },

    draw: function() {
        // Pulisci il canvas
        this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);

        // Disegna lo sfondo
        this.ctx.fillStyle = 'black';
        this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);

        // Disegna la linea centrale
        this.ctx.strokeStyle = 'white';
        this.ctx.beginPath();
        this.ctx.moveTo(this.canvas.width / 2, 0);
        this.ctx.lineTo(this.canvas.width / 2, this.canvas.height);
        this.ctx.stroke();

        // Disegna le racchette
        this.ctx.fillStyle = 'white';
        this.ctx.fillRect(this.paddle1.x, this.paddle1.y, this.paddle1.width, this.paddle1.height);
        this.ctx.fillRect(this.paddle2.x, this.paddle2.y, this.paddle2.width, this.paddle2.height);

        // Disegna la palla
        this.ctx.beginPath();
        this.ctx.arc(this.ball.x, this.ball.y, this.ball.radius, 0, Math.PI * 2);
        this.ctx.fill();

        // Disegna i punteggi e i nomi degli alias
        this.ctx.font = '20px Arial';
        this.ctx.fillStyle = 'white';
        this.ctx.textAlign = 'center';
        
        // Nome e punteggio del giocatore 1
        this.ctx.fillText(`${this.player1Name}: ${this.score1}`, this.canvas.width / 4, 30);
        
        // Nome e punteggio del giocatore 2
        this.ctx.fillText(`${this.player2Name}: ${this.score2}`, 3 * this.canvas.width / 4, 30);
    },

    getMatchData: async function(tournamentId, matchId) {
        const response = await fetch(`/api/tournament/${tournamentId}/match/${matchId}/`, {
            headers: {
                'Authorization': `Bearer ${localStorage.getItem('access_token')}`
            }
        });
        if (!response.ok) {
            throw new Error('Failed to fetch match data');
        }
        return await response.json();
    },

    endGame: function() {
        console.log("endGame function called, isTournamentGame:", this.isTournamentGame);
        clearInterval(this.gameLoop);
        this.gameLoop = null;
        const winner = this.score1 > this.score2 ? this.player1Name : this.player2Name;
        
        alert(`${winner} ha vinto!`);;
    
        // Aggiungi un messaggio di reindirizzamento
        alert('Reindirizzamento tra 3 secondi...');
    
        // Reindirizza dopo 3 secondi
        setTimeout(() => {
            if (this.isTournamentGame) {
                console.log("Calling submitTournamentResult");
                this.submitTournamentResult();
            } else {
                console.log("Redirecting to tournament list");
                window.location.hash = '#tournament';
            }
        }, 3000);
    },

    submitTournamentResult: async function() {
        console.log("submitTournamentResult called with tournamentId:", this.tournamentId, "gameId:", this.gameId);
        try {
            const response = await fetch(`/api/tournament/${this.tournamentId}/match/${this.gameId}/submit-score/`, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                },
                body: JSON.stringify({
                    score_player1: this.score1,
                    score_player2: this.score2
                })
            });
    
            if (response.ok) {
                const data = await response.json();
                console.log('Tournament result submitted successfully', data);
                window.location.hash = `#tournament/${this.tournamentId}`;
            } else {
                console.error('Failed to submit tournament result', await response.text());
                window.location.hash = `#tournament/${this.tournamentId}`;
            }
        } catch (error) {
            console.error('Error submitting tournament result:', error);
            window.location.hash = `#tournament/${this.tournamentId}`;
        }
    },
};