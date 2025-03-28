/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rewrite.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:49:59 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:50:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rewrite.hpp"

Rewrite::Rewrite(string context) {
    vector<string> value;

    if (context != "server" && context != "location")
        throw WrongContextExc("Rewrite", "server|location", context);
    this->_type = "rewrite";
    this->_is_context = false;
    this->_value_inline = value;
}

Rewrite::Rewrite(string raw_value, string context) {
    if (context != "server" && context != "location")
        throw WrongContextExc("Rewrite", "server|location", context);
    this->_type = "rewrite";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Rewrite::~Rewrite() {}
