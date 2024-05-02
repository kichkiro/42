/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:29:10 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 12:53:16 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------> 

#include <string>
#include <iostream>
 #include <stdint.h>

#include <Data.hpp>

using std::cout;
using std::endl;

// Class ---------------------------------------------------------------------->

class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &rs);
		~Serializer();

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
