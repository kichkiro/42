/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:33:06 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/17 10:12:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stack;
using std::istringstream;
using std::exception;
using std::invalid_argument;

// Class ---------------------------------------------------------------------->

class RPN {
    public:
        RPN(const string &exp);
        RPN(const RPN &src);
        RPN &operator=(const RPN &rs);
        ~RPN(void);

        int evaluate(void);

    private:
        stack<int> _stack_operand;
        
        int  _str_to_int(const string &str);
        void _process_token(const string &token);
};
