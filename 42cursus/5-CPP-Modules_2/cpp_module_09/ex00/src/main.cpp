/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:59 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/11 17:08:45 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "You must provide an input file..." << endl;
        return 1;
    }
    BitcoinExchange btc("database/data.csv", argv[1]);
    btc.calculate();
    
    return 0;
}
