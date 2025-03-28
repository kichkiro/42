/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:25:08 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 18:41:51 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#server
    Syntax:	    server { ... }
    Default:	—
    Context:	http
 */
class Server : public Directive {
    public:
        Server(string context);
        Server(ifstream &raw_value, string context);
        ~Server();
};
