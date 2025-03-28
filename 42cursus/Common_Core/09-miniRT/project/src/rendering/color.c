/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:29:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/17 21:09:50 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*!
 * @brief
	Converts a t_rgb structure to an int.
 * @param rgb
	RGB structure.
 * @return
	Integer color.
 * @note
	The colors are stored in separate integer variables inside the structure.
	We shift the bits of each color by the appropriate number of bits
	(red by 16, green by 8, and blue by 0),
	and then combine them using bitwise OR (|).
	The resulting integer color represents the RGB value.
*/
int	rgb_to_int(t_rgb *rgb)
{
	return (((int)rgb->red << 16) | ((int)rgb->green << 8) | (int)rgb->blue);
}

/*!
 * @brief
 * @param red
 * @param green
 * @param blue
 * @return
 */
int	rgb_to_int2(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

/*!
 * @brief
 	Print the RGB values of a t_rgb structure as integers.
 * @param rgb
	RGB structure.
*/
void	print_rgb_int(t_rgb *rgb)
{
	printf("%lf\t%lf\t%lf\n", rgb->red, rgb->green, rgb->blue);
}

/*!
 * @brief
	Print the RGB values of a t_rgb structure as hexadecimal.
 * @param rgb
	RGB structure.
*/
void	print_rgb_hex(t_rgb *rgb)
{
	printf("0xFF%X\n", rgb_to_int2((int)rgb->red, (int)rgb->green,
			(int)rgb->blue));
}

t_rgb	v3_to_rgb(t_v3 v)
{
	t_rgb	rgb;

	rgb.red = v.x;
	rgb.green = v.y;
	rgb.blue = v.z;
	return (rgb);
}
