/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:38:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/28 23:25:22 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	intersec_sphere2(t_hit hit, t_ray *ray, t_sphere *sp,
		t_intersec **isec)
{
	if (hit.t > (*isec)->nearest || hit.t < (*isec)->min
		|| hit.t > (*isec)->max)
		return (false);
	(*isec)->has_intersec = true;
	(*isec)->nearest = hit.t;
	(*isec)->point = v_add_vec(ray->origin, v_mult(ray->direction, hit.t));
	(*isec)->color = (*sp->rgb);
	(*isec)->normal = v_unit(v_sub_vec((*isec)->point, (*sp->origin)));
	return (true);
}

bool	intersec_sphere(t_ray *ray, t_sphere *sp, t_intersec **isec)
{
	t_hit	hit;

	hit.x = v_sub_vec(ray->origin, (*sp->origin));
	hit.a = v_dot_product(ray->direction, ray->direction);
	hit.hb = v_dot_product(hit.x, ray->direction);
	hit.c = v_dot_product(hit.x, hit.x) - (sp->diameter / 2 * sp->diameter / 2);
	hit.dis = hit.hb * hit.hb - (hit.a * hit.c);
	if (hit.dis < 0)
		return (false);
	hit.sdis = sqrt(hit.dis);
	hit.t = (-hit.hb - hit.sdis) / (hit.a);
	hit.t2 = (-hit.hb + hit.sdis) / (hit.a);
	if (hit.t > hit.t2)
		hit.t = hit.t2;
	if (hit.t < 0)
	{
		hit.t = hit.t2;
		if (hit.t < 0)
			return (false);
	}
	return (intersec_sphere2(hit, ray, sp, isec));
}

bool	intersec_plane(t_ray *ray, t_plane *pl, t_intersec **isec)
{
	double	t;
	double	denom;
	t_v3	v;

	denom = v_dot_product(*pl->direction, ray->direction);
	if (fabs(denom) > EPSILON)
	{
		v = v_sub_vec((*pl->origin), ray->origin);
		t = v_dot_product(v, (*pl->direction)) / denom;
		if (t > EPSILON && t < (*isec)->nearest)
		{
			(*isec)->has_intersec = true;
			(*isec)->nearest = t;
			(*isec)->point = v_add_vec(ray->origin, v_mult(ray->direction, t));
			(*isec)->normal = (*pl->direction);
			(*isec)->color = (*pl->rgb);
			return (true);
		}
	}
	return (false);
}

void	intersec_init(t_intersec **isec)
{
	(*isec)->has_intersec = false;
	(*isec)->nearest = INFINITY;
	(*isec)->color = (t_rgb){0, 0, 0};
	(*isec)->min = EPSILON;
	(*isec)->max = INFINITY;
}

bool	intersections(t_scene *scene, t_ray ray, t_intersec *isec, double len)
{
	t_scene_set_to_head(&scene);
	intersec_init(&isec);
	while (scene)
	{
		if (scene->type == SPHERE)
			intersec_sphere(&ray, (t_sphere *)scene->data, &isec);
		else if (scene->type == PLANE)
			intersec_plane(&ray, (t_plane *)scene->data, &isec);
		else if (scene->type == CYLINDER)
			intersec_cylinder(&ray, (t_cylinder *)scene->data, &isec);
		if (len && isec->has_intersec && isec->nearest < len)
			return (true);
		scene = scene->next;
	}
	return (false);
}
