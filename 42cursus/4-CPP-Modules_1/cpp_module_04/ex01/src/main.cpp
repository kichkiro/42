/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:57:23 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/25 19:56:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    const WrongAnimal *k = new WrongCat();

    cout << j->getType() << " " << endl;
    cout << i->getType() << " " << endl;
    cout << k->getType() << " " << endl;

    i->makeSound();
    j->makeSound();
    k->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    return 0;
}
