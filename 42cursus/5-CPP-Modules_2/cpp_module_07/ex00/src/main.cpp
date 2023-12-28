/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:20:48 by kichkiro          #+#    #+#             */
/*   Updated: 2023/12/28 11:09:16 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void) {
    int a = 2;
    int b = 3;

    ::swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    cout << "min( a, b ) = " << ::min(a, b) << endl;
    cout << "max( a, b ) = " << ::max(a, b) << endl;

    string c = "chaine1";
    string d = "chaine2";

    ::swap(c, d);
    cout << "c = " << c << ", d = " << d << endl;
    cout << "min( c, d ) = " << ::min(c, d) << endl;
    cout << "max( c, d ) = " << ::max(c, d) << endl;
    
    return 0;
}
