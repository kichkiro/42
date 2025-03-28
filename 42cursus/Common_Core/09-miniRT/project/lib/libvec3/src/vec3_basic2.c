/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basic2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:38:00 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/12 21:45:04 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*!
 * @brief
 	Add two vectors.
 * @param a
 	First vector.
 * @param b
 	Second vector.
 * @return
 	The sum of two vectors.
*/
t_v3	v_add_vec(t_v3 a, t_v3 b)
{
	return ((t_v3){a.x + b.x, a.y + b.y, a.z + b.z});
}

/*!
 * @brief
 	Subtract two vectors.
 * @param a
 	First vector.
 * @param b
 	Second vector.
 * @return
 	The difference of two vectors.
*/
t_v3	v_sub_vec(t_v3 a, t_v3 b)
{
	return ((t_v3){a.x - b.x, a.y - b.y, a.z - b.z});
}

/*!
 * @brief
	Moltiplicate two vectors.
 * @param a
	First vector.
 * @param b
	Second vector.
 * @return
	The product of two vectors.
 */
t_v3	v_mult_vec(t_v3 a, t_v3 b)
{
	return ((t_v3){a.x * b.x, a.y * b.y, a.z * b.z});
}
