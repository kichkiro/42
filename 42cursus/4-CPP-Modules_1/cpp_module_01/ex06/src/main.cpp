/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:00:59 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 12:51:36 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl *harl;

    if (argc != 2)
    {
        cout << "usage: ./harlFilter <level>" << endl;
        return 1;
    }
    harl = new Harl();
    harl->complain(argv[1]);
    delete harl;

    return 0;
}
