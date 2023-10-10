/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:06:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/08 12:49:42 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    // Init ------------------------------------------------------------------->
    
    Bureaucrat *b1 = NULL;
    Bureaucrat *b2 = NULL;
    Form       *f1 = NULL;
    Form       *f2 = NULL;

    try {
        b1 = new Bureaucrat("b1", 2);
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }
    try {
        b2 = new Bureaucrat("b2", 19);
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }
    try {
        f1 = new Form("f1", 20, 1);
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }
    try {
        f2 = new Form("f2", 1, 1);
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }
        
    // Info ------------------------------------------------------------------->

    cout << endl;
    cout << "Info --------------------------------------------------->" << endl;
    cout << endl;
    cout << *b1 << endl << endl;
    cout << *b2 << endl << endl;
    cout << *f1 << endl << endl;
    cout << *f2 << endl << endl;

    // Test - Bureaucrat ------------------------------------------------------>

    cout << "Test - Bureaucrat -------------------------------------->" << endl;
    cout << endl;
    try {
        b1->incrementGrade();
        b1->incrementGrade();
        b1->decrementGrade();
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }

    // Test - Form ------------------------------------------------------------>

    cout << endl;
    cout << "Test - Form -------------------------------------------->" << endl;
    cout << endl;
    b1->signForm(*f1);
    cout << endl;
    b1->signForm(*f2);
    cout << endl;
    b2->signForm(*f1);
    cout << endl;
    b2->signForm(*f2);

    // Info ------------------------------------------------------------------->

    cout << endl;
    cout << "Info --------------------------------------------------->" << endl;
    cout << endl;
    cout << *b1 << endl << endl;
    cout << *b2 << endl << endl;
    cout << *f1 << endl << endl;
    cout << *f2 << endl << endl;

    // Exit ------------------------------------------------------------------->
    
    delete b1;
    delete b2;
    delete f1;
    delete f2;
    return 0;
}
