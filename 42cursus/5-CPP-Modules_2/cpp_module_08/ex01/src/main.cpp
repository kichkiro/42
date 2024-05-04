/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:24:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 11:01:12 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

using std::cout;
using std::endl;

int main(void) {
    // vector<int> nums;
    // Span sp = Span(5);

    // nums.push_back(6);
    // nums.push_back(3);
    // nums.push_back(17);
    // nums.push_back(9);
    // nums.push_back(11);

    // sp.addNumbers(nums.begin(), nums.end());

    // cout << sp.shortestSpan() << endl;
    // cout << sp.longestSpan() << endl;
    
    cout << "Test with big sequence ------------------------->" << endl;

    vector<int> nums2;
    Span big_sp = Span(10000);

    for (int i = 0; i < 10000; i++)
        nums2.push_back(i);
    
    big_sp.addNumbers(nums2.begin(), nums2.end());

    cout << big_sp.shortestSpan() << endl;
    cout << big_sp.longestSpan() << endl;
    
    return 0;
}
