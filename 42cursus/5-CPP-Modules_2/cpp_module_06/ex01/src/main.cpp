/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:29:27 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/27 15:24:01 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
	Data*		ptr;
	uintptr_t   integer;

	ptr = new Data;
	integer = Serializer::serialize(ptr);
    
	cout << "ptr addr:    " << ptr << endl;
	cout << "serialize:   " << integer << endl;
	cout << "deserialize: " << Serializer::deserialize(integer) << endl;

	delete ptr;

	return 0;
}
