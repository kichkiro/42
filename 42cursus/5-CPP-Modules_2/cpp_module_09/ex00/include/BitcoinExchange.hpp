/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:33:06 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/12 13:31:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <map>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::ifstream;
using std::istringstream;
using std::getline;
using std::tm;

typedef std::map<std::string, std::string>::iterator MapIt;

// Class ---------------------------------------------------------------------->

class BitcoinExchange {
    public:        
        BitcoinExchange(string database, string inputfile);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rs);
        ~BitcoinExchange(void);
    private:
        map<string, double> _database;
        map<string, double> _inputfile;

        void _set_database(string filename);
        void _set_inputfile(string filename);
        bool _check_date(string date);
        double _calculate(string key, double value);
};
