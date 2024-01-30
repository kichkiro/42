/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:46:15 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/30 16:54:54 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <exception>

#include "Directives.hpp"
#include "utils.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::remove;
using std::ofstream;
using std::runtime_error;

// Class ---------------------------------------------------------------------->

class ConfigFile {
    private:
        typedef vector<Directive *>::iterator VecDirIt;
        
        vector<Directive *> _config;

        void _first_parsing(const char *filename);
        void _parsing(const char *tmp_file);

    public:
        ConfigFile(void);
        ConfigFile(const char *filename);
        ~ConfigFile(void);

        // vector<Directive> get_config_file(void);
};
