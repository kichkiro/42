const ProfileView = {
    render: async function() {
        const token = localStorage.getItem('access_token');
        if (!token) {
            window.location.hash = '#login';
            return;
        }
        const app = document.getElementById('app');
        app.innerHTML = '<h2>Loading profile...</h2>';

        try {
            const profileResponse = await fetch('/api/accounts/me/', {
                headers: {
                    'Authorization': `Bearer ${token}`
                }
            });
            const statsResponse = await fetch('/api/user/stats/', {
                headers: {
                    'Authorization': `Bearer ${token}`
                }
            });
            const friendsResponse = await fetch('/api/friends/', {
                headers: {
                    'Authorization': `Bearer ${token}`
                }
            });

            if (profileResponse.ok && statsResponse.ok && friendsResponse.ok) {
                const profileData = await profileResponse.json();
                this.profileData = profileData; // Assegna profileData come proprietà
                const statsData = await statsResponse.json();
                const friendsData = await friendsResponse.json();
                
                app.innerHTML = `
                    <div class="container mt-5">
                        <h2>User Profile</h2>
                        <div class="row">
                            <div class="col-md-4">
                                <img src="${profileData.avatar || '/static/img/default_avatar.png'}" alt="Avatar" class="img-fluid rounded-circle mb-3" id="avatar-preview">
                                <input type="file" id="avatar-input" style="display: none;" accept="image/*">
                                <button class="btn btn-primary" id="change-avatar-btn">Change Avatar</button>
                            </div>
                            <div class="col-md-8">
                                <form id="profile-form">
                                    <div class="mb-3">
                                        <label for="username" class="form-label">Username</label>
                                        <input type="text" class="form-control" id="username" value="${profileData.username}">
                                    </div>
                                    <div class="mb-3">
                                        <label for="email" class="form-label">Email</label>
                                        <input type="email" class="form-control" id="email" value="${profileData.email}">
                                    </div>
                                    <button type="submit" class="btn btn-primary">Update Profile</button>
                                </form>
                            </div>
                        </div>
                        <div class="row mt-4">
                            <div class="col-md-6">
                                <h3>Stats</h3>
                                <p>Games Played: ${statsData.games_played}</p>
                                <p>Games Won: ${statsData.games_won_count}</p>
                                <p>Total Score: ${statsData.total_score}</p>
                                <p>Win Rate: ${statsData.win_rate}%</p>
                            </div>
                            <div class="col-md-6">
                                <h3>Friends</h3>
                                <ul id="friends-list">
                                    ${friendsData.map(friend => `
                                        <li>
                                            ${friend.username} 
                                            <span class="${friend.is_online ? 'online' : 'offline'}">
                                                (${friend.is_online ? 'Online' : 'Offline'})
                                            </span>
                                        </li>
                                    `).join('')}
                                </ul>
                                <div class="mt-3">
                                    <input type="text" id="friend-username" placeholder="Friend's username">
                                    <button id="add-friend-btn" class="btn btn-secondary">Add Friend</button>
                                </div>
                            </div>
                        </div>
                        <div class="row mt-4">
                            <div class="col">
                                <h3>Match History</h3>
                                <div id="match-history"></div>
                            </div>
                        </div>
                    </div>
                `;
                this.attachEventListeners();
                this.loadMatchHistory();
            } else {
                app.innerHTML = '<h2>Failed to load profile</h2>';
            }
        } catch (error) {
            console.error('Error:', error);
            app.innerHTML = '<h2>Error loading profile</h2>';
        }
    },

    attachEventListeners: function() {
        const form = document.getElementById('profile-form');
        form.addEventListener('submit', this.handleProfileUpdate);
    
        const changeAvatarBtn = document.getElementById('change-avatar-btn');
        changeAvatarBtn.addEventListener('click', this.handleAvatarChange);
    
        const avatarInput = document.getElementById('avatar-input');
        avatarInput.addEventListener('change', this.handleAvatarUpload);

        const addFriendBtn = document.getElementById('add-friend-btn');
        addFriendBtn.addEventListener('click', this.handleAddFriend);
    },

    handleProfileUpdate: async function(e) {
        e.preventDefault();
        const username = document.getElementById('username').value;
        const email = document.getElementById('email').value;
        const updateData = { username, email };

        try {
            const response = await fetch('/api/accounts/me/', {
                method: 'PATCH',  // Cambiato da PUT a PATCH
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                },
                body: JSON.stringify(updateData)
            });

            if (response.ok) {
                const responseData = await response.json();
                alert('Profile updated successfully');
                document.getElementById('username').value = responseData.username;
                document.getElementById('email').value = responseData.email || '';
            } else {
                const errorData = await response.json();
                alert('Failed to update profile: ' + JSON.stringify(errorData));
            }
        } catch (error) {
            console.error('Error:', error);
            alert('An error occurred while updating profile');
        }
    },

    handleAvatarChange: function() {
        console.log('Avatar change button clicked');
        document.getElementById('avatar-input').click();
    },
    
    handleAvatarUpload: async function(e) {
        console.log('Avatar file selected', e.target.files[0]);
        const file = e.target.files[0];
        if (file) {
            const formData = new FormData();
            formData.append('avatar', file);
    
            try {
                const response = await fetch('/api/accounts/me/', {
                    method: 'PATCH',
                    headers: {
                        'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                    },
                    body: formData
                });
    
                if (response.ok) {
                    const data = await response.json();
                    document.getElementById('avatar-preview').src = data.avatar;
                    alert('Avatar updated successfully');
                } else {
                    const errorData = await response.json();
                    alert('Failed to update avatar: ' + JSON.stringify(errorData));
                }
            } catch (error) {
                console.error('Error:', error);
                alert('An error occurred while updating avatar');
            }
        }
    },

    loadMatchHistory: async function() {
        const matchHistoryDiv = document.getElementById('match-history');
        try {
            const response = await fetch('/api/accounts/matches/', {
                headers: {
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                }
            });
            if (response.ok) {
                const matches = await response.json();
                console.log('Matches:', matches);
                const username = this.profileData.username;
    
                if (matches.length === 0) {
                    matchHistoryDiv.innerHTML = '<p>No matches found.</p>';
                    return;
                }
    
                matchHistoryDiv.innerHTML = `
                    <table class="table">
                        <thead>
                            <tr>
                                <th>Date</th>
                                <th>Opponent</th>
                                <th>Result</th>
                                <th>Score</th>
                            </tr>
                        </thead>
                        <tbody>
                            ${matches.map(match => {
                                const opponent = match.player1_username === username
                                    ? (match.player2_username || match.player2_alias || 'Unknown')
                                    : (match.player1_username || 'Unknown');
                                const result = match.winner_username === username ? 'Win' : 'Loss';
                                const score = `${match.score_player1} - ${match.score_player2}`;
                                return `
                                    <tr>
                                        <td>${new Date(match.date_played).toLocaleString()}</td>
                                        <td>${opponent}</td>
                                        <td>${result}</td>
                                        <td>${score}</td>
                                    </tr>
                                `;
                            }).join('')}
                        </tbody>
                    </table>
                `;
            } else {
                matchHistoryDiv.innerHTML = '<p>Failed to load match history</p>';
            }
        } catch (error) {
            console.error('Error:', error);
            matchHistoryDiv.innerHTML = '<p>Error loading match history</p>';
        }
    },

    handleAddFriend: async function() {
        const friendUsername = document.getElementById('friend-username').value;
        if (!friendUsername) {
            alert('Please enter a friend\'s username');
            return;
        }

        try {
            const response = await fetch('/api/friends/add/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${localStorage.getItem('access_token')}`
                },
                body: JSON.stringify({ friend_username: friendUsername })
            });

            if (response.ok) {
                alert('Friend added successfully');
                // Aggiorna la lista degli amici
                const friendsList = document.getElementById('friends-list');
                friendsList.innerHTML += `<li>${friendUsername}</li>`;
                document.getElementById('friend-username').value = '';
            } else {
                const errorData = await response.json();
                alert('Failed to add friend: ' + errorData.error);
            }
        } catch (error) {
            console.error('Error:', error);
            alert('An error occurred while adding friend');
        }
    }
};