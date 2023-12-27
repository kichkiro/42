/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:29:10 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/27 14:13:56 by kichkiro         ###   ########.fr       */
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
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &rs);
		~Serializer();
};
