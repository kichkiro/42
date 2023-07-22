/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:02:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/21 17:52:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// SFM ------------------------------------------------------------------------>

Dog::Dog(void) : _type("Dog") {
    cout << "Dog - Default Constructor" << endl;
}

Dog::Dog(const Dog &src) {
    cout << "Dog - Default Copy Constructor" << endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &rs) {
    cout << "Dog - Default Assignment Operator" << endl;
    if (this != &rs)
        this->_type = rs._type;
    return *this;
}

Dog::~Dog(void) {
    cout << "Dog - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

string Dog::getType(void) const {
    Animal::getType();
    return this->_type;
}

void Dog::makeSound(void) const {
    Animal::makeSound();
    cout << "Woof woof!" << endl;
}
