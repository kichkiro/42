/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:15:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/23 15:05:21 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Directives.hpp"

// Directive - Base Class ----------------------------------------------------->

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
    NULL
};

Directive::Directive(void) {}

Directive::~Directive() {}

/*!
 * @brief
    Router method for handling different directives.
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
    ifstream &file
) {
    if (directive == "http")
        value.push_back(new Http(file, context));
    // else if (directive == "server")
    //     value.push_back(new Server(file, context));   
    // else if (directive == "location")
    //     value.push_back(new Location(file, context));
    // else if (directive == "limit_except")
    //     value.push_back(new LimitExcept(file, context));
    // else if (directive == "listen")
    //     value.push_back(new Listen(file, context));
    // else if (directive == "root")
    //     value.push_back(new Root(file, context));
    // else if (directive == "server_name")
    //     value.push_back(new ServerName(file, context));
    // else if (directive == "include")
    //     value.push_back(new Include(file, context));
    // else if (directive == "error_page")
    //     value.push_back(new ErrorPage(file, context));
    // else if (directive == "client_max_body_size")
    //     value.push_back(new ClientMaxBodySize(file, context));
    // else if (directive == "alias")
    //     value.push_back(new Alias(file, context));
    // else if (directive == "index")
    //     value.push_back(new Index(file, context));
    // else if (directive == "autoindex")
    //     value.push_back(new Autoindex(file, context));
}

// Http ----------------------------------------------------------------------->

Http::Http(string context) {
    vector<Directive *> value;

    if (context != "main") {
        cerr << "Http: http context can be used only in: main" << endl;
        // Exit
    }
    this->_type == "http";
    this->_is_context = true;
    this->_value = value;
}

Http::Http(ifstream &raw_value, string context) {
    if (context != "main") {
        cerr << "Http: http directive can be used only in main context" << endl;
        // Exit
    }
    this->_type == "http";
    this->_is_context = true;
    this->_parse(raw_value);
}

Http::~Http() {
    typedef vector<Directive*>::iterator IT;
    for (IT it = _value.begin(); it != _value.end(); ++it)
        delete *it;
}

void Http::_parse(ifstream &raw_value) {
    string line, result2;
    int    brackets;

    brackets = 0;
    while (getline(raw_value, line)) {
        result2 = line.substr(0, line.find_first_of(" \t"));
        if (result2[0] == 35)
            continue;
        else if (str_in_array(result2.c_str(), this->_directives))
            router(this->_value, this->_type, result2, raw_value);
        else if (line.find_first_of("{") != string::npos)
            brackets++;
        else if (line.find_first_of("}") != string::npos)
            brackets--;
        if (brackets == -1)
            break;
    }
}

// Server --------------------------------------------------------------------->

