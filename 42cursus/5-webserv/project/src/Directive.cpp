/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directive.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:15:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/22 17:08:57 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Directive.hpp"

// Directive - Base Class ----------------------------------------------------->

Directive::Directive(void) {}

Directive::~Directive() {}

void Directive::set_type(string type) {
    this->_type = type;
}

void Directive::set_allowed_context(vector<string> allowed_context) {
    this->_allowed_context = allowed_context;
}

void Directive::set_is_context(bool is_context) {
    this->_is_context = is_context;
}

string Directive::get_type(void) {
    return this->_type;
}

vector<string> Directive::get_allowed_context(void) {
    return this->_allowed_context;
}

bool Directive::get_is_context(void) {
    return this->_is_context;
}


// Http ----------------------------------------------------------------------->

Http::Http(void) {
    vector<string>    allowed_context;
    vector<Directive*> value;

    allowed_context.push_back("any");
    this->set_type("http");
    this->set_allowed_context(allowed_context);
    this->set_is_context(true);
    this->_value = value;
}

Http::Http(string raw_value) {
    vector<string>    allowed_context;

    allowed_context.push_back("any");
    this->set_type("http");
    this->set_allowed_context(allowed_context);
    this->set_is_context(true);
    this->_parse(raw_value);
}

Http::~Http() {}

void Http::_parse(string raw_value) {
    vector<Directive*> value; 

    (void)raw_value;

    this->_value = value;
}

// Server --------------------------------------------------------------------->


