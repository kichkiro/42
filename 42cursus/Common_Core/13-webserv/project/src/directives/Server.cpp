/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:47:42 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 18:41:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(string context) {
    vector<Directive *> value;

    if (context != "http")
        throw WrongContextExc("Server", "http", context);
    this->_type = "server";
    this->_is_context = true;
    this->_value_block = value;
}

Server::Server(ifstream &raw_value, string context) {
    if (context != "http")
        throw WrongContextExc("Server", "http", context);
    this->_type = "server";
    this->_is_context = true;
    this->_parsing_block(raw_value);
}

Server::~Server() {
    for (VecDirIt it = this->_value_block.begin();
        it != this->_value_block.end(); ++it)
        delete *it;
}
