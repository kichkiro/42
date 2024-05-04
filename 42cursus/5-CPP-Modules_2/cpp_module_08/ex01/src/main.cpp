/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:24:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 13:19:18 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

using std::cout;
using std::endl;
using std::cerr;
using std::vector;

int main() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    cout << sp.shortestSpan() << endl;
    cout << sp.longestSpan() << endl;

    cout << endl << "Test exceptions ------------------------>" << endl << endl;

    Span sp_exc1 = Span(2);

    try {
        for (size_t i = 0; i < 10; i++)
            sp_exc1.addNumber(i);
    }
    catch (const std::exception &e) {
        cerr << e.what() << endl;
    }

    Span sp_exc2 = Span(2);
    try {
        sp_exc2.addNumber(42);
        sp_exc2.longestSpan();
    }
    catch (const std::exception &e) {
        cerr << e.what() << endl;
    }

    cout << endl << "Test with big sequence ----------------->" << endl << endl;

    Span big_sp = Span(10000);

    for (int i = 0; i < 10000; i++)
        big_sp.addNumber(i * 2);

    cout << big_sp.shortestSpan() << endl;
    cout << big_sp.longestSpan() << endl;

    cout << endl << "Test addNumbers() ---------------------->" << endl << endl;

    Span sp_nums = Span(3);
    vector<int> nums;
    vector<int> nums_from_span;

    for (int i = 42; i < 150; i += 42)
        nums.push_back(i);
    sp_nums.addNumbers(nums.begin(), nums.end());
    nums_from_span = sp_nums.get_vec();
    for (vec_it it = nums_from_span.begin(); it != nums_from_span.end(); it++)
        cout << *it << endl;

    return 0;
}
