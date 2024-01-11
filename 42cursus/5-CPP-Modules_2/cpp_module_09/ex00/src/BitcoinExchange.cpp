/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/11 17:10:00 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(string database_path, string inputfile_path) {
    this->_set_database(database_path);
    this->_set_inputfile(inputfile_path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rs) {
    this->_database = rs._database;
    this->_inputfile = rs._inputfile;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::_set_database(string filename) {
    ifstream file;
    string line;

    file.open(filename.c_str());

    while (getline(file, line)) {
        string key, value;
        istringstream iss(line);
        getline(iss, key, ',');
        getline(iss, value, ',');
        this->_database[key] = value;
    }
    file.close();
    // for (MapIt it = this->_database.begin(); it != this->_database.end(); ++it) {
    //     cout << "Key: " << it->first << ", Value: " << it->second << endl;
    // }
}

void BitcoinExchange::_set_inputfile(string filename) {
    string line;
    ifstream file(filename.c_str());
    
    while (getline(file, line)) {
        istringstream iss(line);
        string date;
        double value;
        if (!(iss >> date >> value)) {
            cerr << "Error parsing date or value: " << line << endl;
            continue;
        }
        if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
            cerr << "Invalid date format: " << date << endl;
            continue;
        }
        this->_inputfile[date] = value;
    }
    file.close();


}


void BitcoinExchange::calculate(void) {
    cout << endl;
}
