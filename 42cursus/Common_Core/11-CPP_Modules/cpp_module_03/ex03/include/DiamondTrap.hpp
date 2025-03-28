/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:16:22 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 21:12:50 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap(void);
        DiamondTrap(string name);
        DiamondTrap(const DiamondTrap &src);
        ~DiamondTrap(void);

        void attack(const string &target);
        void whoAmI(void);

    private:
        string _name;
};
