/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/28 00:27:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "AMateria.hpp"

using std::cout;
using std::endl;

// Class ---------------------------------------------------------------------->

class Cure : public AMateria {
    public:
        Cure(void);
        Cure(const Cure &src);
        Cure &operator=(const Cure &rs);
        ~Cure(void);

        void use(ICharacter &target);
        AMateria *clone(void) const;
};
