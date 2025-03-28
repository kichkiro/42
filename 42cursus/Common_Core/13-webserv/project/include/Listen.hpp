/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Listen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:41:07 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:21 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#listen
    Syntax:	    listen address[:port];
    Default:	listen *:80;
    Context:	server
 */
class Listen : public Directive {
    public:
        Listen(string context);
        Listen(string raw_value, string context);
        ~Listen();
};
