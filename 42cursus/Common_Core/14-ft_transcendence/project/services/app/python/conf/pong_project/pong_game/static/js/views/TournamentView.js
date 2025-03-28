const TournamentView = {
    render: async function(tournamentId) {
        const app = document.getElementById('app');
        
        if (tournamentId) {
            // Visualizza i dettagli di un torneo specifico
            await this.renderTournamentDetails(tournamentId);
        } else {
            // Visualizza la lista di tutti i tornei
            await this.renderTournamentList();
        }
    },

    renderTournamentList: async function() {
        const app = document.getElementById('app');
        const tournaments = await this.getTournaments();

        let html = '<h2>Your Tournaments</h2>';

        if (tournaments.length === 0) {
            html += '<p>You have not created any tournaments yet.</p>';
        } else {
            html += '<ul>';
            tournaments.forEach(tournament => {
                html += `
                    <li>
                        <a href="#tournament/${tournament.id}">${tournament.name}</a> - ${tournament.status}
                        (${tournament.participants.length}/${tournament.max_participants} participants)
                        ${tournament.status === 'REGISTRATION' ?
                            `<button onclick="TournamentView.joinTournament(${tournament.id})">Add Participant</button>` :
                            ''
                        }
                    </li>
                `;
            });
            html += '</ul>';
        }

        html += '<button onclick="TournamentView.createTournament()">Create New Tournament</button>';
        app.innerHTML = html;
    },

    renderTournamentDetails: async function(tournamentId) {
        const app = document.getElementById('app');
        try {
            const tournament = await this.getTournament(tournamentId);
            
            let html = `
                <h2>${tournament.name}</h2>
                <p>Status: ${tournament.status}</p>
                <p>Current Round: ${tournament.current_round}</p>
                <p>Participants: ${tournament.participants.length}/${tournament.max_participants}</p>
                
                <h3>Participants:</h3>
                <ul>
                    ${tournament.participants.map(p => `<li>${p.alias}</li>`).join('')}
                </ul>
            `;
    
            if (tournament.status === 'REGISTRATION' && tournament.participants.length < tournament.max_participants) {
                html += `<button id="addParticipantBtn">Add Participant</button>`;
            }
    
            if (tournament.status !== 'REGISTRATION') {
                html += `
                    <button id="showResultsBtn">Show Tournament Results</button>
                    <button id="showBracketBtn">Show Tournament Bracket</button>
                `;
    
                html += `
                    <h3>Current Round Matches:</h3>
                    <ul>
                        ${tournament.matches
                            .filter(m => m.round === tournament.current_round)
                            .map(m => `
                                <li>
                                    Round ${m.round}: ${m.player1_alias} vs ${m.player2_alias}
                                    ${m.winner_alias ? `(Winner: ${m.winner_alias})` : ''}
                                    ${!m.winner_alias && tournament.status === 'IN_PROGRESS' ? 
                                        `<button class="playMatchBtn" data-match-id="${m.id}">Play Match</button>` : 
                                        ''}
                                </li>
                            `).join('')}
                    </ul>
                `;
            }
    
            if (tournament.status === 'FINISHED') {
                html += `<h3>Tournament Winner: ${tournament.matches[tournament.matches.length - 1].winner_alias}</h3>`;
            }
    
            html += '<br><a href="#tournament">Back to Tournament List</a>';
    
            app.innerHTML = html;
    
            // Add event listeners
            if (tournament.status === 'REGISTRATION' && tournament.participants.length < tournament.max_participants) {
                document.getElementById('addParticipantBtn').addEventListener('click', () => {
                    this.joinTournament(tournamentId);
                });
            }
    
            if (tournament.status !== 'REGISTRATION') {
                document.getElementById('showResultsBtn').addEventListener('click', () => {
                    this.showTournamentResults(tournamentId);
                });
    
                document.getElementById('showBracketBtn').addEventListener('click', () => {
                    console.log("Show Bracket button clicked");
                    this.showBracket(tournamentId);
                });
    
                document.querySelectorAll('.playMatchBtn').forEach(btn => {
                    btn.addEventListener('click', () => {
                        this.startMatch(tournamentId, btn.dataset.matchId);
                    });
                });
            }
        } catch (error) {
            console.error('Error rendering tournament details:', error);
            app.innerHTML = '<p>Error loading tournament details.</p>';
        }
    },

    getTournaments: async function() {
        try {
            const response = await fetch('/api/tournament/', {
                headers: {
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                }
            });
            if (response.ok) {
                return await response.json();
            }
            console.error('Failed to fetch tournaments:', response.statusText);
            return [];
        } catch (error) {
            console.error('Error fetching tournaments:', error);
            return [];
        }
    },

    getTournament: async function(tournamentId) {
        const response = await fetch(`/api/tournament/${tournamentId}/`, {
            headers: {
                'Authorization': `Bearer ${localStorage.getItem('access_token')}`
            }
        });
        if (!response.ok) {
            throw new Error('Failed to fetch tournament');
        }
        return await response.json();
    },

    createTournament: async function() {
        const name = prompt("Enter tournament name:");
        if (!name) return;
        
        let maxParticipants;
        do {
            const input = prompt("Enter max number of participants (2, 4, 8, 16, or 32):");
            
            // Verifica che l'input sia esattamente uno dei valori consentiti
            if (/^(2|4|8|16|32)$/.test(input)) {
                maxParticipants = parseInt(input);
            } else {
                alert("Please enter a valid number: 2, 4, 8, 16, or 32");
            }
        } while (![2, 4, 8, 16, 32].includes(maxParticipants));
    
        try {
            const response = await fetch('/api/tournament/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                },
                body: JSON.stringify({ name, max_participants: maxParticipants })
            });
    
            if (response.ok) {
                alert('Tournament created successfully');
                this.render();
            } else {
                const data = await response.json();
                alert(`Failed to create tournament: ${data.error || 'Unknown error'}`);
            }
        } catch (error) {
            console.error('Error creating tournament:', error);
            alert('An error occurred while creating the tournament');
        }
    },

    joinTournament: async function(tournamentId) {
        const alias = prompt('Enter participant alias:');
        if (!alias) return;
    
        try {
            const response = await fetch(`/api/tournament/${tournamentId}/join/`, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                },
                body: JSON.stringify({ alias })
            });
    
            if (response.ok) {
                const data = await response.json();
                if (data.status === 'IN_PROGRESS') {
                    alert('Participant added and the tournament has started!');
                } else {
                    alert('Participant added successfully');
                }
                this.render(tournamentId);
            } else {
                const error = await response.json();
                alert(`Error adding participant: ${error.error || 'Unknown error'}`);
            }
        } catch (error) {
            console.error('Error adding participant:', error);
            alert('An error occurred while adding the participant');
        }
    },

    startMatch: async function(tournamentId, matchId) {
        try {
            const response = await fetch(`/api/tournament/${tournamentId}/match/${matchId}/start/`, {
                method: 'POST',
                headers: {
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                }
            });
    
            if (response.ok) {
                const matchData = await response.json();
                // Reindirizza alla pagina del gioco
                window.location.hash = `#game/${tournamentId}/${matchId}`;
            } else {
                const error = await response.json();
                alert(`Error starting match: ${error.error || 'Unknown error'}`);
            }
        } catch (error) {
            console.error('Error starting match:', error);
            alert('An error occurred while starting the match');
        }
    },

    showTournamentResults: async function(tournamentId) {
        try {
            const tournament = await this.getTournament(tournamentId);
            let resultsHtml = `<h2>${tournament.name} - Tournament Results</h2>`;
    
            // Partecipanti
            resultsHtml += `<h3>Participants:</h3><ul>`;
            tournament.participants.forEach(p => {
                resultsHtml += `<li>${p.alias}</li>`;
            });
            resultsHtml += `</ul>`;
    
            // Risultati per round
            let roundMatches = {};
            tournament.matches.forEach(match => {
                if (!roundMatches[match.round]) {
                    roundMatches[match.round] = [];
                }
                roundMatches[match.round].push(match);
            });
    
            Object.keys(roundMatches).sort((a, b) => a - b).forEach(round => {
                resultsHtml += `<h3>Round ${round}:</h3><ul>`;
                roundMatches[round].forEach(match => {
                    resultsHtml += `<li>${match.player1_alias} vs ${match.player2_alias}: `;
                    if (match.winner_alias) {
                        resultsHtml += `Winner - ${match.winner_alias} (${match.score_player1} - ${match.score_player2})`;
                    } else {
                        resultsHtml += `Not played yet`;
                    }
                    resultsHtml += `</li>`;
                });
                resultsHtml += `</ul>`;
            });
    
            // Vincitore del torneo
            if (tournament.status === 'FINISHED') {
                const finalMatch = tournament.matches[tournament.matches.length - 1];
                resultsHtml += `<h3>Tournament Winner: ${finalMatch.winner_alias}</h3>`;
            }
    
            // Mostra i risultati in un modal o in una nuova pagina
            const modal = document.createElement('div');
            modal.style.position = 'fixed';
            modal.style.left = '0';
            modal.style.top = '0';
            modal.style.width = '100%';
            modal.style.height = '100%';
            modal.style.backgroundColor = 'rgba(0,0,0,0.5)';
            modal.style.overflowY = 'auto';
    
            const modalContent = document.createElement('div');
            modalContent.style.backgroundColor = '#fff';
            modalContent.style.margin = '10% auto';
            modalContent.style.padding = '20px';
            modalContent.style.width = '80%';
            modalContent.innerHTML = resultsHtml;
    
            const closeBtn = document.createElement('button');
            closeBtn.textContent = 'Close';
            closeBtn.onclick = () => document.body.removeChild(modal);
            modalContent.appendChild(closeBtn);
    
            modal.appendChild(modalContent);
            document.body.appendChild(modal);
        } catch (error) {
            console.error('Error showing tournament results:', error);
            alert('Error loading tournament results');
        }
    },

    showBracket: async function(tournamentId) {
        console.log("showBracket called with tournamentId:", tournamentId);
        try {
            const tournament = await this.getTournament(tournamentId);
            console.log("Tournament data received:", tournament);
            const bracketHtml = this.generateBracket(tournament);
            console.log("Bracket HTML generated:", bracketHtml);
    
            const modal = document.createElement('div');
            modal.className = 'modal';
            modal.style.display = 'block'; // Ensure the modal is visible
            modal.innerHTML = `
                <div class="modal-content">
                    <h2>${tournament.name} - Tournament Bracket</h2>
                    ${bracketHtml}
                    <button id="closeBracketBtn">Close</button>
                </div>
            `;
    
            document.body.appendChild(modal);
            document.getElementById('closeBracketBtn').onclick = () => {
                document.body.removeChild(modal);
            };
            console.log("Bracket modal added to DOM");
        } catch (error) {
            console.error('Error showing tournament bracket:', error);
            alert('Error loading tournament bracket');
        }
    },
    
    generateBracket: function(tournament) {
        const rounds = {};
        tournament.matches.forEach(match => {
            if (!rounds[match.round]) rounds[match.round] = [];
            rounds[match.round].push(match);
        });
    
        let bracketHtml = '<div class="tournament-bracket">';
        Object.keys(rounds).sort((a, b) => a - b).forEach(round => {
            bracketHtml += `<div class="round">`;
            bracketHtml += `<h3>Round ${round}</h3>`;
            rounds[round].forEach(match => {
                bracketHtml += `
                    <div class="match">
                        <div class="team ${match.winner_alias === match.player1_alias ? 'winner' : ''}">${match.player1_alias}</div>
                        <div class="team ${match.winner_alias === match.player2_alias ? 'winner' : ''}">${match.player2_alias}</div>
                    </div>
                `;
            });
            bracketHtml += `</div>`;
        });
        bracketHtml += '</div>';
    
        return bracketHtml;
    },
};