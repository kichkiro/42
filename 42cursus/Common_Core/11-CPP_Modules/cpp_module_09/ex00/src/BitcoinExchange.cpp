/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/15 14:01:35 by kichkiro         ###   ########.fr       */
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
            cout << key << " => " << value << " = " << 
                this->_calculate(key, value) << endl;
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
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        max_days_in_month = 29;
    return (day <= max_days_in_month);
}

double BitcoinExchange::_calculate(string key, double value) {
    while (this->_database.find(key) == this->_database.end()) {
        key = this->_decrement_date(key);
        if (key < this->_database.begin()->first) {
            key = this->_database.begin()->first;
            break;
        }
    }
    return this->_database[key] * value;
}

string BitcoinExchange::_decrement_date(const string &date) {
    istringstream iss(date);
    int year, month, day;
    char dash1, dash2;

    iss >> year >> dash1 >> month >> dash2 >> day;
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        int last_day_of_prev_month = 31;
        day = last_day_of_prev_month;
    }
    ostringstream oss;
    oss << year << '-' << (month < 10 ? "0" : "") << month << '-'
        << (day < 10 ? "0" : "") << day;
    return oss.str();
}
