/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:04:39 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 18:04:38 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(string name);
        FragTrap(const FragTrap &src);
        ~FragTrap(void);

        void attack(const string &target);
        void highFivesGuys(void);
};
