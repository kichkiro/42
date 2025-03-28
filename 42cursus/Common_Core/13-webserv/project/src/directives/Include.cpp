/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Include.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:46:47 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:46:57 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include.hpp"

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
    DIR *dir;
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
