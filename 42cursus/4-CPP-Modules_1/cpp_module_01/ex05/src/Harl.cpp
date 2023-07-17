/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:01:15 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 12:50:11 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Construnctor --------------------------------------------------------------->

Harl::Harl(void) {}

// Destructor ----------------------------------------------------------------->

Harl::~Harl(void) {}

// Methods -------------------------------------------------------------------->

void Harl::complain(string level)
{
    action a[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    string type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i <= 4; ++i)
    {
        if (i == 4)
        {
            cout << "[ Probably complaining about insignificant problems ]" << \
                endl;
        }
        else if (level == type[i])
        {
            (this->*a[i])();
            break;
        }
    }
    cout << endl;
}

void Harl::_debug(void)
{
    cout << "[ DEBUG ]" << endl << "I love having extra bacon for my 7XL-doubl"\
        "e-cheese-triple-pickle-special-ketchup burger. I really do!" << endl;
}

void Harl::_info(void)
{
    cout << "[ INFO ]" << endl << "I cannot believe adding extra bacon costs m"\
        "ore money. You didn’t put enough bacon in my burger! If you did, I wo"\
        "uldn’t be asking for more!" << endl;
}

void Harl::_warning(void)
{
    cout << "[ WARNING ]" << endl << "I think I deserve to have some extra bac"\
        "on for free. I’ve been coming for years whereas you started working h"\
        "ere since last month." << endl;
}

void Harl::_error(void)
{
    cout << "[ ERROR ]" << endl << "This is unacceptable! I want to speak to t"\
        "he manager now." << endl;
}
