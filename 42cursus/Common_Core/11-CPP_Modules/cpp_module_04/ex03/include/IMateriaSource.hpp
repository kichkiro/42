/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:42:20 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 21:30:52 by kichkiro         ###   ########.fr       */
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

class IMateriaSource {
    public:
        IMateriaSource(void);
        IMateriaSource(const IMateriaSource &src);
        virtual ~IMateriaSource(void);

        virtual void learnMateria(AMateria *) = 0;
        virtual AMateria *createMateria(string const &type) = 0;
};
