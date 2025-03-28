/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:29:18 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/28 17:11:59 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "ICharacter.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class Character : public ICharacter {
    public:
        Character(string name);
        Character(const Character &src);
        Character &operator=(const Character &rs);
        ~Character(void);

        string const &getName(void) const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);

    private:
        string    _name;
        AMateria *_inventory[4];
        AMateria *_old[sizeof(size_t)];
};
