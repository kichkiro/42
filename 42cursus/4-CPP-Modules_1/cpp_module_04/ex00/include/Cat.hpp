/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:03:13 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/21 17:50:48 by kichkiro         ###   ########.fr       */
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

class Cat : public Animal {
    public:
        Cat(void);
        Cat(const Cat &src);
        Cat &operator=(const Cat &rs);
        ~Cat(void);

        string getType(void) const;
        void   makeSound(void) const;

    protected:
        string _type;
};
