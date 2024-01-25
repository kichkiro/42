/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:15:39 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/25 12:33:23 by kichkiro         ###   ########.fr       */
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
        cerr << "webserv: Directive: syntax error" << endl;
}

// Include -------------------------------------------------------------------->

Include::Include(string raw_value, vector<string> &parsed_content) {
    this->_type == "include";
    this->_is_context = false;
    this->_ptr_parsed_content = &parsed_content;
    this->_pre_parsing(raw_value);
}

Include::~Include() {}

/*!
 * @brief 
    This function performs pre-parsing on the given raw_value, extracting 
    configuration file paths, and calling the _parsing function to parse each 
    configuration file.
 * @param raw_value 
    The input string containing raw configuration information.
 */
void Include::_pre_parsing(string raw_value) {
    vector<string> configs;
    string         path;
    DIR            *dir;
    struct dirent  *entry;
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
        this->_parsing(config);
    }
}

/*!
 * @brief 
    This function reads and processes the content of the input file stream, 
    extracting relevant information.
    It identifies and handles "include" directives, updating the parsed content 
    accordingly.
 * @param raw_value 
    An input file stream representing the configuration content to be parsed.
 */
void Include::_parsing(ifstream &raw_value) {
    string line;

    if (raw_value.is_open()) {
        while (getline(raw_value, line)) {
            line = strip(line);
            if (line[0] == 35 || !line[0])
                continue;
            else if (first_token(line) == "include")
                Include(line, *this->_ptr_parsed_content);
            else
                this->_ptr_parsed_content->push_back(line);
        }
        raw_value.close();
    }
    else {
        cerr << "webserv: Include: file does not exists." << endl;
    }
}

// Http ----------------------------------------------------------------------->

Http::Http(string context) {
    vector<Directive *> value;

    if (context != "main") {
        cerr << "webserv: Http: http context can be used only in: main" << endl;
        // Exit
    }
    this->_type == "http";
    this->_is_context = true;
    this->_value = value;
}

Http::Http(ifstream &raw_value, string context) {
    if (context != "main") {
        cerr << "webserv: Http: http directive can be used only in main context" 
            << endl;
        // Exit
    }
    this->_type == "http";
    this->_is_context = true;
    this->_parsing(raw_value);
}

Http::~Http() {
    for (VecDirIt it = _value.begin(); it != _value.end(); ++it)
        delete *it;
}

void Http::_parsing(ifstream &raw_value) {
    streampos prev_pos;
    string    line, token;
    int       brackets;

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

