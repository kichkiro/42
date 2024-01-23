/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:46:32 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/23 17:16:16 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigFile.hpp"

const char *directives2[] = {
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

/*
this->_config_file deve contenere tutte le direttive parsate


*/

ConfigFile::ConfigFile(void) {
    this->_parse("etc/webserv/webserv.conf");
}

ConfigFile::ConfigFile(const char *filename) {
    this->_parse(filename);
}

ConfigFile::~ConfigFile(void) {}

void ConfigFile::_parse(const char *filename) {
    ifstream file(filename);
    string   line;

    if (!file.is_open()) {
        cerr << "Error: ConfigFile: file does not exists." << endl;
        // Return an error code
    }
    while (getline(file, line)) {
        string result = line.substr(0, line.find_first_of(" \t"));
        // int brackets = 0;
        
        if (result[0] == 35 || !result[0])
            continue;
        else if (str_in_array(result.c_str(), directives2)) {
            // -----------------------------------------------------------------
            // aggiungi la direttiva a this->_config_file
            
            cout << endl;
            // Directive::router(this->_config_file, "main", result, file);

            // if (result == "http")
            //     this->_config_file.push_back(new Http(file, "main"));

            // -----------------------------------------------------------------
            
            // salta fino alla chiusura del blocco se la direttiva e' un contesto
            
            // QUESTO POSSIAMO FARLO NELLE CLASSI Directive INQUANTO IFSTREAM 
            // HA MEMORIA DELLA POSIZIONE CORRENTE SE PASSATO PER RIFERIMENTO
            // while (getline(file, line)) {
            //     string result2 = line.substr(0, line.find_first_of(" \t"));
                
            //     if (result2[0] == 35)
            //         continue;
            //     else if (line.find_first_of("{") != string::npos)
            //         brackets++;
            //     else if (line.find_first_of("}") != string::npos)
            //         brackets--;
            //     if (brackets == -1)
            //         break;
            // }
            // -----------------------------------------------------------------
        }
        else {
            cerr << "Error: ConfigFile: sysntax error." << endl;
            // Return an error code
        }
    }
    file.close();
    // assign this->_config_file
}
