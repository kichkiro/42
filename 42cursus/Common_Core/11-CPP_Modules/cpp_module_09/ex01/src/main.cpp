/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:59 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/17 10:15:29 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " \"inverted Polish expression\"\n";
        return 1;
    }
    try {
        RPN rpn(argv[1]);
        cout << rpn.evaluate() << endl;
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
