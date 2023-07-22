/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:02:51 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/21 17:53:47 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// SFM ------------------------------------------------------------------------>

Cat::Cat(void) : _type("Cat") {
    cout << "Cat - Default Constructor" << endl;
}

Cat::Cat(const Cat &src) {
    cout << "Cat - Default Copy Constructor" << endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &rs) {
    cout << "Cat - Default Assignment Operator" << endl;
    if (this != &rs)
        this->_type = rs._type;
    return *this;
}

Cat::~Cat(void) {
    cout << "Cat - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

string Cat::getType(void) const {
    return this->_type;
}

void Cat::makeSound(void) const {
    Animal::makeSound();
    cout << "Meow meow!" << endl;
}
