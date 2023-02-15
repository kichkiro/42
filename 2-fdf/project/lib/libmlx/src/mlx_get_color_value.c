/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_color_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/07/31 19:01:33 by CharlieRoot       #+#    #+#             */
/*   Updated: 2023/01/19 11:01:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_get_color_value(t_xvar *xvar, int color)
{
	return (mlx_int_get_good_color(xvar, color));
}

int	mlx_int_get_good_color(t_xvar *xvar, int color)
{
	XColor	xc;

	if (xvar->depth >= 24)
		return (color);
	xc.red = (color >> 8) & 0xFF00;
	xc.green = color & 0xFF00;
	xc.blue = (color << 8) & 0xFF00;
	xc.pixel = ((xc.red >> (16 - xvar->decrgb[1])) << xvar->decrgb[0]) + \
		((xc.green >> (16 - xvar->decrgb[3])) << xvar->decrgb[2]) + \
		((xc.blue >> (16-xvar->decrgb[5])) << xvar->decrgb[4]);
	return (xc.pixel);
}
