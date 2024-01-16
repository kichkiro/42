/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/15 14:03:00 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &src) {
    *this = src;
}

RPN &RPN::operator=(const RPN &rs) {
    return *this;
}

RPN::~RPN(void) {}
