/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:57:23 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 08:36:23 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    const AAnimal *farm[6];

    for (int i = 0; i < 4; i++) {
        if (i < 2)
            farm[i] = new Cat();
        else
            farm[i] = new Dog();
    }

    cout << endl;
    cout << farm[0]->getType() << endl;
    cout << farm[2]->getType() << endl;

    cout << endl;
    farm[0]->makeSound();
    farm[2]->makeSound();

    cout << endl;
    for (int i = 0; i < 4; i++) {
        delete farm[i];
    }

    return 0;
}
