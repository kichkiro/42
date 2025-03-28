/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:06:54 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/03 09:03:01 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat a("A", 150);
    Bureaucrat *b = NULL;
    Bureaucrat c;

    cout << "start grade a: " << a.getGrade() << endl;
    cout << "start grade c: " << c.getGrade() << endl << endl;

    try {
        b = new Bureaucrat("B", 151);
    }
    catch (const exception &e) {
        cerr << e.what() << " - New grade assigned to bur 'b': 150" << endl;
        b = new Bureaucrat("B", 150);
    }

    try {
        for(int i = 0; i < 200; i++)
            b->incrementGrade();
    }
    catch (const exception &e) {
        cerr << e.what() << " - New grade assigned to bur 'b': 1" << endl;
    }

    try {
        for(int i = 0; i < 200; i++)
            b->decrementGrade();
    }
    catch (const exception &e) {
        cerr << e.what() << " - New grade assigned to bur 'b': 150" << endl;
    }

    cout << endl << a << endl;
    cout << *b << endl;
    cout << c << endl;

    delete b;

    return 0;
}
