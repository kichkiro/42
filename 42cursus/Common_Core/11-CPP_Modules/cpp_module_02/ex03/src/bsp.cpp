/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:43:46 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/19 17:09:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

bool approximatelyEqual(Fixed a, Fixed b, Fixed epsilon = 1) {
    return abs(a.toFloat() - b.toFloat()) <= epsilon.toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = 0.5f * abs((b.getX() - a.getX()) * (c.getY() - a.getY()) - 
        (c.getX() - a.getX()) * (b.getY() - a.getY()));
    Fixed areaPAB = 0.5f * abs((point.getX() - a.getX()) * (b.getY() - a.getY()) 
        - (b.getX() - a.getX()) * (point.getY() - a.getY()));
    Fixed areaPBC = 0.5f * abs((b.getX() - point.getX()) * (c.getY() - 
        point.getY()) - (c.getX() - point.getX()) * (b.getY() - point.getY()));
    Fixed areaPCA = 0.5f * abs((point.getX() - a.getX()) * (c.getY() - a.getY()) 
        - (c.getX() - a.getX()) * (point.getY() - a.getY()));

    return approximatelyEqual((areaPAB + areaPBC + areaPCA), areaABC);
}
