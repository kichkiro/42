/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:03:05 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/21 17:49:51 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class Animal {
    public:
        Animal(void);
        Animal(const Animal &src);
        Animal &operator=(const Animal &rs);
        ~Animal(void);

        string getType(void) const;
        void   makeSound(void) const;

    protected:
        string _type;      
};
