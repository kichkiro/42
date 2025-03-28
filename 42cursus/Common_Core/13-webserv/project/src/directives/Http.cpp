/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Http.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:47:13 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 19:03:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Http.hpp"

Http::Http(string context) {
    vector<Directive *> value;

    if (context != "main")
        throw WrongContextExc("Http", "main", context);
    this->_type = "http";
    this->_is_context = true;
    this->_value_block = value;
}

Http::Http(ifstream &raw_value, string context) {
    if (context != "main")
        throw WrongContextExc("Http", "main", context);
    this->_type = "http";
    this->_is_context = true;
    this->_parsing_block(raw_value);
}

Http::~Http() {
    for (VecDirIt it = this->_value_block.begin();
        it != this->_value_block.end(); ++it)
        delete *it;
}

vector<int> Http::_get_ports(void) {
    vector<int> ports;

    size_t number_of_servers = this->_value_block.size();
    for (size_t i = 0; i < number_of_servers; i++) {
        size_t number_of_directives = this->_value_block[i]->get_block_size();
        for (size_t j = 0; j < number_of_directives; j++) {
            if (this->_value_block[i]->get_value_block()[j]->get_type()
                == "listen") {
                size_t num_ports = this->_value_block[i]->get_value_block()[j]->get_inline_size();
                for (size_t k = 0; k < num_ports; k++) {
                    if (this->_value_block[i]->get_value_block()[j]->get_value_inline()[k] != "default_server") {
                        int port = atoi(this->_value_block[i]->get_value_block()[j]->get_value_inline()[k].c_str());
                        if (!int_in_vec(ports, port))
                            ports.push_back(port);
                    }
                }
            }
        }
    }
    return ports;
}

/*!
 * @brief
    Function to initialize sockets and pollfd structures for each port
    desired.
 * @param server_sockets
 * @param fds
 * @param num_fds
 */
void Http::_init_sockets(int server_sockets[], struct pollfd fds[], int &num_fds, int num_ports, vector<int> ports) {
    for (int i = 0; i < num_ports; ++i) {
        server_sockets[i] = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockets[i] == -1) {
            perror("Socket creation failed");
            exit(1);
        }

        // Setting the server address
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(ports[i]);
        if (bind(server_sockets[i], (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("Binding failed");
            close(server_sockets[i]);
            exit(1);
        }

        // Print that the server is listening on the port
        cout << "Server listening on port " << ntohs(server_addr.sin_port) << endl;

        // Put the socket listening
        if (listen(server_sockets[i], SOMAXCONN) == -1) {
            perror("Listening failed");
            close(server_sockets[i]);
            exit(1);
        }

        // Add the socket to the pollfd structure
        fds[num_fds].fd = server_sockets[i];
        fds[num_fds].events = POLLIN;
        num_fds++;
    }
}

/*!
 * @brief
    Function to handle polling cycle and events on sockets.
 * @param fds
 * @param num_fds
 * @param server_sockets
 */
void Http::_handle_polling(int server_sockets[], struct pollfd fds[], int num_fds) {
    while (true) {
        int poll_status = poll(fds, num_fds, -1);
        if (poll_status == -1) {
            perror("Poll failed");
            exit(1);
        }
        cout << poll_status << endl;
        // Handle events on sockets
        for (int i = 0; i < num_fds; ++i) {
            if (fds[i].revents & POLLIN) {

                int client_socket = accept(server_sockets[i], NULL, NULL);
                if (client_socket == -1) {
                    perror("Acceptance failed");
                    close(server_sockets[i]);
                    exit(1);
                }

                // Accept the connection and handle the request
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                getpeername(client_socket, (struct sockaddr *)&client_addr, &client_addr_len);
                printf("Client connected from port %d\n", ntohs(client_addr.sin_port));

                // Print the socket port
                char buffer[1024];
                ssize_t bytes_read = read(client_socket, buffer, sizeof(buffer));
                if (bytes_read == -1) {
                    perror("Reading failed");
                    close(client_socket);
                    continue;
                }

                // Print the HTTP request
                printf("HTTP request received: %.*s\n", static_cast<int>(bytes_read), buffer);

                // PROCESSARE QUI LA RICHIESTA E TORNARE LA RISPOSTA ***********

                const char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html>";

                // *************************************************************

                ssize_t bytes_sent = send(client_socket, response, strlen(response), 0);
                if (bytes_sent == -1) {
                    perror("Sending the response failed");
                    close(client_socket);
                    continue;
                }

                close(client_socket);
            }
        }
    }
}

void Http::start_servers(void) {
    vector<int> ports = this->_get_ports();
    int num_ports = ports.size();
    int server_sockets[num_ports];
    struct pollfd fds[num_ports];
    int num_fds = 0;

    this->_init_sockets(server_sockets, fds, num_fds, num_ports, ports);
    this->_handle_polling(server_sockets, fds, num_fds);

    for (int i = 0; i < num_fds; ++i)
        close(server_sockets[i]);
}
