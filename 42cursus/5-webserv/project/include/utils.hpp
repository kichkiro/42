/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:42:41 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/25 12:33:18 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using std::string;

// Functions ------------------------------------------------------------------>

bool str_in_array(const char *str, const char **arr);
string strip(const string &str);
string first_token(const string &str);
string second_token(const string &str);
