/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:16:19 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 11:19:53 by kichkiro         ###   ########.fr       */
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

int Span::shortestSpan(void) {
    vector<int> diff_vec;

    if (this->_vec.size() < 2)
        throw Span::FewNumberException();
    for (long unsigned int i = 0; i < this->_vec.size() - 1; i++)
        diff_vec.push_back(abs(_vec[i] - _vec[i + 1]));
    sort(diff_vec.begin(), diff_vec.end());
    return diff_vec[0];
}

// int Span::longestSpan(void) {
//     vector<int> diff_vec;

//     if (this->_vec.size() < 2)
//         throw Span::FewNumberException();
//     for (long unsigned int i = 0; i < this->_vec.size() - 1; i++)
//         diff_vec.push_back(abs(_vec[i] - _vec[i + 1]));
//     sort(diff_vec.begin(), diff_vec.end());
//     return diff_vec.back();
// }

// int Span::shortestSpan(void) {
//     if (this->_vec.size() < 2)
//         throw Span::FewNumberException();

//     std::vector<int> sortedVec = _vec;
//     std::sort(sortedVec.begin(), sortedVec.end());

//     int minSpan = INT_MAX;
//     for (size_t i = 1; i < sortedVec.size(); ++i) {
//         int span = sortedVec[i] - sortedVec[i - 1];
//         minSpan = std::min(minSpan, span);
//     }

//     return minSpan;
// }

int Span::longestSpan(void) {
    if (this->_vec.size() < 2)
        throw Span::FewNumberException();

    int maxElement = *std::max_element(_vec.begin(), _vec.end());
    int minElement = *std::min_element(_vec.begin(), _vec.end());

    return maxElement - minElement;
}

const char *Span::FullException::what(void) const throw() {
    return "Container is Full!";
}

const char *Span::FewNumberException::what(void) const throw() {
    return "Few Numbers!";
}
