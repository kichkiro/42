/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:16:50 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:19:05 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie *zombies;

    zombies = zombieHorde(42, "frank");
    delete[] zombies;
    return 0;
}
