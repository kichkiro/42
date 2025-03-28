/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:44:25 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 19:03:22 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

/*!
* @brief Initialize a new Server object, and create a new socket
* @details This constructor initializes a new Server object, and creates a new socket using
    the socket() function from the sys/socket.h library by giving it three arguments:
    - AF_INET: The protocol family to be used, in this case, the Internet Protocol v4 addresses.
    - SOCK_STREAM: The type of socket to be created, in this case, a stream socket.
    - 0: The protocol to be used, in this case, the default protocol for the given protocol family and socket type.

    Then, it initializes the _address attribute with the following values:
    - sin_family: The protocol family to be used, in this case, the Internet Protocol v4 addresses.
    - sin_addr: The IPv4 address of the server, not bound to any specific address, will listen to all available interfaces, using the INADDR_ANY macro from the netinet/in.h library.
    - sin_port: The port number of the server, converted to network byte order using the htons() function from the netinet/in.h library.
*/
Socket::Socket() : _port(PORT),
_maxConnections(MAX_CONNECTIONS),
_timeout((timeval) {
    TIMEOUT_SEC, TIMEOUT_USEC
}),
_flags(0) {
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    _serverAddress.sin_family = AF_INET;
    _serverAddress.sin_addr.s_addr = INADDR_ANY;
    _serverAddress.sin_port = htons(_port);
}

Socket::Socket(int port) :
    _port(port),
    _maxConnections(MAX_CONNECTIONS),
    _timeout((timeval) {TIMEOUT_SEC, TIMEOUT_USEC}),
    _flags(0) {
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    _serverAddress.sin_family = AF_INET;
    _serverAddress.sin_addr.s_addr = INADDR_ANY;
    _serverAddress.sin_port = htons(_port);
}

/*!
* @brief Delete a Server object
* @details This destructor deletes a Server object, and closes the socket using the close() function from the unistd.h library.
*/
Socket::~Socket() {
    close();
}

/*!
* @brief Bind the socket to the address
* @details This function binds the socket to the address using the bind() function from the sys/socket.h library.
    - The first argument is the file descriptor of the socket.
    - The second argument is the address information of the server.
    - The third argument is the size of the address information of the server.
* @return The result of the bind() function
*/
int Socket::bind() {
    memset(_serverAddress.sin_zero, '\0', sizeof _serverAddress.sin_zero);
    return (::bind(_serverSocket, (struct sockaddr *)&_serverAddress, sizeof(_serverAddress)));
}

/*!
* @brief Listen for incoming connections
* @param connections The maximum length of the queue of pending connections
* @details This function listens for incoming connections using the listen() function from the sys/socket.h library.
    - The first argument is the file descriptor of the socket.
    - The second argument is the maximum length of the queue of pending connections.
* @return The result of the listen() function
*/
int Socket::listen(int connections) {
    return (::listen(_serverSocket, connections));
}

/*!
* @brief Set the socket to non-blocking
* @details This function sets the socket to non-blocking using the fcntl() function from the fcntl.h library.
    - The first argument is the file descriptor of the socket.
    - The second argument is the command to be executed, in this case, F_SETFL, which sets the file status flags to the value specified by the third argument.
    - The third argument is the value to be set, in this case, the value of the flags attribute OR'd with the O_NONBLOCK macro, which sets the file status flags to non-blocking mode.
* @return The result of the fcntl() function
*/
int Socket::nonBlocking() {
    return (_flags = fcntl(_serverSocket, F_SETFL, _flags | O_NONBLOCK));
}

/*!
* @brief The main loop of the server
* @details This function is the main loop of the server, using the select() is possible to check if there is any data available to read on the socket without blocking.
    The arguments of the select() function are:
    - The range of file descriptors to be checked, set to highest numbered file descriptor in any of the three sets, plus 1, to tell the select function the effective size of the bit masks it should consider.
    - The file descriptor set to be checked for read activity.
    - The file descriptor set to be checked for write activity.
    - The file descriptor set to be checked for exceptions.
    - The timeout value.
    If the select() function returns a value less than 0, an error occurred, and the program exits,
    if the return value is 0, the connection timed out, and the program continues, otherwise it accepts a new connection, answers the client, and closes the client socket.
* @return In case of an error, the exit code of the respective error, otherwise, 0
*/
int Socket::run() {
    int r;

    while (1) {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(_serverSocket, &readfds);
        timeval t = _timeout;

        if ((r = select(_serverSocket + 1, &readfds, NULL, NULL, &t) < 0))
            return (Error::exit(FAILED_SELECT, *this));
        else if (r == 0)
            Error::checkError(r, TIMEOUT);

        // If the server socket is not ready, continue
        if (!FD_ISSET(_serverSocket, &readfds))
            continue;

        // Accept a new connection
        if (_accept() < 0)
            return (Error::exit(FAILED_ACCEPT, *this));

        // Get the client request
        _clientRequest();

        // Answer the client
        _answer();

        // Close the client socket
        close();
    }
}

/*!
* @brief Get the client request
* @details This function gets the client request using the recv() function from the sys/socket.h library.
    - The first argument is the file descriptor of the client socket.
    - The second argument is the buffer to store the message.
    - The third argument is the size of the buffer.
* @return The result of the recv() function
*/
void Socket::_clientRequest() {
    char buffer[BUFFER_SIZE];
    int bytes = recv(_clientSocket, buffer, 1024, 0);
    buffer[bytes] = '\0';
    Log::request(GET, buffer);
}

/*!
* @brief Accept a new connection
* @details This function accepts a new connection using the accept() function from the sys/socket.h library.
    - The first argument is the file descriptor of the socket.
    - The second argument is the ad dress information of the client.
    - The third argument is the size of the address information of the client.
*/
int Socket::_accept() {
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    _clientSocket = ::accept(_serverSocket, (sockaddr *)&clientAddr, &clientAddrLen);
    return (_clientSocket);
}

/*!
* @brief Answer the client
* @details This function answers the client using the send() function from the sys/socket.h library.
    - The first argument is the file descriptor of the client socket.
    - The second argument is the message to be sent.
    - The third argument is the size of the message to be sent.
*/
void Socket::_answer() {
    std::string response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
    send(_clientSocket, response.c_str(), response.size(), 0);
}

/*!
* @brief Close the client socket
* @details This function closes the client socket using the close() function from the unistd.h library.
*/
void Socket::close() {
    if (_clientSocket > 0)
        ::close(_clientSocket);
}

/*!
* @brief Get the port number of the server
* @return The port number of the server
*/
uint16_t Socket::getPort() const {
    return (_port);
}

std::string Socket::getPortString() const {
    std::stringstream ss;
    ss << _port;
    return (ss.str());
}

/*!
* @brief Get the file descriptor of the socket
* @return The file descriptor of the socket
*/
int Socket::getSocket() const {
    return (_serverSocket);
}

/*!
* @brief Get the address information of the server
* @return The address information of the server
*/
sockaddr_in Socket::getAddress() const {
    return (_serverAddress);
}
