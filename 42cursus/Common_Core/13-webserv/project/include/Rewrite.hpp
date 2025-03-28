/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rewrite.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:41:00 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:16 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_rewrite_module.html#rewrite
    Syntax:     rewrite regex replacement [flag];
    Default:	—
    Context:	server, location, if
 */
class Rewrite : public Directive {
    public:
        Rewrite(string context);
        Rewrite(string raw_value, string context);
        ~Rewrite();
};
