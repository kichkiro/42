/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:46:37 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/28 17:32:49 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	rotate_cylinder_side(t_cylinder *cylinder, int keycode)
{
	if (cylinder->direction->y == 1 || cylinder->direction->y == -1)
		return (false);
	if (cylinder->direction->x == 1)
	{
		cylinder->direction->x = 0;
		cylinder->direction->z = 1;
	}
	else
	{
		cylinder->direction->x = 1;
		cylinder->direction->z = 0;
	}
	return (true);
}

static bool	rotate_cylinder(t_cylinder *cylinder, int keycode)
{
	if (keycode == XK_i || keycode == XK_k)
	{
		if (cylinder->direction->x == 1 || cylinder->direction->x == -1)
			return (false);
		if (cylinder->direction->y == 1)
		{
			cylinder->direction->y = 0;
			cylinder->direction->z = 1;
		}
		else
		{
			cylinder->direction->y = 1;
			cylinder->direction->z = 0;
		}
		return (true);
	}
	else
		return (rotate_cylinder_side(cylinder, keycode));
}

void	rotate_camera(t_mlx_scene *mlx_scene, int keycode)
{
	t_camera	*camera;

	camera = t_scene_get_camera(mlx_scene->scene);
	if (keycode == XK_t)
		(*camera).w.y -= ROTATION_CAMERA_RATIO;
	else if (keycode == XK_g)
		(*camera).w.y += ROTATION_CAMERA_RATIO;
	else if (keycode == XK_f)
		(*camera).w.x -= ROTATION_CAMERA_RATIO;
	else
		(*camera).w.x += ROTATION_CAMERA_RATIO;
	render(&mlx_scene->mlx, mlx_scene->scene);
}

void	rotate(t_mlx_scene *mlx_scene, int keycode)
{
	bool		rot;
	t_scene		**scene;

	scene = &mlx_scene->scene;
	t_scene_set_to_head(scene);
	while (scene && *scene && (*scene)->next)
	{
		if ((*scene)->type == CYLINDER)
			break ;
		*scene = (*scene)->next;
	}
	if ((*scene)->type == CYLINDER)
		rot = rotate_cylinder((t_cylinder *)(*scene)->data, keycode);
	t_scene_set_to_head(scene);
	if (rot)
		render(&mlx_scene->mlx, (*scene));
	return ;
}
