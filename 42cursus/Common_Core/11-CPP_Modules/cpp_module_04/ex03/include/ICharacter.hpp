/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:51:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 21:30:03 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class AMateria;

class ICharacter {
    public:
        ICharacter(void);
        ICharacter(const ICharacter &src);
        virtual ~ICharacter(void);

        virtual string const &getName(void) const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter &target) = 0;
};
