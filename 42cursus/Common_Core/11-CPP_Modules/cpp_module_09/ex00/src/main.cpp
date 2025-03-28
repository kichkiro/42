/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:59 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/04 16:13:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "You must provide an input file..." << endl;
        return 1;
    }
    BitcoinExchange btc("data.csv", argv[1]);

    return 0;
}
