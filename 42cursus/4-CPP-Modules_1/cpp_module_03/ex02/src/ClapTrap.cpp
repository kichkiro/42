/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:29:45 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 12:51:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// SFM ------------------------------------------------------------------------>

ClapTrap::ClapTrap(void) {
    cout << "name: " << this->_name << "Default constructor" << endl;
}

ClapTrap::ClapTrap(string name) : _name(name) {
    cout << "name: " << this->_name << " - " << "Contructor with an argument" 
        << endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    cout << "name: " << this->_name << " - " << "Default copy contructor" 
        << endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rs) {
    cout << "name: " << this->_name << " - " << "Overloading the assignment "\
        "operator" << endl;
    if (this == &rs)
        return *this;
    this->_name = rs._name;
    this->_hit_points = rs._hit_points;
    this->_energy_points = rs._energy_points;
    this->_attack_damage = rs._attack_damage;
    return *this;
}

ClapTrap::~ClapTrap(void) {
    cout << "name: " << this->_name << " - " << "Default destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void ClapTrap::attack(const string &target) {
    if (!this->_energy_points)
        cout << "name: " << this->_name << " - " << "You have run out of "\
            "energy points - you cannot attack!" << endl;
    else if (!this->_hit_points)
        cout << "name: " << this->_name << " - " << "You are dead - you cannot"\
            " attack!" << endl;
    else {
        cout << "name: " << this->_name << " - " << "ClapTrap " << this->_name 
            << " attacks " << target << ", causing " << this->_attack_damage 
            << " points of damage!" << endl;
        this->_energy_points--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!this->_hit_points)
        cout << "name: " << this->_name << " - " << "You're already dead, you "\
            "can't take any more damage!" << endl;
    else {
        cout << "name: " << this->_name << " - " << "ClapTrap " << this->_name 
            << " lost " << amount << " health points" << endl;
        if (this->_hit_points < static_cast<int>(amount))
            this->_hit_points = 0;
        else
            this->_hit_points -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->_energy_points)
        cout << "name: " << this->_name << " - " << "You have run out of "\
            "energy points - you can't repair yourself!" << endl;
    else if (!this->_hit_points)
        cout << "name: " << this->_name << " - " << "You are dead - you can't "\
            "repair yourself!" << endl;
    else {
        cout << "name: " << this->_name << " - " << "ClapTrap " << this->_name 
            << " repair himself by " << amount << " health points" << endl;
        this->_hit_points += amount;
        this->_energy_points--;
    }
}
