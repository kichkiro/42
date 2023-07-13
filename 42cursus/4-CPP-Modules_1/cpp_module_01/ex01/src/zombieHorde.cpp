/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:16:56 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/13 10:11:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, string name)
{
	Zombie *zombies;

	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i] = Zombie(name);
		zombies[i].announce();
	}
	return zombies;
}
