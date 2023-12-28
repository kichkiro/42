/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:23:56 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/28 15:44:46 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &src) : _arr(new T[src._size]), _size(src._size) {
    for (size_t i = 0; i < src._size; i++)
        this->_arr[i] = src._arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rs) {
    if (&rs != this) {
        delete[] this->_arr;
        this->_size = rs._size;
        this->_arr = new T[this->_size];
        for (size_t i = 0; i < this->_size; i++)
            this->_arr[i] = rs._arr[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](size_t i) {
    if (i >= this->_size)
        throw OutOfRangeException();
    return this->_arr[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] this->_arr;
}

template <typename T>
size_t Array<T>::size(void) const {
    return this->_size;
}
