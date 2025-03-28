/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:04:28 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 18:11:53 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// SFM ------------------------------------------------------------------------>

FragTrap::FragTrap(void) : ClapTrap() {
    cout << "<-------- FragTrap -  Default constructor" << endl;
}

FragTrap::FragTrap(string name) : ClapTrap(name) {
    cout << "<-------- FragTrap - Contructor with an argument" << endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    cout << "<-------- FragTrap - Default copy contructor" << endl;
}

FragTrap::~FragTrap(void) {
    cout << "<-------- FragTrap - Default destructor" << endl;
}

// Methods -------------------------------------------------------------------->

void FragTrap::attack(const string &target) {
    ClapTrap::attack(target);
    cout << "<-------- PS: I am FragTrap" << endl; 
}

void FragTrap::highFivesGuys(void) {
    cout << "name: " << this->_name << " - " << "FragTrap " << this->_name  << 
        " high-five!" << endl;
}
