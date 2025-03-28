/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:02:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 07:46:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// SFM ------------------------------------------------------------------------>

Dog::Dog(void) : _dog_brain(new Brain()) {
    cout << "Dog         - Default Constructor" << endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
    cout << "Dog         - Default Copy Constructor" << endl;
    this->_type = src._type;
    this->_dog_brain = new Brain(*src._dog_brain);
}

Dog &Dog::operator=(const Dog &rs) {
    cout << "Dog         - Default Assignment Operator" << endl;
    if (this != &rs) {
        this->_type = rs._type;
        this->_dog_brain = new Brain(*rs._dog_brain);
    }
    return *this;
}

Dog::~Dog(void) {
    cout << "Dog         - Default Destructor" << endl;
    delete this->_dog_brain;
}

// Methods -------------------------------------------------------------------->

void Dog::makeSound(void) const {
    Animal::makeSound();
    cout << "Woof woof!" << endl;
}
