/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:34:02 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/28 09:58:58 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Templates ------------------------------------------------------------------>

template <typename T>
void swap(T &a, T &b) {
    T c;
    c = b;
    b = a;
    a = c;
}

template <typename T>
T min(T &a, T &b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(T &a, T &b) {
    return (a > b) ? a : b;
}
