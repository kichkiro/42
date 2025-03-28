/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:16:19 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 13:15:42 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _limit(1) {}

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

void Span::addNumbers(vec_it begin, vec_it end) {
    while (begin != end) {
        this->addNumber(*begin);
        ++begin;
    }
}

int Span::shortestSpan() {
    int shortest;

    if (this->_vec.size() < 2)
        throw Span::FewNumberException();
    sort(this->_vec.begin(), this->_vec.end());
    shortest = this->_vec[1] - this->_vec[0];
    for (size_t i = 2; i < this->_vec.size(); ++i)
        shortest = min(shortest, this->_vec[i] - this->_vec[i - 1]);
    return shortest;
}

int Span::longestSpan(void) {
    vec_it min_it, max_it;

    if (this->_vec.size() < 2)
        throw Span::FewNumberException();
    min_it = min_element(this->_vec.begin(), this->_vec.end());
    max_it = max_element(this->_vec.begin(), this->_vec.end());
    return *max_it - *min_it;
}

vector<int> Span::get_vec(void) {
    return this->_vec;
}

unsigned int Span::get_limit(void) {
    return this->_limit;
}

// Exceptions ----------------------------------------------------------------->

const char *Span::FullException::what(void) const throw() {
    return "Container is Full!";
}

const char *Span::FewNumberException::what(void) const throw() {
    return "Few Numbers!";
}
