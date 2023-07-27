/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:39:55 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/27 20:06:51 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "AMateria.hpp"

using std::cout;
using std::endl;

// Class ---------------------------------------------------------------------->

class Ice : public AMateria {
    public:
        Ice(void);
        Ice(const Ice &src);
        Ice &operator=(const Ice &rs);
        ~Ice(void);

        // void use(ICharacter &target);
        AMateria *clone(void) const;        
};
