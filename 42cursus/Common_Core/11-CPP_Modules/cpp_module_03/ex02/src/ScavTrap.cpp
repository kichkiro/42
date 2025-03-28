/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:15:43 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 18:12:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// SFM ------------------------------------------------------------------------>

ScavTrap::ScavTrap(void) : ClapTrap() {
    cout << "<-------- ScavTrap -  Default constructor" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
    cout << "<-------- ScavTrap - Contructor with an argument" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    cout << "<-------- ScavTrap - Default copy contructor" << endl;
}

ScavTrap::~ScavTrap(void) {
    cout << "<-------- ScavTrap - Default destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void ScavTrap::attack(const string &target) {
    ClapTrap::attack(target);
    cout << "<-------- PS: I am ScavTrap" << endl; 
}

void ScavTrap::guardGate(void) {
    cout << "name: " << this->_name << " - " << "ScavTrap " << this->_name  << 
        " is now in Gate keeper mode!"<< endl;
}
