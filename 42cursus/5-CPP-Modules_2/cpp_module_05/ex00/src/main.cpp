/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:06:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/01 11:30:56 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat *b = NULL;

    try {
        b = new Bureaucrat("bob", 2);
    }
    catch (const exception &e) {
        cerr << e.what() << '\n';
    }
    
    try {
        b->incrementGrade();
        b->incrementGrade();
        b->decrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    cout << b->getGrade() << endl;

    delete b;

    return 0;
}
