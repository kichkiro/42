/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:29:12 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 18:13:48 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
    FragTrap a("A");
    FragTrap b("B");
    FragTrap c(b);

    cout << endl;
    for (int i = 0; i < 6; i++) {
        b.attack("a");
        a.takeDamage(20);
    }
    cout << endl;
    
    b.beRepaired(42);
    a.beRepaired(42);
    a.attack("C");
    c.takeDamage(20);
    c.attack("B");
    b.takeDamage(20);
    b.takeDamage(0);
    c.beRepaired(10);
    c.beRepaired(10);
    c.beRepaired(10);
    c.attack("A");
    b.highFivesGuys();
    a.highFivesGuys();
    cout << endl;

    return 0;
}
