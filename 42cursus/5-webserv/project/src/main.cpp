/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:59:33 by kichkiro          #+#    #+#             */
/*   Updated: 2024/01/22 17:00:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "webserv.hpp"
#include "Directive.hpp"

int main(int argc, char const **argv) {
    // if (argc == 1)
    //     ConfigFile configfile;
    // else if (argc == 2)
    //     ConfigFile configfile(argv[1]);
    // else {
    //     cerr << "Usage: ./webserv [CONFIG-FILE]" << endl;
    //     return 1;
    // }

    (void)argc;
    (void)argv;
    Http http("test");
    


    return 0;
}
