/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_rgb_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/07/31 16:52:42 by CharlieRoot       #+#    #+#             */
/*   Updated: 2023/01/19 11:14:52 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

/*!
 * @brief
	TrueColor Visual is needed to have *_mask correctly set
 * @param xvar 
 * @return 
 */
int	mlx_int_rgb_conversion(t_xvar *xvar)
{
	bzero(xvar->decrgb, sizeof(int) * 6);
	while (!(xvar->visual->red_mask & 1))
	{
		xvar->visual->red_mask >>= 1;
		xvar->decrgb[0]++;
	}
	while (xvar->visual->red_mask & 1)
	{
		xvar->visual->red_mask >>= 1;
		xvar->decrgb[1]++;
	}
	while (!(xvar->visual->green_mask & 1))
	{
		xvar->visual->green_mask >>= 1;
		xvar->decrgb[2]++;
	}
	while (xvar->visual->green_mask & 1)
	{
		xvar->visual->green_mask >>= 1;
		xvar->decrgb[3]++;
	}
	while (!(xvar->visual->blue_mask & 1))
	{
		xvar->visual->blue_mask >>= 1; 
		xvar->decrgb[4]++;
	}
	while (xvar->visual->blue_mask & 1)
	{
		xvar->visual->blue_mask >>= 1; 
		xvar->decrgb[5]++;
	}
}
