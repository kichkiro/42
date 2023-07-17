/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:16:45 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 13:04:17 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class Zombie
{
    public:

        Zombie(void);
        Zombie(const string &name);
        ~Zombie(void);

        void   announce(void);

    private:

        string _name;
};

// Functions ------------------------------------------------------------------>

Zombie *zombieHorde(int N, string name);
