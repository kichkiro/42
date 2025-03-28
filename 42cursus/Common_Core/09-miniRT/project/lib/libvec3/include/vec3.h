/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:27:32 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:45:34 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

// Libraries ------------------------------------------------------------------>

# include <stdlib.h>
# include <math.h>

// Defines -------------------------------------------------------------------->

# define PI 3.14159265358979323846

// Structures ----------------------------------------------------------------->

typedef struct s_v3
{
	double	x;
	double	y;
	double	z;
}	t_v3;

// Functions ------------------------------------------------------------------>

t_v3	v_mult(t_v3 a, double n);
t_v3	v_div(t_v3 a, double n);

t_v3	v_add_vec(t_v3 a, t_v3 b);
t_v3	v_sub_vec(t_v3 a, t_v3 b);
t_v3	v_mult_vec(t_v3 a, t_v3 b);

float	v_distance(t_v3 a, t_v3 b);
double	v_module(t_v3 a);
double	v_dot_product(t_v3 a, t_v3 b);
t_v3	v_cross(t_v3 a, t_v3 b);
t_v3	v_unit(t_v3 a);
t_v3	v_normalize(t_v3 a);

double	v_cos(t_v3 a, t_v3 b);
double	v_sin(t_v3 a, t_v3 b);

t_v3	v_rotate_x(t_v3 v, double angle);
t_v3	v_rotate_y(t_v3 v, double angle);
t_v3	v_rotate_z(t_v3 v, double angle);

t_v3	*v_pointer(t_v3 v);

#endif
