/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 16:29:46 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const string &exp) {
    istringstream iss(exp);
    string token;

    while (iss >> token)
        this->_process_token(token);
}

RPN::RPN(const RPN &src) {
    *this = src;
}

RPN &RPN::operator=(const RPN &rs) {
    this->_stack_operand = rs._stack_operand;
    return *this;
}

RPN::~RPN(void) {}

int RPN::evaluate(void) {
    if (this->_stack_operand.size() != 1)
        throw invalid_argument("Invalid expression");
    return this->_stack_operand.top();
}

int RPN::_str_to_int(const string &str) {
    istringstream iss(str);
    int result;

    iss >> result;
    return result;
}

void RPN::_process_token(const string &token) {
    int operand1;
    int operand2;

    if (isdigit(token[0]))
        this->_stack_operand.push(this->_str_to_int(token));
    else if (token == "+" || token == "-" || token == "*" || token == "/") {
        operand2 = this->_stack_operand.top();
        this->_stack_operand.pop();
        operand1 = this->_stack_operand.top();
        this->_stack_operand.pop();
        if (token == "+")
            this->_stack_operand.push(operand1 + operand2);
        else if (token == "-")
            this->_stack_operand.push(operand1 - operand2);
        else if (token == "*")
            this->_stack_operand.push(operand1 * operand2);
        else if (token == "/") {
            if (operand2 == 0)
                throw invalid_argument("Division by zero");
            this->_stack_operand.push(operand1 / operand2);
        }
    }
    else
        throw invalid_argument("Error");
}
