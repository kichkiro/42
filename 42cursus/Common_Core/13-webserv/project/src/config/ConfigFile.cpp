/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:46:32 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 11:29:56 by kichkiro         ###   ########.fr       */
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
    for (VecDirIt it = _config.begin(); it != _config.end(); ++it)
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
    vector<string> parsed_content;
    ifstream       input_file;
    ofstream       tmp_file;
    string         line, token, tmp_filename;

    input_file.open(filename);
    if (!input_file.is_open()) {
        cerr << "webserv: ConfigFile: file does not exists" << endl;
        throw runtime_error("");
    }
    while (getline(input_file, line)) {
        line = strip(line);
        if (line[0] == 35 || !line[0])
            continue;
        else if (first_token(line) == "include")
            Include(line, parsed_content);
        else
            parsed_content.push_back(line);
    }
    input_file.close();
    tmp_filename = ".configfile.tmp";
    tmp_file.open(tmp_filename.c_str());
    if (!tmp_file.is_open()) {
        cerr << "webserv: ConfigFile: could not create temporary file" << endl;
        remove(tmp_filename.c_str());
        throw runtime_error("");
    }
    for (size_t i = 0; i < parsed_content.size(); ++i)
        tmp_file << parsed_content[i] << endl;
    tmp_file.close();
    this->_parsing(tmp_filename.c_str());
}

void ConfigFile::_parsing(const char *config_file) {
    ifstream  file;
    string    line, token;

    file.open(config_file);
    if (!file.is_open()) {
        cerr << "webserv: ConfigFile: file does not exists" << endl;
        remove(config_file);
        throw runtime_error("");
    }
    while (getline(file, line)) {
        token = first_token(strip(line));
        if (str_in_array(token.c_str(), Directive::_directives))
            Directive::router(this->_config, "main", token, line, file);
        else {
            cerr << "webserv: ConfigFile: \"" << token << 
                "\" directive does not exists" << endl;
            remove(config_file);
            throw runtime_error("");
        }
    }
    file.close();
    remove(config_file);
}

vector<Directive *> ConfigFile::get_config(void) {
    return this->_config;
}
