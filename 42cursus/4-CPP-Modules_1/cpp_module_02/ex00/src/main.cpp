/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:19:16 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:15:51 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    cout << a.getRawBits() << endl;
    cout << b.getRawBits() << endl;
    cout << c.getRawBits() << endl;

    return 0;
}
