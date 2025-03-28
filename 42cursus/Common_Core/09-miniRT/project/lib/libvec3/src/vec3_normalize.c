/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:43:52 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:44:22 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*!
 * @brief
	Normalize a vector.
 * @param a
	The vector.
 * @return
	The normalized vector.
 * @note
	The normalized vector is found by dividing each component of the vector by
	its module.
 */
t_v3	v_normalize(t_v3 a)
{
	double	module;
	t_v3	norm;

	module = v_module(a);
	norm.x = a.x / module;
	norm.y = a.y / module;
	norm.z = a.z / module;
	return (norm);
}
