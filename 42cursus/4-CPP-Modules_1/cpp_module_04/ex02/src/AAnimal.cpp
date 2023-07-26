/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:18:23 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/26 11:07:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// SFM ------------------------------------------------------------------------>

AAnimal::AAnimal(void) : _type("") {
    cout << "Animal      - Default Constructor" << endl;
}

AAnimal::AAnimal(const AAnimal &src) {
    cout << "Animal      - Default Copy Constructor" << endl;
    *this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &rs) {
    cout << "Animal      - Default Assignment Operator" << endl;
    if (this != &rs)
        this->_type = rs._type;
    return *this;
}

AAnimal::~AAnimal(void) {
    cout << "Animal      - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

string AAnimal::getType(void) const {
    return this->_type;
}
