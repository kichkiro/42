/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:32:20 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 13:03:44 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include "Weapon.hpp"

// Class ---------------------------------------------------------------------->

class HumanB
{
    public:

        HumanB(string name);
        ~HumanB(void);

        void    attack(void);
        void    setWeapon(Weapon &new_weapon);

    private:

        string  _name;
        Weapon *_weapon;
};
