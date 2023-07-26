/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:18:23 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/26 09:36:23 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// SFM ------------------------------------------------------------------------>

Animal::Animal(void) : _type("") {
    cout << "Animal      - Default Constructor" << endl;
}

Animal::Animal(const Animal &src) {
    cout << "Animal      - Default Copy Constructor" << endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &rs) {
    cout << "Animal      - Default Assignment Operator" << endl;
    if (this != &rs)
        this->_type = rs._type;
    return *this;
}

Animal::~Animal(void) {
    cout << "Animal      - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

string Animal::getType(void) const {
    return this->_type;
}

void Animal::makeSound(void) const {}
