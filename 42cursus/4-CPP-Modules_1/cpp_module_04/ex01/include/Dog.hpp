/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:03:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/26 00:30:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

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

        void makeSound(void) const;

    private:
        Brain *_dog_brain;
};