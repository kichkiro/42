/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:48:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:45:16 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*!
 * @brief
 	Rotate a vector around the X axis.
 * @param v
 	The vector.
 * @param angle
 	The angle of rotation.
 * @return
 	The rotated vector.
 * @note
 	The rotation of a vector around the X axis is found by the following
	formula:
		x' = x * 1
		y' = y * cos(angle) + z * -sin(angle)
		z' = y * sin(angle) + z * cos(angle)
*/
t_v3	v_rotate_x(t_v3 v, double angle)
{
	t_v3	new;
	double	rad;

	rad = angle * PI / 180;
	new.x = v.x * 1;
	new.y = v.y * cos(rad) + v.z * -sin(rad);
	new.z = v.y * sin(rad) + v.z * cos(rad);
	return (new);
}

/*!
 * @brief
 	Rotate a vector around the Y axis.
 * @param v
 	The vector.
 * @param angle
 	The angle of rotation.
 * @return
 	The rotated vector.
 * @note
 	The rotation of a vector around the Y axis is found by the following
	formula:
		x' = x * cos(angle) + z * sin(angle)
		y' = y * 1
		z' = x * -sin(angle) + z * cos(angle)
*/
t_v3	v_rotate_y(t_v3 v, double angle)
{
	t_v3	new;
	double	rad;

	rad = angle * PI / 180;
	new.x = v.x * cos(rad) + v.z * sin(rad);
	new.y = v.y * 1;
	new.z = v.x * -sin(rad) + v.z * cos(rad);
	return (new);
}

/*!
 * @brief
 	Rotate a vector around the Z axis.
 * @param v
 	The vector.
 * @param angle
 	The angle of rotation.
 * @return
 	The rotated vector.
 * @note
 	The rotation of a vector around the Z axis is found by the following
	formula:
		x' = x * cos(angle) + y * -sin(angle)
		y' = x * sin(angle) + y * cos(angle)
		z' = z * 1
*/
t_v3	v_rotate_z(t_v3 v, double angle)
{
	t_v3	new;
	double	rad;

	rad = angle * PI / 180;
	new.x = v.x * cos(rad) + v.y * -sin(rad);
	new.y = v.x * sin(rad) + v.y * cos(rad);
	new.z = v.z * 1;
	return (new);
}
