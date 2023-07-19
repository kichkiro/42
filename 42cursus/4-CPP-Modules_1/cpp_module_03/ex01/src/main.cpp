/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:29:12 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/19 22:09:47 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap a("a", 5, 3, 2);
    ClapTrap b("b", 10, 3, 4);
    ClapTrap c(b);

    b.attack("a");
    a.takeDamage(4);
    b.attack("a");
    a.takeDamage(4);
    b.attack("a");
    a.takeDamage(4);
    a.beRepaired(42);
    a.attack("c");
    c.attack("b");
    b.takeDamage(4);
    c.beRepaired(10);
    c.beRepaired(10);
    c.beRepaired(10);
    c.attack("a");
    b.beRepaired(42);

    return 0;
}
