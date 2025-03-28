/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:03:56 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 07:48:11 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "Brain.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class WrongAnimal {
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal &operator=(const WrongAnimal &rs);
        virtual ~WrongAnimal(void);

        Brain         *getBrain(void) const;
        string         getType(void) const;
        virtual void   makeSound(void) const;

    protected:
        string _type;      
        Brain *_brain;
};
