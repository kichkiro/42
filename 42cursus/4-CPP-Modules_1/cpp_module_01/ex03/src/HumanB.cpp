/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:31:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/14 12:18:26 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor ---------------------------------------------------------------->

HumanB::HumanB(string name, string weapon)
{
	this->name = name;
	this->weapon.setType(weapon);
}

// Destructor ----------------------------------------------------------------->

HumanB::~HumanB(void)
{
	cout << "destroy HumanB: " << this->name << endl;
}

// Methods -------------------------------------------------------------------->

void HumanB::attack(void)
{
	cout << this->name << " attack with their " << this->weapon.getType() << \
		endl;
}
