/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:43:33 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/19 17:06:49 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// SFM ------------------------------------------------------------------------>

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &src) {
    *this = src;
}

Point Point::operator=(const Point &rs) {
    if (this == &rs)
        return *this;
    Point ret(rs.getX(), rs.getY());
    
    return ret;
}

Point::~Point(void) {}


// Methods -------------------------------------------------------------------->

float Point::getX(void) const {
    return this->_x.toFloat();
}

float Point::getY(void) const {
    return this->_y.toFloat();
}

