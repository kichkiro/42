/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directive.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:15:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/10 15:57:51 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Directive.hpp"

const char *Directive::_directives[] = {
    "http",
    "server",
    "location",
    "limit_except",
    "listen",
    "root",
    "server_name",
    "include",
    "error_page",
    "client_max_body_size",
    "alias",
    "index",
    "autoindex",
    "rewrite",
    NULL
};

Directive::Directive(void) {}

Directive::~Directive() {}

string Directive::get_type(void) const {
    return this->_type;
}

bool Directive::get_is_context(void) const {
    return this->_is_context;
}

vector<string> Directive::get_value_inline(void) const {
    return this->_value_inline;
}

vector<Directive *> Directive::get_value_block(void) const {
    return this->_value_block;
}

size_t Directive::get_block_size(void) const {
    return this->_value_block.size();
}

size_t Directive::get_inline_size(void) const {
    return this->_value_inline.size();
}

/*!
 * @brief
    Router method for handling different directives.

    This method can only be called by the ConfigFile class and the derived
    Directive classes that are contexts.
 * @param value
    Vector of Directive pointers to store created objects.
 * @param context
    Context of origin.
 * @param directive
    Directive to analyze.
 * @param file
    File containing unparsed values.
 */
void Directive::router(
    vector<Directive *> &value,
    string context,
    string directive,
    string line,
    ifstream &file
) {
    if (directive == "http")
        value.push_back(new Http(file, context));
    else if (directive == "server")
        value.push_back(new Server(file, context));
    // else if (directive == "location")
    //     value.push_back(new Location(file, context));
    // else if (directive == "limit_except")
    //     value.push_back(new LimitExcept(file, context));
    else if (directive == "listen")
        value.push_back(new Listen(line, context));
    else if (directive == "root")
        value.push_back(new Root(line, context));
    else if (directive == "server_name")
        value.push_back(new ServerName(line, context));
    else if (directive == "error_page")
        value.push_back(new ErrorPage(line, context));
    else if (directive == "client_max_body_size")
        value.push_back(new ClientMaxBodySize(line, context));
    else if (directive == "alias")
        value.push_back(new Alias(line, context));
    else if (directive == "index")
        value.push_back(new Index(line, context));
    else if (directive == "autoindex")
        value.push_back(new Autoindex(line, context));
    else if (directive == "rewrite")
        value.push_back(new Rewrite(line, context));
    else
        cerr << "webserv: Directive: <" << directive <<
        "> directive does not exists" << endl;
}

void Directive::_parsing_inline(string raw_value) {
    size_t i;
    string value;

    i = 0;
    value = "";
    while (i <= this->_type.length())
        i++;
    while (raw_value[i] != 59 && i < raw_value.length()) {
        value = "";
        while (raw_value[i] != 32 && raw_value[i] != 9 && raw_value[i] != 59)
            value += raw_value[i++];
        if (raw_value[i] != 59)
            i++;
        this->_value_inline.push_back(value);
    }
}

void Directive::_parsing_block(ifstream &raw_value) {
    string    line, token;
    int       brackets;

    brackets = 0;
    while (getline(raw_value, line)) {
        token = first_token(strip(line));
        if (token[0] == 35)
            continue;
        else if (str_in_array(token.c_str(), this->_directives))
            router(this->_value_block, this->_type, token, line, raw_value);
        if (line.find_first_of("{") != string::npos)
            brackets++;
        else if (line.find_first_of("}") != string::npos)
            brackets--;
        if (brackets == -1)
            break;
    }
}
