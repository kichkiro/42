/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:32:00 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/14 13:51:59 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Libraries ------------------------------------------------------------------>

#include "Weapon.hpp"

// Constructor ---------------------------------------------------------------->

Weapon::Weapon(void) {}

Weapon::Weapon(string type)
{
	this->_type = type;
	cout << "create a weapon: " << this->_type << endl;
}

// Destructor ----------------------------------------------------------------->

Weapon::~Weapon(void)
{
	cout << "destroy weapon: " << this->_type << endl;
}

// Methods -------------------------------------------------------------------->

const string& Weapon::getType(void)
{
	return this->_type;
}

void Weapon::setType(string new_type)
{
	this->_type = new_type;
	cout << "set new type: " << this->_type << endl;
}
