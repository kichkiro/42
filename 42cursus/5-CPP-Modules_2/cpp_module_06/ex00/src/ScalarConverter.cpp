/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:57:28 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/15 15:15:38 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char   ScalarConverter::_char;
int    ScalarConverter::_int;
float  ScalarConverter::_float;
double ScalarConverter::_double;
int    ScalarConverter::_precision = 1;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rs) {
    _char = rs._char;
    _int = rs._int;
    _float = rs._float;
    _double = rs._double;
    _precision = rs._precision;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::_is_char(string input) {
    if (input.find("'") != string::npos && input.find("'", 1) == 2) {
        _char = input[1];
        return true;
    }
    return false;
}

bool ScalarConverter::_is_pseudo_literal(string input) {
    if (input == "+inff" || input == "+inf") {
        _float = numeric_limits<float>::infinity();
        _double = numeric_limits<double>::infinity();
    }
    else if (input == "-inff" || input == "-inf") {
        _float = -numeric_limits<float>::infinity();
        _double = -numeric_limits<double>::infinity();
    }
    else if (input == "nanf" || input == "nan") {
        _float = numeric_limits<float>::quiet_NaN();
        _double = numeric_limits<double>::quiet_NaN();
    }
    else
        return false;
    _precision = 0;
    return true;
}

bool ScalarConverter::_is_int(string input) {
    size_t i;

    i = 0;
    if (input[0] == '-')
        i++;
    if (input.length() == 1 && input[0] == '0') {
        _int = 0;
        return true;
    }
    for (; i < input.length(); i++) {
        if (input[i] < '0' || input[i] > '9')
            return false;
    }
    _int = atoi(input.c_str());
    return true;
}

bool ScalarConverter::_is_floatdouble(string input) {
    size_t i;

    i = 0;
    if (input[0] == '-')
        i++;
    while (input[i] != '.')
        i++;
    if (input[i] == '.')
        i++;
    else
        return false;
    while (input[i] >= '0' && input[i] <= '9') {
        _precision++;
        i++;
    }
    _precision--;
    if ((input[i] == 'f' && i + 1 == input.length()) || i == input.length()) {
        _float = atof(input.c_str());
        _double = atof(input.c_str());
        return true;
    }
    return false;
}

void ScalarConverter::_caster(string type) {
    if (type == "char") {
        _int = static_cast<int>(_char);
        _float = static_cast<float>(_char);
        _double = static_cast<double>(_char);
    }
    else if (type == "int") {
        _char = static_cast<char>(_int);
        _float = static_cast<float>(_int);
        _double = static_cast<double>(_int);
    }
    else if (type == "floatdouble") {
        _int = static_cast<int>(_float);
        _char = static_cast<char>(_float);
    }
}

void ScalarConverter::_display(bool is_pseudo_literal, bool is_strange_value) {
    if (is_pseudo_literal || is_strange_value) {
        cout << "char: impossible" << endl;
        cout << "int: impossible" << endl;
        if (is_strange_value) {
            cout << "float: impossible" << endl;
            cout << "double: impossible" << endl;
        }
    }
    else {
        if (isprint(_char))
            cout << "char: " << _char << endl;
        else
            cout << "char: Non displayable" << std::endl;
        if (_int < INT_MIN || _int > INT_MAX)
            cout << "int: impossible";
        else
            cout << "int: " << _int << endl;
    }
    if (!is_strange_value) {
        cout << "float: " << fixed << setprecision(_precision) << _float << "f"
            << endl;
        cout << "double: " << fixed << setprecision(_precision) << _double
            << endl;
    }
}

void ScalarConverter::convert(string input) {
    if (_is_pseudo_literal(input)) {
        _display(true, false);
        return;
    }
    if (_is_char(input))
        _caster("char");
    else if (_is_int(input))
        _caster("int");
    else if (_is_floatdouble(input))
        _caster("floatdouble");
    else {
        _display(false, true);
        return;
    }
    _display(false, false);
}
