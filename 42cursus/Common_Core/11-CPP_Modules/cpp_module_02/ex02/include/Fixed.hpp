/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 23:05:26 by kichkiro         ###   ########.fr       */
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
        bool   operator<(const Fixed &rs) const;
        bool   operator>(const Fixed &rs) const;
        bool   operator<=(const Fixed &rs) const;
        bool   operator>=(const Fixed &rs) const;
        bool   operator==(const Fixed &rs) const;
        bool   operator!=(const Fixed &rs) const;
        Fixed  operator+(const Fixed &rs);
        Fixed  operator-(const Fixed &rs);
        Fixed  operator*(const Fixed &rs);
        Fixed  operator/(const Fixed &rs);
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed  operator++(int);
        Fixed  operator--(int);
        ~Fixed(void);

        static const Fixed &min(Fixed const &a, Fixed const &b);
        static const Fixed &max(Fixed const &a, Fixed const &b);
        static       Fixed &min(Fixed &a, Fixed &b);
        static       Fixed &max(Fixed &a, Fixed &b);

        int   getRawBits(void) const;
        void  setRawBits(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;

    private:
        int 			 _fp_nbr;
        static const int _f_bits = 8;
};

// Functions ------------------------------------------------------------------>

ostream &operator<<(ostream &os, const Fixed &fixed);
