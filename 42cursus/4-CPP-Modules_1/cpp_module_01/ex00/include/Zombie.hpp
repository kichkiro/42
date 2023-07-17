/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:17:37 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 13:01:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::string;
using std::cout;
using std::endl;

// Class ---------------------------------------------------------------------->

class Zombie
{
    public:

        Zombie(const string &name);
        ~Zombie(void);

        void   announce(void);

    private:

        string _name;
};

// Functions ------------------------------------------------------------------>

Zombie *newZombie(string name);
void	randomChump(string name);
