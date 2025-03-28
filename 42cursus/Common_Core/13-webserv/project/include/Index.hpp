/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Index.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:41:11 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:26 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_index_module.html#index
    Syntax:	    index file ...;
    Default:    index index.html;
    Context:	http, server, location
 */
class Index : public Directive {
    public:
        Index(string context);
        Index(string raw_value, string context);
        ~Index();
};
