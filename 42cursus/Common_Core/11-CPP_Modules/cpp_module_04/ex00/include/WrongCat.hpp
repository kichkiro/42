/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:04:13 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 07:11:23 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "WrongAnimal.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class WrongCat : public WrongAnimal {
    public:
        WrongCat(void);
        WrongCat(const WrongCat &src);
        WrongCat &operator=(const WrongCat &rs);
        ~WrongCat(void);

        void makeSound(void) const;
};
