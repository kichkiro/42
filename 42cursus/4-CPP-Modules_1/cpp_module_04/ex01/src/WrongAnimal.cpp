/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:04:42 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 08:30:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// SFM ------------------------------------------------------------------------>

WrongAnimal::WrongAnimal(void) : _type(""), _brain(new Brain()) {
    cout << "WrongAnimal - Default Constructor" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
    cout << "WrongAnimal - Default Copy Constructor" << endl;
    this->_type = src._type;
    this->_brain = new Brain(*src._brain);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rs) {
    cout << "WrongAnimal - Default Assignment Operator" << endl;
    if (this != &rs) {
        this->_type = rs._type;
        this->_brain = new Brain(*rs._brain);
    }
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    cout << "WrongAnimal - Default Destructor" << endl;
    delete this->_brain;
}

// Methods -------------------------------------------------------------------->

Brain *WrongAnimal::getBrain(void) const {
    return this->_brain;
}

string WrongAnimal::getType(void) const {
    return this->_type;
}

void WrongAnimal::makeSound(void) const {}
