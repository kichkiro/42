/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:02:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/25 19:54:50 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// SFM ------------------------------------------------------------------------>

Dog::Dog(void) {
    cout << "Dog         - Default Constructor" << endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
    cout << "Dog         - Default Copy Constructor" << endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &rs) {
    cout << "Dog         - Default Assignment Operator" << endl;
    if (this != &rs)
        this->_type = rs._type;
    return *this;
}

Dog::~Dog(void) {
    cout << "Dog         - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void Dog::makeSound(void) const {
    Animal::makeSound();
    cout << "Woof woof!" << endl;
}
