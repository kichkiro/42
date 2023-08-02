/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:57:23 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 08:31:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

int main(void) {
    Animal *farm[6];

    for (int i = 0; i < 4; i++) {
        if (i < 2)
            farm[i] = new Cat();
        else
            farm[i] = new Dog();
    }

    for (int i = 0; i < 4; i++) {
        delete farm[i];
    }

    WrongAnimal *wrong = new WrongAnimal();
    cout << wrong->getBrain() << endl;
    WrongAnimal *wrong_cpy = new WrongAnimal(*wrong);
    cout << wrong_cpy->getBrain() << endl;
    
    delete wrong;
    delete wrong_cpy;

    return 0;
}
