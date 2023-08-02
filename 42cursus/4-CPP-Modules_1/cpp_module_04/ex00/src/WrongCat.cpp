/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:04:28 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 07:11:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// SFM ------------------------------------------------------------------------>

WrongCat::WrongCat(void) {
    cout << "WrongCat    - Default Constructor" << endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    cout << "WrongCat    - Default Copy Constructor" << endl;
    *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &rs) {
    cout << "WrongCat    - Default Assignment Operator" << endl;
    if (this != &rs)
        this->_type = rs._type;
    return *this;
}

WrongCat::~WrongCat(void) {
    cout << "WrongCat    - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void WrongCat::makeSound(void) const {
    WrongAnimal::makeSound();
    cout << "Wrong Wrong!" << endl;
}
