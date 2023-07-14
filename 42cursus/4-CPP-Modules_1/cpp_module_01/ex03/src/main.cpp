/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:31:40 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/14 12:20:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	HumanA *human_a;
	HumanB *human_b;

	human_a = new HumanA("bob", "bow");
	human_b = new HumanB("frank", "lance");
	human_a->attack();
	human_b->attack();
	delete human_a;
	delete human_b;

	return 0;
}
