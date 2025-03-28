/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:44:16 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/28 00:26:45 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// SFM ------------------------------------------------------------------------>

Ice::Ice(void) : AMateria("ice") {
    cout << "Ice      - Default Constructor" << endl;
}

Ice::Ice(const Ice &src) : AMateria(src) {
    cout << "Ice      - Copy Constructor" << endl;
}

Ice &Ice::operator=(const Ice &rs) {
    cout << "Ice      - Default Assignment Operator" << endl;
    if (this != &rs)
        AMateria::operator=(rs);
    return *this;
}

Ice::~Ice(void) {
    cout << "Ice      - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void Ice::use(ICharacter &target) {
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}

AMateria *Ice::clone(void) const {
    return new Ice(*this);
}
