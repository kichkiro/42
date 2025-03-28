/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:16:22 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 13:57:11 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <vector>
#include <algorithm>

using std::max_element;
using std::min_element;
using std::min;
using std::sort;
using std::vector;
using std::exception;

typedef std::vector<int>::iterator vec_it;

// Class ---------------------------------------------------------------------->

class Span {
    private:
        vector<int>  _vec;
        unsigned int _limit;

    public:
        Span(void);
        Span(unsigned int limit);
        Span(const Span &src);
        Span &operator=(const Span &rs);
        ~Span(void);

        void addNumber(int n);
        void addNumbers(vec_it begin, vec_it end);
        int shortestSpan(void);
        int longestSpan(void);

        vector<int> get_vec(void);
        unsigned int get_limit(void);

        class FullException : public exception {
            const char *what(void) const throw();
        };
        
        class FewNumberException : public exception {
            const char *what(void) const throw();
        };
};
