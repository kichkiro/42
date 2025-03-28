/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:33:06 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 16:19:12 by kichkiro         ###   ########.fr       */
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
    private:
        stack<int> _stack_operand;
        
        int  _str_to_int(const string &str);
        void _process_token(const string &token);

    public:
        RPN(const string &exp);
        RPN(const RPN &src);
        RPN &operator=(const RPN &rs);
        ~RPN(void);

        int evaluate(void);
};
