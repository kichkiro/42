/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:24:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 10:37:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::exception;

int main(void) {
    vector<int> vec;
    int value_to_find = 42;
    vector<int>::iterator it;

    vec.push_back(1);
    vec.push_back(35);
    vec.push_back(40);
    vec.push_back(5);
    vec.push_back(42);

    try {
        it = easyfind(vec, value_to_find);
        cout << "Value " << value_to_find << " founded in the vector." << endl;
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
