/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:29:28 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 12:48:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <climits>
#include <limits>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;
using std::isprint;
using std::numeric_limits;

// Classes -------------------------------------------------------------------->

class ScalarConverter {
    private:
        static char   _char;
        static int    _int;
        static float  _float;
        static double _double;
        static int    _precision;

        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &rs);
        ~ScalarConverter();

        static bool _is_pseudo_literal(string input);
        static bool _is_char(string input);
        static bool _is_int(string input);
        static bool _is_floatdouble(string input);
        static void _caster(string type);
        static void _display(bool is_pseudo_literal, bool is_strange_value);

    public:
        static void convert(string input);
};
