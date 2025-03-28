/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerName.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:40:54 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#server_name
    Syntax:	    server_name name ...;
    Default:    server_name "";
    Context:	server
 */
class ServerName : public Directive {
    public:
        ServerName(string context);
        ServerName(string raw_value, string context);
        ~ServerName();
};
