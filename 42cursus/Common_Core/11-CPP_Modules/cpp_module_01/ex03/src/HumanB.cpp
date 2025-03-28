/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:31:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:19:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor ---------------------------------------------------------------->

HumanB::HumanB(string _name) : _name(_name), _weapon(NULL) {}

// Destructor ----------------------------------------------------------------->

HumanB::~HumanB(void) {
    cout << "destroy HumanB: " << this->_name << endl;
}

// Methods -------------------------------------------------------------------->

void HumanB::attack(void) {
    cout << this->_name << " attack with their " << this->_weapon->getType() \
        << endl;
}

void HumanB::setWeapon(Weapon &new_weapon) {
    this->_weapon = &new_weapon;
    cout << "set weapon: " << this->_weapon->getType() << endl;
}
