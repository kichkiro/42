/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:00:59 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/17 12:50:20 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl *harl;

    harl = new Harl();
    harl->complain("DEBUG");
    harl->complain("INFO");
    harl->complain("WARNING");
    harl->complain("ERROR");
    harl->complain("NOT_VALID");
    delete harl;
    return 0;
}
