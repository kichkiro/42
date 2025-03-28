/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:44:51 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:19 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#location
    Syntax:	    location [ = | ~ | ~* | ^~ ] uri { ... }
                location @name { ... }
    Default:	—
    Context:	server, location
 */
class Location : public Directive {
    public:
        Location(string context);
        Location(ifstream &raw_value, string context);
        ~Location();
};
