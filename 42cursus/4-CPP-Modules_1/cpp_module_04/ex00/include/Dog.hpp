/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:03:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/21 17:51:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "Animal.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class Dog : public Animal {
    public:
        Dog(void);
        Dog(const Dog &src);
        Dog &operator=(const Dog &rs);
        ~Dog(void);

        string getType(void) const;
        void   makeSound(void) const;

    protected:
        string _type;
};
