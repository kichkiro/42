/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:39:15 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:19:20 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void) {
    string str = "HI THIS IS BRAIN";
    string *stringPTR = &str;
    string &stringREF = str;

    cout << "Memory address of the string variable: " << &str << endl;
    cout << "Memory address held by stringPTR:      " << stringPTR << endl;
    cout << "Memory address held by stringREF:      " << &stringREF << endl;
    cout << endl;
    cout << "Value of the string variable:  " << str << endl;
    cout << "Value pointed to by stringPTR: " << *stringPTR << endl;
    cout << "Value pointed to by stringREF: " << stringREF << endl;

    return 0;
}
