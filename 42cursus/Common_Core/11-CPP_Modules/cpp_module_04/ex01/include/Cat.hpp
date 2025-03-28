/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:03:13 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 07:39:01 by kichkiro         ###   ########.fr       */
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

class Cat : public Animal {
    public:
        Cat(void);
        Cat(const Cat &src);
        Cat &operator=(const Cat &rs);
        ~Cat(void);

        void makeSound(void) const;

    private:
        Brain *_cat_brain;
};
