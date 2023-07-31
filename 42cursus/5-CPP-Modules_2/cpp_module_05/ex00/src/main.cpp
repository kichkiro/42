/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:06:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/31 23:39:27 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat *b;

    b = new Bureaucrat("bob", 151);

    try {

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    delete b;

    return 0;
}
