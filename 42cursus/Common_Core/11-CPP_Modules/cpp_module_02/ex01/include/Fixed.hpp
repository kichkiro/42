/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 23:05:01 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

// Class ---------------------------------------------------------------------->

class Fixed {
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &rs);
        ~Fixed(void);

        int  getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;

    private:
        int 			 _fp_nbr;
        static const int _f_bits = 8;
};

// Functions ------------------------------------------------------------------>

ostream &operator<<(ostream &os, const Fixed &fixed);
