/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersec_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:51:28 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/30 19:02:35 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	intersec_cylinder_base(t_cylinder *cy, t_ray *ray, \
									t_intersec **isec, t_plane *pl)
{
	t_hit	hit;

	hit.dv = v_dot_product(ray->direction, *cy->direction);
	hit.t = v_dot_product(v_sub_vec(*pl->origin, ray->origin),
			*cy->direction) / hit.dv;
	if (hit.dv == 0.0)
		return (false);
	hit.p = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
	if (hit.t > (*isec)->min && hit.t < (*isec)->max && hit.t < (*isec)->nearest
		&& sqrtf(v_dot_product(v_sub_vec(hit.p, *pl->origin),
				v_sub_vec(hit.p, *pl->origin))) <= cy->diameter / 2)
	{
		(*isec)->has_intersec = true;
		(*isec)->nearest = hit.t;
		(*isec)->point = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
		(*isec)->color = (*cy->rgb);
		(*isec)->normal = v_unit(*cy->direction);
		return (true);
	}
	return (false);
}

static bool	intersec_cylinder_body2(t_hit hit, t_ray *ray, t_cylinder *cy, \
									t_intersec **isec)
{
	if (hit.t < (*isec)->nearest
		&& fabs(v_dot_product(hit.diff, *cy->direction)) <= (cy->height / 2))
	{
		(*isec)->has_intersec = true;
		(*isec)->nearest = hit.t;
		(*isec)->point = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
		(*isec)->color = (*cy->rgb);
		hit.dtop = v_dot_product(hit.diff, *cy->direction);
		hit.pcent = v_add_vec(*cy->origin, v_mult(*cy->direction, -hit.dtop));
		(*isec)->normal = v_unit(v_sub_vec((*isec)->point, hit.pcent));
		return (true);
	}
	return (false);
}

static bool	intersec_cylinder_body(t_ray *ray, t_cylinder *cy, \
									t_intersec **isec)
{
	t_hit	hit;

	hit.x = v_sub_vec(ray->origin, *cy->origin);
	hit.dv = v_dot_product(ray->direction, *cy->direction);
	hit.xv = v_dot_product(hit.x, *cy->direction);
	hit.a = pow(v_module(ray->direction), 2) - pow(hit.dv, 2);
	hit.hb = v_dot_product(hit.x, ray->direction) - (hit.dv * hit.xv);
	hit.c = pow(v_module(hit.x), 2) - pow(cy->diameter / 2, 2) - pow(hit.xv, 2);
	hit.dis = (hit.hb * hit.hb) - (hit.a * hit.c);
	if (hit.dis < 0.0 || hit.a == 0)
		return (false);
	hit.t = (-hit.hb - sqrt(hit.dis)) / hit.a;
	hit.p = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
	hit.diff = v_sub_vec(*cy->origin, hit.p);
	if (hit.t > (*isec)->nearest || hit.t < (*isec)->min | hit.t > (*isec)->max)
		return (false);
	return (intersec_cylinder_body2(hit, ray, cy, isec));
}

bool	intersec_cylinder(t_ray *ray, t_cylinder *cy, t_intersec **isec)
{
	t_plane	pl1;
	t_plane	pl2;
	bool	ret;

	pl1.origin = v_pointer(v_add_vec(*cy->origin, v_mult(*cy->direction,
					(cy->height / 2))));
	pl1.rgb = cy->rgb;
	pl1.direction = cy->direction;
	pl2.origin = v_pointer(v_sub_vec(*cy->origin, v_mult(*cy->direction,
					(cy->height / 2))));
	pl2.rgb = cy->rgb;
	pl2.direction = v_pointer(v_mult(*cy->direction, -1));
	if (intersec_cylinder_body(ray, cy, isec)
		|| intersec_cylinder_base(cy, ray, isec, &pl2)
		|| intersec_cylinder_base(cy, ray, isec, &pl1))
		ret = true;
	else
		ret = false;
	free(pl1.origin);
	free(pl2.origin);
	free(pl2.direction);
	return (ret);
}
