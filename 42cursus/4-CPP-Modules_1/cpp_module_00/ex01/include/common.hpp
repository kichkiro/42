/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:52:04 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/12 17:30:18 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <iomanip>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::left;

// Macros --------------------------------------------------------------------->

#define RESET 		"\033[0m"
#define RED_B 		"\033[1;31m"
#define BLUE_B 		"\033[1;34m"
#define YELLOW_B	"\033[1;33m"
#define WHITE_B		"\033[1;37m"
