/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directive.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:15:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/23 17:26:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Directive.hpp"

const char *directives1[] = {
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

// Directive - Base Class ----------------------------------------------------->

Directive::Directive(void) {
    // this->_directives.push_back("http");
    // this->_directives.push_back("server");
    // this->_directives.push_back("location");
    // this->_directives.push_back("limit_except");
    // this->_directives.push_back("listen");
    // this->_directives.push_back("root");
    // this->_directives.push_back("server_name");
    // this->_directives.push_back("include");
    // this->_directives.push_back("error_page");
    // this->_directives.push_back("client_max_body_size");
    // this->_directives.push_back("alias");
    // this->_directives.push_back("index");
    // this->_directives.push_back("autoindex");
}

Directive::~Directive() {}

vector<string> Directive::get_directives(void) {
    return this->_directives;
}

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
    ifstream file
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

Http::~Http() {}

void Http::_parse(ifstream &raw_value) {
    string line;
    int    brackets;

    while (getline(raw_value, line)) {
        string result2 = line.substr(0, line.find_first_of(" \t"));

        if (result2[0] == 35)
            continue;
        else if (str_in_array(result2.c_str(), directives1))
            router(this->_value, this->_type, result2, raw_value);
            // cout << endl;
        else if (line.find_first_of("{") != string::npos)
            brackets++;
        else if (line.find_first_of("}") != string::npos)
            brackets--;
        if (brackets == -1)
            break;
    }
}

// Server --------------------------------------------------------------------->

