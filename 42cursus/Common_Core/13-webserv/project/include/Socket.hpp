/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:45:02 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 19:01:22 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Macros for the server default arguemnts, in case the configuration file is not provided
#define PORT 4242
#define MAX_CONNECTIONS 10
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0
#define BUFFER_SIZE 1024

/*!
* @brief A class to represent a server
* @param _port The port number of the server
* @param _serverSocket The file descriptor of the socket
* @param _serverAddress The address information of the server, includes:
* 	- sin_family: The protocol family to be used, in this case, the Internet Protocol v4 addresses.
* 	- sin_port: The port number of the server
* 	- sin_addr: The IPv4 address of the server
* @param _clientSocket The file descriptor of the client socket
* @param _flags The flags of the blocking mode of the socket
*/
class Socket {
	private:
		// From the configuration file
		int _port;
		int _maxConnections;
		timeval _timeout;

		// Socket information
		int _serverSocket;
		sockaddr_in _serverAddress;
		int _clientSocket;
		int _flags;

		Socket(const Socket &src);
		Socket &operator=(const Socket &src);

		// Server runtime functions
		void _clientRequest();
		int _accept();
		void _answer();

	public:
		// Socket();
		Socket(int port);
		~Socket();

		// Server setup functions
		int bind();
		int listen(int connections = MAX_CONNECTIONS);
		int nonBlocking();

		// Server runtime functions
		int run();
		void close();

		// Getters
		uint16_t getPort() const;
		std::string getPortString() const;
		int getSocket() const;
		sockaddr_in getAddress() const;
};
