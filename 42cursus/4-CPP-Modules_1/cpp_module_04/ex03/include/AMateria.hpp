/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:32:03 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/27 22:52:44 by kichkiro         ###   ########.fr       */
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

class ICharacter;

class AMateria {
    public:
        AMateria(string const &type);
        AMateria(const AMateria &src);
        AMateria &operator=(const AMateria &rs);
        virtual ~AMateria(void);

        string const &getType(void) const;

        virtual AMateria *clone(void) const = 0;
        virtual void use(ICharacter &target);

    protected:
        const string _type;
};
