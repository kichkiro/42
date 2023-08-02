/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:02:51 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 07:05:29 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// SFM ------------------------------------------------------------------------>

Cat::Cat(void) {
    cout << "Cat         - Default Constructor" << endl;    
    this->_type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src) {
    cout << "Cat         - Default Copy Constructor" << endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &rs) {
    cout << "Cat         - Default Assignment Operator" << endl;
    if (this != &rs)
        this->_type = rs._type;
    return *this;
}

Cat::~Cat(void) {
    cout << "Cat         - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void Cat::makeSound(void) const {
    Animal::makeSound();
    cout << "Meow meow!" << endl;
}
