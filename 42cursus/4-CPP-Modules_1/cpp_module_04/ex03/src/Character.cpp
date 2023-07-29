/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:30:42 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/28 17:37:18 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// SFM ------------------------------------------------------------------------>

Character::Character(string name) : _name(name) {
    cout << "Character - Default Constructor" << endl;
}

Character::Character(const Character &src) {
    cout << "Character - Copy Constructor" << endl;
    this->_name = src._name;
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
        this->_inventory[i] = src._inventory[i];
    }
    for (int i = 0; i < sizeof(size_t); i++) {
        if (!this->_old[i])
            break;
        delete this->_old[i];
        this->_old[i] = src._old[i];
    }
}

Character &Character::operator=(const Character &rs) {
    cout << "Character - Default Assignment Operator" << endl;
    if (this == &rs)
        return *this;
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
        this->_inventory[i] = rs._inventory[i];
    }
    for (int i = 0; i < sizeof(size_t); i++) {
        if (!this->_old[i])
            break;
        delete this->_old[i];
        this->_old[i] = rs._old[i];
    }
    return *this;
}

Character::~Character() {
    cout << "Character - Default Destructor" << endl;
    for (int i = 0; i < sizeof(size_t); i++) {
        if (this->_old[i])
            delete this->_old[i];
    }
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
    this->_inventory[idx]->use(target);
}
