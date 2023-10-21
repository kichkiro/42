/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:06:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/11 10:12:17 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include <iostream>
#include <vector>

using std::type_info;


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  // Get the type info for the AForm class.
  const std::type_info& base_type = typeid(AForm);

  // Get a list of all derived classes of AForm.
  cout << base_type. << endl;

  // Print the names of all derived classes.


  return 0;
}
// int main(void) {
    // Init ------------------------------------------------------------------->
    
    // Bureaucrat             *b1 = NULL;
    // Bureaucrat             *b2 = NULL;
    // ShrubberyCreationForm  *f1 = NULL;
    // RobotomyRequestForm    *f2 = NULL;
    // PresidentialPardonForm *f3 = NULL;

    // try {
    //     b1 = new Bureaucrat("b1", 150);
    // }
    // catch (const exception &e) {
    //     cerr << e.what() << endl;
    // }
    // try {
    //     b2 = new Bureaucrat("b2", 6);
    // }
    // catch (const exception &e) {
    //     cerr << e.what() << endl;
    // }
    // try {
    //     f1 = new ShrubberyCreationForm("home");
    // }
    // catch (const exception &e) {
    //     cerr << e.what() << endl;
    // }
    // try {
    //     f2 = new RobotomyRequestForm("home2");
    // }
    // catch (const exception &e) {
    //     cerr << e.what() << endl;
    // }
    // try {
    //     f3 = new PresidentialPardonForm("home3");
    // }
    // catch (const exception &e) {
    //     cerr << e.what() << endl;
    // }
        
    // // Info ------------------------------------------------------------------->

    // cout << endl;
    // cout << "Info --------------------------------------------------->" << endl;
    // cout << endl;
    // cout << *b1 << endl << endl;
    // cout << *b2 << endl << endl;
    // cout << *f1 << endl << endl;
    // cout << *f2 << endl << endl;
    // cout << *f3 << endl << endl;

    // // Test - Form ------------------------------------------------------------>

    // cout << endl;
    // cout << "Test - Form -------------------------------------------->" << endl;
    // cout << endl;
    // b2->executeForm(*f1);
    // cout << endl;
    // b1->signForm(*f1);
    // cout << endl;
    // b2->signForm(*f1);
    // cout << endl;
    // b2->signForm(*f1);
    // cout << endl;
    // b2->executeForm(*f1);
    // cout << endl;
    // b2->signForm(*f2);
    // cout << endl;
    // b2->executeForm(*f2);
    // cout << endl;
    // b1->signForm(*f3);
    // cout << endl;
    // b2->signForm(*f3);
    // cout << endl;
    // b2->executeForm(*f3);
    // cout << endl;
    // b2->incrementGrade();
    // b2->executeForm(*f3);
    // cout << endl;
    
    // // Info ------------------------------------------------------------------->

    // cout << "Info --------------------------------------------------->" << endl;
    // cout << endl;
    // cout << *b1 << endl << endl;
    // cout << *b2 << endl << endl;
    // cout << *f1 << endl << endl;
    // cout << *f2 << endl << endl;
    // cout << *f3 << endl << endl;

    // // Exit ------------------------------------------------------------------->
    
    // delete b1;
    // delete b2;
    // delete f1;
    // delete f2;
    // delete f3;

    // return 0;
// }
