/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Index.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:50:51 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:51:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Index.hpp"

Index::Index(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("Index", "http|server|location", context);
    value.push_back("index.html");
    this->_type = "index";
    this->_is_context = false;
    this->_value_inline = value;
}

Index::Index(string raw_value, string context) {
    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("Index", "http|server|location", context);
    this->_type = "index";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Index::~Index() {}
