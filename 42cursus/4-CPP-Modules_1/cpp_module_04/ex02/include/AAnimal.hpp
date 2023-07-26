/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:03:05 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/26 11:06:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class AAnimal {
    public:
        AAnimal(void);
        AAnimal(const AAnimal &src);
        AAnimal &operator=(const AAnimal &rs);
        virtual ~AAnimal(void);

        string getType(void) const;
        virtual void   makeSound(void) const = 0;

    protected:
        string _type;      
};
