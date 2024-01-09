/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:16:19 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/09 12:33:47 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int limit) : _limit(limit) {}

Span::Span(const Span &src) : _vec(src._vec), _limit(src._limit) {}

Span &Span::operator=(const Span &rs) {
    if (this != &rs) {
        this->_vec = rs._vec;
        this->_limit = rs._limit;
    }
    return *this;
}

Span::~Span(void) {}

void Span::addNumber(int n) {
    if (this->_vec.size() < this->_limit)
        this->_vec.push_back(n);
    else
        throw Span::FullException();
}

void Span::addNumbers(VecIterator begin, VecIterator end) {
    while (begin != end) {
        this->addNumber(*begin);
        ++begin;
    }
}

int Span::shortestSpan(void) {
    vector<int> diff_vec;

    if (this->_vec.size() < 2)
        throw Span::FewNumberException();
    for (long unsigned int i = 0; i < this->_vec.size() - 1; i++) {
        diff_vec.push_back(abs(_vec[i] - _vec[i + 1]));
    }
    sort(diff_vec.begin(), diff_vec.end());
    return diff_vec[0];
}

int Span::longestSpan(void) {
    vector<int> diff_vec;

    if (this->_vec.size() < 2)
        throw Span::FewNumberException();
    for (long unsigned int i = 0; i < this->_vec.size() - 1; i++) {
        diff_vec.push_back(abs(_vec[i] - _vec[i + 1]));
    }
    sort(diff_vec.begin(), diff_vec.end());
    return diff_vec.back();
}
