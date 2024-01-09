/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:24:53 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/09 12:33:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

using std::cout;
using std::endl;

int main(void) {
    vector<int> nums;
    Span sp = Span(5);

    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(17);
    nums.push_back(9);
    nums.push_back(11);

    sp.addNumbers(nums.begin(), nums.end());

    cout << sp.shortestSpan() << endl;
    cout << sp.longestSpan() << endl;
    
    return 0;
}
