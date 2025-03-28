/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alias.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:49:40 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:49:46 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Alias.hpp"

Alias::Alias(string context) {
    vector<string> value;

    if (context != "location")
        throw WrongContextExc("Alias", "location", context);
    this->_type = "alias";
    this->_is_context = false;
    this->_value_inline = value;
}

Alias::Alias(string raw_value, string context) {
    if (context != "location")
        throw WrongContextExc("Alias", "location", context);
    this->_type = "alias";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Alias::~Alias() {}
