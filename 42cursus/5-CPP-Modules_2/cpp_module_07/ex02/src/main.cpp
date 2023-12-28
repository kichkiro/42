/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:20:48 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/28 16:03:48 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
    // Init ------------------------------------------------------------------->
    Array<int> a1(4); 

    cout << "-------------------------------------------------------->" << endl;
    cout << "size a1: " << a1.size() << endl;
    cout << endl;

    for (size_t i = 0; i < a1.size(); i++)
        a1[i] = i * 42;

    cout << "-------------------------------------------------------->" << endl;
    for (size_t i = 0; i < a1.size(); i++)
        cout << "item at index: " << i << " equal to " << a1[i] << endl;
    cout << endl;

    // Test - Copy Constructor ------------------------------------------------>
    Array<int> a2(a1);
    cout << "-------------------------------------------------------->" << endl;
    cout << "size a2 (copied from a1): " << a2.size() << endl;
    cout << "Contents of a2 (copied from a1):" << endl;
    for (size_t i = 0; i < a2.size(); i++)
        cout << "item at index: " << i << " equal to " << a2[i] << endl;
    cout << endl;
    
    a2[0] = 999;
    cout << "First item in a2 modified: " << a2[0] << endl;
    cout << "Corresponding item in a1: " << a1[0] << endl;

    // Test - Assign Operator ------------------------------------------------->
    Array<int> a3;
    a3 = a1;
    cout << "-------------------------------------------------------->" << endl;
    cout << "size a3 (assigned from a1): " << a3.size() << endl;
    cout << "Contents of a3 (assigned from a1):" << endl;
    for (size_t i = 0; i < a3.size(); i++)
        cout << "item at index: " << i << " equal to " << a3[i] << endl;
    cout << endl;

    return 0;
}
