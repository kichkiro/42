/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:57:10 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/12 21:45:27 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*!
 * @brief
 * @param a
 * @param n
 * @return
 */
t_v3	v_mult(t_v3 a, double n)
{
	return ((t_v3){a.x * n, a.y * n, a.z * n});
}

/*!
 * @brief
 * @param a
 * @param n
 * @return
 */
t_v3	v_div(t_v3 a, double n)
{
	return (v_mult(a, 1.0 / n));
}
