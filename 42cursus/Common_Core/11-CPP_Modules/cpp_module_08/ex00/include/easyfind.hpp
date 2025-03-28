/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:16:56 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 10:27:00 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <algorithm>
#include <exception>

using std::runtime_error;

// Templates ------------------------------------------------------------------>

template <typename T>
typename T::iterator easyfind(T &container, int val);

#include "easyfind.tpp"
