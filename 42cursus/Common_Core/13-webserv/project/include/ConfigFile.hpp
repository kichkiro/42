/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:46:15 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 16:59:55 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include "webserv.h"

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

        vector<Directive *> get_config(void);
};
