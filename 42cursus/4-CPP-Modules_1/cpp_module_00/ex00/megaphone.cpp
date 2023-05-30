/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:38:38 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/29 22:22:20 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::toupper;

int main(int argc, char **argv)
{
    string arg;

    if (argc == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i)
    {
        arg = argv[i];

        for (int j = 0; arg[j]; ++j)
            cout << (char)toupper(arg[j]);
    }
    cout << endl;
    return 0;
}
