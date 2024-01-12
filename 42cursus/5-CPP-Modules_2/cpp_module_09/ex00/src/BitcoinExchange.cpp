/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/12 14:04:53 by kichkiro         ###   ########.fr       */
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
        string key;
        double value;
        istringstream iss(line);
        getline(iss, key, ',');
        iss >> value;
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

    getline(file, line);
    while (getline(file, line)) {
        string key;
        double value;
        istringstream iss(line);
        getline(iss, key, '|');
        if (!(iss >> value) || !this->_check_date(key))
            cerr << "Error: bad input => " << key << endl;
        else if (value < 0)
            cerr << "Error: not a positive number." << endl;
        else if (value > 1000)
            cerr << "Error: too large a number." << endl;
        else {
            key.erase(key.end() - 1);
            this->_inputfile[key] = value;
            cout << key << "=> " << value << " = " << this->_calculate(key, value) << endl;
        }
    }
    file.close();
}

bool BitcoinExchange::_check_date(string date) {
    istringstream ss(date);
    int year, month, day;
    char dash1, dash2;

    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    static const int days_in_month[] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    int max_days_in_month = days_in_month[month];
    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
        max_days_in_month = 29;
    return (day <= max_days_in_month);
}

double BitcoinExchange::_calculate(string key, double value) {
    if (_database.find(key) != _database.end()) {
        double value = _database[key];
        return value;
    }
    else {
        // cercare la prima data antecedente presente nel db.

        return 42;
    }
}

