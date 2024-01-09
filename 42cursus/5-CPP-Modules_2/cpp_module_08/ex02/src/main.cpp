/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:24:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/09 14:58:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include "MutantStack.hpp"

using std::cout;
using std::endl;
using std::list;

int main(void) {
    // Test with MutantStack -------------------------------------------------->
    cout << "Test with MutantStack:" << endl;

    MutantStack<int> mutant_stack;

    mutant_stack.push(5);
    mutant_stack.push(17);

    cout << mutant_stack.top() << endl;
    mutant_stack.pop();
    cout << mutant_stack.size() << endl;
    mutant_stack.push(3);
    mutant_stack.push(5);
    mutant_stack.push(737);

    //[...]

    mutant_stack.push(0);

    MutantStack<int>::iterator it = mutant_stack.begin();
    MutantStack<int>::iterator ite = mutant_stack.end();

    ++it;
    --it;
    
    while (it != ite) {
        cout << *it << endl;
        ++it;
    }
    
    stack<int> s(mutant_stack);

    // Test with Standard List ------------------------------------------------>
    cout << endl << "Test with Standard List:" << endl;

    list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    cout << lst.back() << endl;
    lst.pop_back();
    cout << lst.size() << endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);

    // [...]

    lst.push_back(0);

    list<int>::iterator it_list = lst.begin();
    list<int>::iterator ite_list = lst.end();

    ++it_list;
    --it_list;

    while (it_list != ite_list) {
        cout << *it_list << endl;
        ++it_list;
    }

    return 0;
}
