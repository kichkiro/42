/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:59:33 by kichkiro          #+#    #+#             */
/*   Updated: 2024/03/09 17:51:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigFile.hpp"

int main(int argc, char const **argv) {
    try {
        if (argc == 1) {
            ConfigFile configfile;
            Http *httpDirective = dynamic_cast<Http *>(configfile.get_config()[0]);
            httpDirective->start_servers();
        }
        else if (argc == 2)
            ConfigFile configfile(argv[1]);
        else {
            cerr << "Usage: ./webserv [CONFIG-FILE]" << endl;
            return 1;
        }
    }

    catch (const exception &e) {
    }

    return 0;
}

