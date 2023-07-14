/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:31:48 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/14 12:18:19 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor ---------------------------------------------------------------->

HumanA::HumanA(string name, string weapon)
{
	this->name = name;
	this->weapon.setType(weapon);
}

// Destructor ----------------------------------------------------------------->

HumanA::~HumanA(void)
{
	cout << "destroy HumanA: " << this->name << endl;
}

// Methods -------------------------------------------------------------------->

void HumanA::attack(void)
{
	cout << this->name << " attack with their " << this->weapon.getType() << \
		endl;
}
