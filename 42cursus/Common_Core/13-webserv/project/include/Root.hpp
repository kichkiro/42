/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Root.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:40:43 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#root
    Syntax:	    root path;
    Default:	root html;
    Context:	http, server, location
 */
class Root : public Directive {
    public:
        Root(string context);
        Root(string raw_value, string context);
        ~Root();
};
