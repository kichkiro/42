/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:30:42 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/28 00:09:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// SFM ------------------------------------------------------------------------>

Character::Character(string name) : _name(name) {
    cout << "Character - Default Constructor" << endl;
}

Character::Character(const Character &src) {
    cout << "Character - Copy Constructor" << endl;
}

Character &Character::operator=(const Character &rs) {
    cout << "Character - Default Assignment Operator" << endl;
    return *this;
}

Character::~Character() {
    cout << "Character - Default Destructor" << endl;
}

// Methods -------------------------------------------------------------------->

string const &Character::getName(void) const {
    return this->_name;
}

void Character::equip(AMateria *m) {
    if (!m)
        return;
    for (char i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    for (size_t i = 0; i < sizeof(size_t); i++) {
        if (!this->_old[i]) {
            this->_old[i] = this->_inventory[idx];
            break;
        }
    }
    this->_inventory[idx] = NULL;    
}

void Character::use(int idx, ICharacter &target) {

}
