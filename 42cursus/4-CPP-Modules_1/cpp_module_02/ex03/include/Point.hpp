/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:44:06 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/19 17:06:54 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Libraries ------------------------------------------------------------------>

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

using std::cout;
using std::endl;

// Class ---------------------------------------------------------------------->

class Point {
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &src);
        Point operator=(const Point &rs);
        ~Point(void);

        float getX(void) const;
        float getY(void) const;

    private:
        const Fixed _x;
        const Fixed _y;
};
