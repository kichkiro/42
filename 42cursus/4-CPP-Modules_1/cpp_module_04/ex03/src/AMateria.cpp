/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:31:41 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 21:33:34 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// SFM ------------------------------------------------------------------------>

AMateria::AMateria(string const &type) : _type(type) {
    cout << "AMateria - Default Constructor" << endl;
}

AMateria::AMateria(const AMateria &src) : _type(src._type) {
    cout << "AMateria - Copy Constructor" << endl;
}

AMateria &AMateria::operator=(const AMateria &rs) {
    cout << "AMateria - Default Assignment Operator" << endl;
    if (this != &rs) {
        this->_type = rs._type;
    }
    return *this;
}

AMateria::~AMateria(void) {
    cout << "AMateria - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

string const &AMateria::getType(void) const {
    return this->_type;
}

void AMateria::use(ICharacter &target) {
    cout << "* " << target.getName() << " *" << endl;
}
