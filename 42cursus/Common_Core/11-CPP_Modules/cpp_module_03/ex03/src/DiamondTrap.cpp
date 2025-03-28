/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:16:33 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 21:15:37 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// SFM ------------------------------------------------------------------------>

DiamondTrap::DiamondTrap() :
    ClapTrap(), _name(ClapTrap::_name + "_clap_name") {
    cout << "<<<------ DiamondTrap - Default constructor" << endl;
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(string name) :
    ClapTrap(name), _name(name + "_clap_name") {
    cout << "<<<------ DiamondTrap - Contructor with an argument" << endl;
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) :
    ClapTrap(src), ScavTrap(src), FragTrap(src) {
    cout << "<<<------ DiamondTrap - Default copy contructor" << endl;
    *this = src;
}

DiamondTrap::~DiamondTrap() {
    cout << "<<<------ DiamondTrap - Default destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void DiamondTrap::attack(const string &target) {
    ScavTrap::attack(target);
    cout << "DiamondTrap " << this->_name << " attack using ScavTrap!" << endl;
}

void DiamondTrap::whoAmI() {
    cout << "<<<------ DiamondTrap - I am -> " << this->_name << 
        " - Clapname: " << ClapTrap::_name << endl;
}
