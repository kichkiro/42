/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:16:53 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 20:08:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(string name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap(void);

        void attack(const string &target);
        void guardGate(void);
};
