/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:46:15 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/24 16:32:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Directives.hpp"
#include "utils.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::getline;

// Class ---------------------------------------------------------------------->

class ConfigFile {
    private:
        vector<Directive *> _config_file;

        void _first_parsing(const char *filename);
        void _parsing(const char *filename);

    public:
        ConfigFile(void);
        ConfigFile(const char *filename);
        ~ConfigFile(void);

        // vector<Directive> get_config_file(void);
};
