/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Autoindex.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:41:28 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:57:58 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_autoindex_module.html#autoindex
    Syntax:	    autoindex on | off;
    Default:    autoindex off;
    Context:	http, server, location
 */
class Autoindex : public Directive {
    public:
        Autoindex(string context);
        Autoindex(string raw_value, string context);
        ~Autoindex();
};
