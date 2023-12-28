/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:20:48 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/28 11:10:11 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
    // Test with an array of int ---------------------------------------------->
    int int_array[] = {1, 2, 3, 4, 5};
    size_t int_array_len = sizeof(int_array) / sizeof(int_array[0]);

    cout << "Integer array: ";
    ::iter(int_array, int_array_len, ::print_item<int>);
    cout << endl;

    // Test with an array of doubles ------------------------------------------>
    double double_array[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    size_t double_array_length = sizeof(double_array) / sizeof(double_array[0]);

    cout << "Double array: ";
    ::iter(double_array, double_array_length, ::print_item<double>);
    cout << endl;

    return 0;
}
