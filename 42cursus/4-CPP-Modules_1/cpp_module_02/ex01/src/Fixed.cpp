/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:08 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:15:14 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// SMF ------------------------------------------------------------------------>

Fixed::Fixed(void) : _fp_nbr(0) {
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int val) : _fp_nbr(val << this->_f_bits) {
    cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float val) : _fp_nbr(roundf(val *(1 << this->_f_bits))) {
    cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &src) {
    *this = src;
    cout << "Copy constructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed &rs) {
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

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fp_nbr) / (1 << this->_f_bits);
}

int   Fixed::toInt(void) const {
    return this->_fp_nbr >> this->_f_bits;
}

// Functions ------------------------------------------------------------------>

ostream &operator<<(ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
