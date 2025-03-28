/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:52:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/28 15:37:21 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	traslate_sphere(t_sphere *sphere, int keycode)
{
	if (keycode == XK_Shift_R)
		sphere->origin->y += TRASTLATION_RATIO;
	else if (keycode == XK_Control_R)
		sphere->origin->y -= TRASTLATION_RATIO;
	else if (keycode == XK_Up)
		sphere->origin->z += TRASTLATION_RATIO;
	else if (keycode == XK_Right)
		sphere->origin->x -= TRASTLATION_RATIO;
	else if (keycode == XK_Down)
		sphere->origin->z -= TRASTLATION_RATIO;
	else
		sphere->origin->x += TRASTLATION_RATIO;
}

static void	traslate_cylinder(t_cylinder *cylinder, int keycode)
{
	if (keycode == XK_Shift_R)
		cylinder->origin->y += TRASTLATION_RATIO;
	else if (keycode == XK_Control_R)
		cylinder->origin->y -= TRASTLATION_RATIO;
	else if (keycode == XK_Up)
		cylinder->origin->z += TRASTLATION_RATIO;
	else if (keycode == XK_Right)
		cylinder->origin->x -= TRASTLATION_RATIO;
	else if (keycode == XK_Down)
		cylinder->origin->z -= TRASTLATION_RATIO;
	else
		cylinder->origin->x += TRASTLATION_RATIO;
}

void	traslate_camera(t_mlx_scene *mlx_scene, int keycode)
{
	t_camera	*camera;

	camera = t_scene_get_camera(mlx_scene->scene);
	if (keycode == XK_w)
		camera->origin->z += TRASTLATION_RATIO;
	else if (keycode == XK_s)
		camera->origin->z -= TRASTLATION_RATIO;
	else if (keycode == XK_a)
		camera->origin->x += TRASTLATION_RATIO;
	else if (keycode == XK_d)
		camera->origin->x -= TRASTLATION_RATIO;
	else if (keycode == XK_q)
		camera->origin->y += TRASTLATION_RATIO;
	else
		camera->origin->y -= TRASTLATION_RATIO;
	render(&mlx_scene->mlx, mlx_scene->scene);
}

void	traslate(t_mlx_scene *mlx_scene, int keycode)
{
	t_scene		**scene;

	scene = &mlx_scene->scene;
	t_scene_set_to_head(scene);
	while (scene && *scene && (*scene)->next)
	{
		if ((*scene)->type == SPHERE || (*scene)->type == CYLINDER)
			break ;
		*scene = (*scene)->next;
	}
	if ((*scene)->type == SPHERE)
		traslate_sphere((t_sphere *)(*scene)->data, keycode);
	else if ((*scene)->type == CYLINDER)
		traslate_cylinder((t_cylinder *)(*scene)->data, keycode);
	t_scene_set_to_head(scene);
	render(&mlx_scene->mlx, mlx_scene->scene);
	return ;
}
