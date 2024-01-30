/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:15:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/30 16:41:41 by kichkiro         ###   ########.fr       */
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

vector<string> Directive::get_value_inline(void) {
    return this->_value_inline;
}

vector<Directive *> Directive::get_value_block(void) {
    return this->_value_block;
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

// Include -------------------------------------------------------------------->

Include::Include(string raw_value, vector<string> &parsed_content) {
    this->_type == "include";
    this->_is_context = false;
    this->_parsing(raw_value, parsed_content);
}

Include::~Include() {}

/*!
 * @brief
    
 * @param raw_value
    The input string containing raw configuration information.
 */
void Include::_parsing(string raw_value, vector<string> &parsed_content) {
    vector<string> configs;
    string         path, line;
    DIR           *dir;
    struct dirent *entry;
    ifstream       config;

    path = second_token(raw_value);
    if (path[path.length() - 1] == 42) {
        path = path.substr(0, path.length() - 1);
        dir = opendir(path.c_str());
        if (dir) {
            while ((entry = readdir(dir)) != NULL) {
                if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
                    configs.push_back(path + entry->d_name);
            }
            closedir(dir);
        }
    }
    else
        configs.push_back(path);
    for (VecStrIt it = configs.begin(); it != configs.end(); it++) {
        config.open(it->c_str());
        if (config.is_open()) {
            while (getline(config, line)) {
                line = strip(line);
                if (line[0] == 35 || !line[0])
                    continue;
                else if (first_token(line) == "include")
                    Include(line, parsed_content);
                else
                    parsed_content.push_back(line);
            }
            config.close();
        }
        else {
            cerr << "webserv: Include: file does not exists" << endl;
        }
    }
}

// Http ----------------------------------------------------------------------->

Http::Http(string context) {
    vector<Directive *> value;

    if (context != "main")
        throw WrongContextExc("Http", "main", context);
    this->_type = "http";
    this->_is_context = true;
    this->_value_block = value;
}

Http::Http(ifstream &raw_value, string context) {
    if (context != "main")
        throw WrongContextExc("Http", "main", context);
    this->_type = "http";
    this->_is_context = true;
    this->_parsing_block(raw_value);
}

Http::~Http() {
    for (VecDirIt it = this->_value_block.begin(); 
        it != this->_value_block.end(); ++it)
        delete *it;
}

// Server --------------------------------------------------------------------->

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

// Location ------------------------------------------------------------------->

// <...>

// LimitExcept ---------------------------------------------------------------->

// <...>

// Listen --------------------------------------------------------------------->

Listen::Listen(string context) {
    vector<string> value;

    if (context != "server")
        throw WrongContextExc("Listen", "server", context);
    this->_type = "listen";
    this->_is_context = false;
    this->_value_inline = value;
}

Listen::Listen(string raw_value, string context) {
    if (context != "server")
        throw WrongContextExc("Listen", "server", context);
    this->_type = "listen";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Listen::~Listen() {}

// Root ----------------------------------------------------------------------->

Root::Root(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("Root", "http|server|location", context);
    this->_type = "root";
    this->_is_context = false;
    this->_value_inline = value;
}

Root::Root(string raw_value, string context) {
    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc("Root", "http|server|location", context);
    this->_type = "root";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Root::~Root() {}

// ServerName ----------------------------------------------------------------->

ServerName::ServerName(string context) {
    vector<string> value;

    if (context != "server")
        throw WrongContextExc("ServerName", "server", context);
    this->_type = "server_name";
    this->_is_context = false;
    this->_value_inline = value;
}

ServerName::ServerName(string raw_value, string context) {
    if (context != "server")
        throw WrongContextExc("ServerName", "server", context);
    this->_type = "server_name";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

ServerName::~ServerName() {}

// ErrorPage ------------------------------------------------------------------>

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

// ClientMaxBodySize ---------------------------------------------------------->

ClientMaxBodySize::ClientMaxBodySize(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc(
            "ClientMaxBodySize", "http|server|location", context);
    this->_type = "client_max_body_size";
    this->_is_context = false;
    this->_value_inline = value;
}

ClientMaxBodySize::ClientMaxBodySize(string raw_value, string context) {
    if (context != "http" && context != "server" && context != "location")
        throw WrongContextExc(
            "ClientMaxBodySize", "http|server|location", context);
    this->_type = "client_max_body_size";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

ClientMaxBodySize::~ClientMaxBodySize() {}

// Alias ---------------------------------------------------------------------->

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

// Index ---------------------------------------------------------------------->

Index::Index(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location") 
        throw WrongContextExc("Index", "http|server|location", context);
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

// Autoindex ------------------------------------------------------------------>

Autoindex::Autoindex(string context) {
    vector<string> value;

    if (context != "http" && context != "server" && context != "location") 
        throw WrongContextExc("Autoindex", "http|server|location", context);
    this->_type = "autoindex";
    this->_is_context = false;
    this->_value_inline = value;
}

Autoindex::Autoindex(string raw_value, string context) {
    if (context != "http" && context != "server" && context != "location") 
        throw WrongContextExc("Autoindex", "http|server|location", context);
    this->_type = "autoindex";
    this->_is_context = false;
    this->_parsing_inline(raw_value);
}

Autoindex::~Autoindex() {}
