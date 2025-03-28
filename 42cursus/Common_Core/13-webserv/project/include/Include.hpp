/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Include.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:25:22 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.h"

// Class ---------------------------------------------------------------------->

/*!
 * @ref 
    Docs:       https://nginx.org/en/docs/ngx_core_module.html#include
    Syntax:	    include file | mask;
    Default:	—
    Context:	any
 */
class Include : public Directive {
    private:
        void _parsing(string raw_value, vector<string> &parsed_content);
        
    public:
        Include(string raw_value, vector<string> &parsed_content);
        ~Include();
};
