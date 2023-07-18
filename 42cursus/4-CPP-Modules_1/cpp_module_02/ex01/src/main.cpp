/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:19:16 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:15:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    Fixed 		a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "c is " << c << endl;
    cout << "d is " << d << endl;

    cout << "a is " << a.toInt() << " as integer" << endl;
    cout << "b is " << b.toInt() << " as integer" << endl;
    cout << "c is " << c.toInt() << " as integer" << endl;
    cout << "d is " << d.toInt() << " as integer" << endl;

    return 0;
}

