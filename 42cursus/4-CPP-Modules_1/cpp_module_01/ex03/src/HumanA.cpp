/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:31:48 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:19:27 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor ---------------------------------------------------------------->

HumanA::HumanA(string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

// Destructor ----------------------------------------------------------------->

HumanA::~HumanA(void) {
    cout << "destroy HumanA: " << this->_name << endl;
}

// Methods -------------------------------------------------------------------->

void HumanA::attack(void) {
    cout << this->_name << " attack with their " << this->_weapon.getType() << \
        endl;
}
