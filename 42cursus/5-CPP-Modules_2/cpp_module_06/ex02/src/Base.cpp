/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:50:25 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/02 13:07:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void) {
    srand(static_cast<unsigned int>(time(NULL)));
    int random = rand() % 3;
    switch (random) {
        case 0:
            cout << "generate A" << endl;
            return new A();
        case 1:
            cout << "generate B" << endl;
            return new B();
        default:
            cout << "generate C" << endl;
            return new C();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL)
        cout << "identify A" << endl;
    else if (dynamic_cast<B *>(p) != NULL)
        cout << "identify B" << endl;
    else if (dynamic_cast<C *>(p) != NULL)
        cout << "identify C" << endl;
    else
        cerr << "Error: ptr is NULL" << endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<const A &>(p);
        cout << "identify A" << endl;
    }
    catch (const exception &eA) {
        try {
            (void)dynamic_cast<const B &>(p);
            cout << "identify B" << endl;
        }
        catch (const exception &eB) {
            try {
                (void)dynamic_cast<const C &>(p);
                cout << "identify C" << endl;
            }
            catch (const exception &eC) {
                cout << "Error" << endl;
            }
        }
    }
}
