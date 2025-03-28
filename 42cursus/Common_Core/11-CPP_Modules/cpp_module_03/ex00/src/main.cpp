/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:29:12 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/20 12:53:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap a("A");
    ClapTrap b("B");
    ClapTrap c(b);

    cout << endl;
    for (int i = 0; i < 11; i++) {
        b.attack("A");
        a.takeDamage(0);
    }
    cout << endl;
    
    b.beRepaired(42);
    a.beRepaired(42);
    a.attack("C");
    c.attack("B");
    b.takeDamage(0);
    c.beRepaired(10);
    c.beRepaired(10);
    c.beRepaired(10);
    c.attack("A");
    cout << endl;

    return 0;
}
