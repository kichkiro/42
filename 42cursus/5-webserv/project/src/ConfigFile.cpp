/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:46:32 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/24 16:46:36 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigFile.hpp"

ConfigFile::ConfigFile(void) {
    this->_first_parsing("etc/webserv/webserv.conf");
}

ConfigFile::ConfigFile(const char *filename) {
    this->_first_parsing(filename);
}

ConfigFile::~ConfigFile(void) {
    typedef vector<Directive*>::iterator IT;
    for (IT it = _config_file.begin(); it != _config_file.end(); ++it)
        delete *it;
}

/*!
 * @brief 
    This method provides in creating a temporary file where the output of an 
    initial parsing will be written, which consists of:
    - deleting comments.
    - deleting blank lines.
    - include the files in the include directive.    
 */
void ConfigFile::_first_parsing(const char *filename) {
    // tmp file
    // 
    vector<string> parsed_content;
    ifstream       file(filename);
    string         line, token;

    if (!file.is_open()) {
        cerr << "Error: ConfigFile: file does not exists." << endl;
        // Return an error code
    }
    while (getline(file, line)) {
        line = strip(line);
        if (line[0] == 35 || !line[0])
            continue;
        else if (first_token(line) == "include")
            Include(line, parsed_content);
        else
            parsed_content.push_back(line);
    }
    file.close();
    // create tmp file and insert parsed_content on it.
}

void ConfigFile::_parsing(const char *filename) {
    ifstream file(filename);
    streampos prev_pos;
    string   line, token;

    prev_pos = file.tellg();
    if (!file.is_open()) {
        cerr << "Error: ConfigFile: file does not exists." << endl;
        // Return an error code
    }
    while (getline(file, line)) {
        token = first_token(strip(line));

        if (token[0] == 35 || !token[0]) {
            prev_pos = file.tellg();
            continue;
        }
        else if (str_in_array(token.c_str(), Directive::_directives)) {
            // cout << "configfile: " << token << endl;
            Directive::router(this->_config_file, "main", token, prev_pos, file);
        }
        else {
            cerr << "Error: ConfigFile: sysntax error." << endl;
            // Return an error code
        }
        prev_pos = file.tellg();
    }
    file.close();
    // assign this->_config_file
}
