/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:15:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/24 17:23:29 by kichkiro         ###   ########.fr       */
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
    streampos prev_pos,
    ifstream &file
) {
    (void)prev_pos;
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
    else
        cerr << "Error: Directive: syntax error" << endl;
}

// Include -------------------------------------------------------------------->

Include::Include(string raw_value, vector<string> &parsed_content) {
    this->_type == "include";
    this->_is_context = false;
    this->_first_parsing(raw_value, parsed_content);
}

Include::~Include() {}

void Include::_first_parsing(string raw_value, vector<string> &parsed_content) {
    (void)parsed_content;
    // ifstream included(raw_value.substr(raw_value.find_first_of(" /t"), ))

    cout << "INCLUDE: " << raw_value[7] << endl;
    
    


}

void Include::_parsing(ifstream &raw_value) {
    (void)raw_value;
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
    this->_parsing(raw_value);
}

Http::~Http() {
    typedef vector<Directive*>::iterator IT;
    for (IT it = _value.begin(); it != _value.end(); ++it)
        delete *it;
}

void Http::_parsing(ifstream &raw_value) {
    streampos prev_pos;
    string line, token;
    int    brackets;

    prev_pos = raw_value.tellg();
    brackets = 0;
    while (getline(raw_value, line)) {
        token = first_token(strip(line));
        cout << "http:       " << token << endl;
        if (token[0] == 35) {
            prev_pos = raw_value.tellg();
            continue;
        }
        else if (str_in_array(token.c_str(), this->_directives))
            router(this->_value, this->_type, token, prev_pos, raw_value);
        else if (line.find_first_of("{") != string::npos)
            brackets++;
        else if (line.find_first_of("}") != string::npos)
            brackets--;
        if (brackets == -1)
            break;
        prev_pos = raw_value.tellg();
    }
}

// Server --------------------------------------------------------------------->

// <...>

