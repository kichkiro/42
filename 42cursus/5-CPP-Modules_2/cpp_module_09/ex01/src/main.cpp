/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:32:59 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/15 14:01:01 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "You must provide an input file..." << endl;
        return 1;
    }
    RPN btc("database/data.csv", argv[1]);

    return 0;
}
