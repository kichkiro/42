/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:15:29 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/12 21:13:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *heap_zombie;

	heap_zombie = newZombie("Heap");
	heap_zombie->announce();
	delete heap_zombie;
	randomChump("Stack");
	return 0;
}
