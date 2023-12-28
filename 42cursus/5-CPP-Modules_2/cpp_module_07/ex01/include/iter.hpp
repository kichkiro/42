/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:34:02 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/28 11:10:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <string>

using std::cout;
using std::endl;

// Templates ------------------------------------------------------------------>

template<typename T, typename Func>
void iter(T *array, size_t length, Func function) {
    for (size_t i = 0; i < length; ++i)
        function(array[i]);
}

template<typename T>
void print_item(const T &item) {
    cout << item << " ";
}
