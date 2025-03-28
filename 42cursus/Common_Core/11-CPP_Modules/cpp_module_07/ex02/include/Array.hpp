/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:34:02 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:36:26 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::exception;

// Templates ------------------------------------------------------------------>

template <typename T>
class Array {
    private:
        T *_arr;
        size_t _size;

    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &src);
        Array &operator=(const Array &rs);
        T &operator[](size_t index);
        ~Array();

        size_t size(void) const;

        class OutOfRangeException : public exception {
            virtual const char* what() const throw() {
                return "Index out of range";
            }
        };
};

#include "Array.tpp"
