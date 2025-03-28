/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:08 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/18 22:13:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// SMF ------------------------------------------------------------------------>

Fixed::Fixed(void) : _fp_nbr(0) {}

Fixed::Fixed(const int val) : _fp_nbr(val << this->_f_bits) {}

Fixed::Fixed(const float val) : _fp_nbr(roundf(val *(1 << this->_f_bits))) {}

Fixed::Fixed(const Fixed &src) {
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rs) {
    if (this != &rs)
        this->_fp_nbr = rs.getRawBits();
    return *this;
}

bool Fixed::operator<(const Fixed &rs) const {
    return this->_fp_nbr < rs._fp_nbr ? true : false;
}

bool Fixed::operator>(const Fixed &rs) const {
    return this->_fp_nbr > rs._fp_nbr ? true : false;
}

bool Fixed::operator<=(const Fixed &rs) const {
    return this->_fp_nbr <= rs._fp_nbr ? true : false;
}

bool Fixed::operator>=(const Fixed &rs) const {
    return this->_fp_nbr >= rs._fp_nbr ? true : false;
}

bool Fixed::operator==(const Fixed &rs) const {
    return this->_fp_nbr == rs._fp_nbr ? true : false;
}

bool Fixed::operator!=(const Fixed &rs) const {
    return this->_fp_nbr != rs._fp_nbr ? true : false;
}

Fixed Fixed::operator+(const Fixed &rs) {
    return Fixed(this->toFloat() + rs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rs) {
    return Fixed(this->toFloat() - rs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rs) {
    return Fixed(this->toFloat() * rs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rs) {
    return Fixed(this->toFloat() / rs.toFloat());
}

Fixed &Fixed::operator++(void) {
    this->_fp_nbr++;
    return *this;
}

Fixed &Fixed::operator--(void) {
    this->_fp_nbr--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed res = *this;

    this->_fp_nbr++;
    return res;
}

Fixed Fixed::operator--(int) {
    Fixed res = *this;

    this->_fp_nbr--;
    return res;
}

Fixed::~Fixed(void) {}

// Methods -------------------------------------------------------------------->

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
    return a < b ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
    return a > b ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

int Fixed::getRawBits(void) const {
    return this->_fp_nbr;
}

void Fixed::setRawBits(int const raw) {
    this->_fp_nbr = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fp_nbr) / (1 << this->_f_bits);
}

int Fixed::toInt(void) const {
    return this->_fp_nbr >> this->_f_bits;
}

// Functions ------------------------------------------------------------------>

ostream &operator<<(ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
