/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:16:00 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 12:52:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const string &name)
{
    this->_name = name;
}

Zombie::~Zombie(void)
{
    cout << "Destroying zombie: " << this->_name << endl;
}

void	Zombie::announce(void)
{
    cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}
