/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:46:32 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/18 16:30:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigFile.hpp"

ConfigFile::ConfigFile(void) {
    ifstream configfile("etc/webserv/webserv.conf");

}

ConfigFile::ConfigFile(const char *filename) {
    ifstream configfile(filename);
    
}

ConfigFile::~ConfigFile(void) {}
