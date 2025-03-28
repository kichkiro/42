/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_adv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:54:13 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:44:55 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*!
 * @brief
	Distance between two points.
 * @param a
 	First point.
 * @param b
 	Second point.
 * @return
 	The vector between two points.
*/
float	v_distance(t_v3 a, t_v3 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)));
}

/*!
 * @brief
 	Find the dot product of two vectors.
 * @param a
 	First vector.
 * @param b
 	Second vector.
 * @return
	The dot product of two vectors.
 * @note
 	The dot product or scalar product is an algebraic operation that takes two
	equal-length sequences of numbers (usually coordinate vectors), and returns
	a single number.
*/
double	v_dot_product(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/*!
 * @brief
 	Find the cross product of two vectors.
 * @param a
 	First vector.
 * @param b
 	Second vector.
 * @return
 	The cross product of two vectors.
 * @note
 	The cross product of two vectors a and b is a vector that is perpendicular
	to both a and b, and thus normal to the plane containing them.
*/
t_v3	v_cross(t_v3 a, t_v3 b)
{
	return ((t_v3){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	});
}

t_v3	v_unit(t_v3 a)
{
	return (v_div(a, v_module(a)));
}

/*!
 * @brief
	Module of a vector.
 * @param a
 	The vector.
 * @return
 	The module of the vector.
 * @note
 	The module of a vector is found by the square root of the dot product of the
	vector by itself.
*/
double	v_module(t_v3 a)
{
	return (sqrt(v_dot_product(a, a)));
}
