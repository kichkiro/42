/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:32:00 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/14 12:19:34 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Libraries ------------------------------------------------------------------>

#include "Weapon.hpp"

// Constructor ---------------------------------------------------------------->

Weapon::Weapon(void)
{
	cout << "create a weapon" << endl;
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

void Weapon::setType(string type)
{
	this->_type = type;
}
