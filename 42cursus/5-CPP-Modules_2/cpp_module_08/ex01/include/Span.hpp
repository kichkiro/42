/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:16:22 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/09 13:11:47 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <cmath>
#include <vector>
#include <algorithm>

using std::abs;
using std::sort;
using std::vector;
using std::exception;

typedef std::vector<int>::const_iterator VecIterator;

// Class ---------------------------------------------------------------------->

class Span {
    public:
        Span(unsigned int limit);
        Span(const Span &src);
        Span &operator=(const Span &rs);
        ~Span(void);

        void addNumber(int n);
        void addNumbers(VecIterator begin, VecIterator end);
        int shortestSpan(void);
        int longestSpan(void);

        class FullException : public exception {
            const char *what(void) const throw() {return "Container is Full!";}
        };
        
        class FewNumberException : public exception {
            const char *what(void) const throw() {return "Few Numbers!";}
        };
        
    private:
        vector<int>  _vec;
        unsigned int _limit;
};
