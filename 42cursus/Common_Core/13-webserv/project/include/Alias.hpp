/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alias.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:41:32 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 18:02:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref
    Docs:       https://nginx.org/en/docs/http/ngx_http_core_module.html#alias
    Syntax:	    alias path;
    Default:	—
    Context:	location
 */
class Alias : public Directive {
    public:
        Alias(string context);
        Alias(string raw_value, string context);
        ~Alias();
};
