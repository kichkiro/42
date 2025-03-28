/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorPage.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:41:19 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:37 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#error_page
    Syntax:	    error_page code ... [=[response]] uri;
    Default:	—
    Context:	http, server, location
 */
class ErrorPage : public Directive {
    public:
        ErrorPage(string context);
        ErrorPage(string raw_value, string context);
        ~ErrorPage();
};
