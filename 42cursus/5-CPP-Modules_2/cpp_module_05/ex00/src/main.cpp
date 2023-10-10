/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:06:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/07 15:16:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat *b = NULL;

    try {
        b = new Bureaucrat("bob", 2);
        cout << "start grade: " << b->getGrade() << endl;
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }
    
    try {
        b->incrementGrade();
        b->incrementGrade();
        b->decrementGrade();
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }

    cout << *b << endl;

    delete b;

    return 0;
}
