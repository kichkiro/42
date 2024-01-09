/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:24:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/08 15:27:13 by kichkiro         ###   ########.fr       */
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
    try {
        vector<int> vec;
        int value_to_find;

        for (size_t i = 0; i < 5; i++) {
            vec.push_back(i);
        }

        value_to_find = -1;
        easyfind(vec, value_to_find);

        cout << "Value " << value_to_find << " find" << endl;
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
