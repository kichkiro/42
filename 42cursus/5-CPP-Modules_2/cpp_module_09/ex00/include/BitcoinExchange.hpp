/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:33:06 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 14:07:55 by kichkiro         ###   ########.fr       */
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
using std::ostringstream;

typedef std::map<std::string, std::string>::iterator map_it;

// Class ---------------------------------------------------------------------->

class BitcoinExchange {
    private:
        map<string, double> _database;
        map<string, double> _inputfile;

        void _set_database(string filename);
        void _set_inputfile(string filename);
        bool _check_date(string date);
        string _decrement_date(const string &date);
        double _calculate(string key, double value);

    public:        
        BitcoinExchange(string database, string inputfile);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rs);
        ~BitcoinExchange(void);
};
