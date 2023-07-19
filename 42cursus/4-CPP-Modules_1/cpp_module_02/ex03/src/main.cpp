/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:19:16 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/19 17:15:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

int main(void) {
    bool res;

    res = bsp(Point(0, 0), Point(25, 50), Point(50, 0), Point(1, 2.09f));
    cout << res << endl;
    
    return 0;
}
