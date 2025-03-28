/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:27:21 by anvannin          #+#    #+#             */
/*   Updated: 2023/11/02 18:14:00 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*!
 * @brief
	This function checks if an intersection point is in shadow by casting a
	shadow ray from the intersection point to the light source.
 * @param scene
 	Pointer to the scene.
 * @param isec
 	Pointer to the intersection structure.
 * @param l
 	Lighting information.
 * @return
 	True if the intersection point is in shadow, false otherwise.
 */
static bool	render_shadow(t_scene *scene, t_intersec *isec, t_lighting l)
{
	t_light		*lg;
	t_intersec	*tmp_isec;

	lg = t_scene_get_light(scene);
	tmp_isec = (t_intersec *)malloc(sizeof(t_intersec));
	l.shadow_ray.origin = v_add_vec(isec->point, v_mult(isec->normal, EPSILON));
	l.shadow_ray.direction = v_sub_vec(*lg->origin, isec->point);
	l.len = v_module(l.shadow_ray.direction);
	l.shadow_ray.direction = v_unit(l.shadow_ray.direction);
	if (intersections(scene, l.shadow_ray, tmp_isec, l.len))
	{
		free(tmp_isec);
		return (true);
	}
	free(tmp_isec);
	return (false);
}

/*!
 * @brief
	This function calculates the lighting effects at an intersection point by
	considering ambient, diffuse, and specular reflections.
 * @param scene
	Pointer to the scene.
 * @param isec
	Pointer to the intersection structure.
 * @param l
	Lighting information.
 */
static void	render_object(t_scene *scene, t_intersec *isec, t_lighting l)
{
	t_ambient_lightning	*al;
	t_camera			*cam;
	t_light				*lg;

	al = t_scene_get_ambient_light(scene);
	cam = t_scene_get_camera(scene);
	lg = t_scene_get_light(scene);
	l.light = v_unit(v_sub_vec((*lg->origin), isec->point));
	l.dfactor = fmax(0.0, v_dot_product(isec->normal, l.light));
	l.diffuse = v_mult(rgb_to_v3(*al->rgb), l.dfactor * 0.6);
	l.viewdir = v_unit(v_sub_vec((*cam->origin), isec->point));
	l.reflect = v_unit(v_sub_vec(v_mult(isec->normal,
					(2.0 * v_dot_product(l.light, isec->normal))), l.light));
	l.sfactor = pow(fmax(v_dot_product(l.viewdir, l.reflect), 0.0), 32);
	l.specular = v_mult(rgb_to_v3(*al->rgb), l.sfactor * 0.5);
	l.color = v_add_vec(v_add_vec(l.ambient, l.diffuse), l.specular);
	isec->color = v3_to_rgb(v_mult_vec(l.color, rgb_to_v3(isec->color)));
}

/*!
 * @brief
	This function calculates the overall lighting at an intersection point:
	- It first computes the ambient lighting and checks for shadows.
	- If the point is in shadow, it attenuates the color with ambient light.
	- If not, it calls `render_object` to calculate the full lighting effects
	  (ambient, diffuse, and specular) and updates the isec structure.
	- The resulting color is clamped to the [0, 255] range for RGB components.
 * @param scene
 	Pointer to the scene.
 * @param isec
 	Pointer to the intersection structure.
 */
void	lighting(t_scene *scene, t_intersec *isec)
{
	t_lighting			l;
	t_ambient_lightning	*al;

	al = t_scene_get_ambient_light(scene);
	l.ambient = v_mult(rgb_to_v3(*al->rgb), al->ratio);
	if (render_shadow(scene, isec, l))
		isec->color = v3_to_rgb(v_mult_vec(l.ambient, rgb_to_v3(isec->color)));
	else
		render_object(scene, isec, l);
	isec->color.red = fmax(0, fmin(isec->color.red, 255));
	isec->color.green = fmax(0, fmin(isec->color.green, 255));
	isec->color.blue = fmax(0, fmin(isec->color.blue, 255));
}
