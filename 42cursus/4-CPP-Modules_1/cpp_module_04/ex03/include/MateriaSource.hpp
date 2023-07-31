/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:51:11 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 21:05:09 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "IMateriaSource.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &rs);
        ~MateriaSource(void);

        void learnMateria(AMateria *materia);
        AMateria *createMateria(string const &type);

    private:
        AMateria *_learned[4];
        
};
