/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:34:02 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/28 15:45:50 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::exception;

// Templates ------------------------------------------------------------------>

template <typename T>
class Array {
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &src);
        Array &operator=(const Array &rs);
        T &operator[](size_t index);
        ~Array();

        size_t size(void) const;

        class OutOfRangeException : public exception {
            public:
                virtual const char* what() const throw() {
                    return "Index out of range";
                }
        };

    private:
        T *_arr;
        size_t _size;
};

#include "Array.tpp"
