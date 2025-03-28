/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:01:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 23:04:03 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Class ---------------------------------------------------------------------->

class Harl {
    public:
        Harl(void);
        ~Harl(void);

        void complain(string level);

    private:
        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);
};

typedef void (Harl:: *action)(void);
