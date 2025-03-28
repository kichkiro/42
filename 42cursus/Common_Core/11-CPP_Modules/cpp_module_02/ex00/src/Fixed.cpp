/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:08 by kichkiro          #+#    #+#             */
/*   Updated: 2023/08/02 08:41:58 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// SMF ------------------------------------------------------------------------>

Fixed::Fixed(void) : _fp_nbr(0) {
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &src) {
    *this = src;
    cout << "Copy constructor called" << endl;
}

Fixed &Fixed::operator = (const Fixed &rs) {
    if (this != &rs)
        this->_fp_nbr = rs.getRawBits();
    cout << "Copy assignment operator called" << endl;
    return *this;
}

Fixed::~Fixed(void) {
    cout << "Destructor called" << endl;
}

// Methods -------------------------------------------------------------------->

int Fixed::getRawBits(void) const {
    return this->_fp_nbr;
}

void Fixed::setRawBits(int const raw) {
    this->_fp_nbr = raw;
}
