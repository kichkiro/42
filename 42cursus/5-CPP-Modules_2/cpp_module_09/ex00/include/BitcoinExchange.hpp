/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:33:06 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/11 17:06:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::ifstream;
using std::istringstream;
using std::getline;

typedef std::map<std::string, std::string>::iterator MapIt;

// Class ---------------------------------------------------------------------->

class BitcoinExchange {
    public:        
        BitcoinExchange(string database, string inputfile);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rs);
        ~BitcoinExchange(void);

        void calculate(void);

    private:
        map<string, string> _database;
        map<string, int>    _inputfile;

        void _set_database(string filename);
        void _set_inputfile(string filename);
};
