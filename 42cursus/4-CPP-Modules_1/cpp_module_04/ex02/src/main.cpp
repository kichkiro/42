/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:57:23 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/26 09:39:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal *farm[6];

    for (int i = 0; i < 4; i++) {
        if (i < 2)
            farm[i] = new Cat();
        else
            farm[i] = new Dog();
    }
    
    for (int i = 0; i < 4; i++) {
        delete farm[i];
    }

    return 0;
}
