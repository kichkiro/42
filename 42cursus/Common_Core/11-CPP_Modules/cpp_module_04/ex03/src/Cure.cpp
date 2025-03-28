/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:43 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 21:21:55 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// SFM ------------------------------------------------------------------------>

Cure::Cure(void) : AMateria("cure") {
    cout << "Cure     - Default Constructor" << endl;
}

Cure::Cure(const Cure &src) : AMateria(src) {
    cout << "Cure     - Copy Constructor" << endl;
}

Cure &Cure::operator=(const Cure &rs) {
    cout << "Cure     - Default Assignment Operator" << endl;
    if (this != &rs)
        AMateria::operator=(rs);
    return *this;
}

Cure::~Cure(void) {
    cout << "Cure     - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void Cure::use(ICharacter &target) {
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}

AMateria *Cure::clone(void) const {
    return new Cure(*this);
}
