/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Http.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:24:50 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 19:08:35 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"
// #include "Socket.hpp"

// class Socket;

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#http
    Syntax:	    http { ... }
    Default:	—
    Context:	main
 */
class Http : public Directive {
    private:
        void _init_sockets(int server_sockets[], struct pollfd fds[], int &num_fds, int number_of_ports, vector<int> ports);
        void _handle_polling(int server_sockets[], struct pollfd fds[], int num_fds);

        vector<int> _get_ports(void);

    public:
        Http(string context);
        Http(ifstream &raw_value, string context);
        ~Http();

        void start_servers();
};
