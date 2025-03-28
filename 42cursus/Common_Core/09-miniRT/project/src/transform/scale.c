/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:45:47 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/28 14:45:10 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	scale_sphere(t_sphere *sphere, int keycode)
{
	if (keycode == 59 || keycode == XK_slash)
		sphere->diameter += SCALE_RATIO;
	else
		sphere->diameter -= SCALE_RATIO;
}

void	scale_cylinder(t_cylinder *cylinder, int keycode)
{
	if (keycode == XK_MY_SEMICOLON)
		cylinder->height += SCALE_RATIO;
	else if (keycode == XK_period)
		cylinder->height -= SCALE_RATIO;
	else if (keycode == XK_comma)
		cylinder->diameter -= SCALE_RATIO;
	else
		cylinder->diameter += SCALE_RATIO;
}

void	scale(t_mlx_scene *mlx_scene, int keycode)
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
		scale_sphere((t_sphere *)(*scene)->data, keycode);
	else if ((*scene)->type == CYLINDER)
		scale_cylinder((t_cylinder *)(*scene)->data, keycode);
	t_scene_set_to_head(scene);
	render(&mlx_scene->mlx, (*scene));
	return ;
}
