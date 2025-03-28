/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorPage.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:49:08 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:49:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ErrorPage.hpp"

ErrorPage::ErrorPage(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("ErrorPage", "http|server|location", context);
    this->_type = "error_page";
    this->_is_context = false;
    this->_value_inline = value;
}

ErrorPage::ErrorPage(string raw_value, string context) {
    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("ErrorPage", "http|server|location", context);
    this->_type = "error_page";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

ErrorPage::~ErrorPage() {}
