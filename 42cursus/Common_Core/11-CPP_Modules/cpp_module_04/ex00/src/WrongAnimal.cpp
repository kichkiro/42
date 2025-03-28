/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:04:42 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/25 19:46:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// SFM ------------------------------------------------------------------------>

WrongAnimal::WrongAnimal(void) : _type("") {
    cout << "WrongAnimal - Default Constructor" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
    cout << "WrongAnimal - Default Copy Constructor" << endl;
    *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rs) {
    cout << "WrongAnimal - Default Assignment Operator" << endl;
    if (this != &rs)
        this->_type = rs._type;
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    cout << "WrongAnimal - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

string WrongAnimal::getType(void) const {
    return this->_type;
}

void WrongAnimal::makeSound(void) const {}
