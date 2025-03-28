/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:58:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/02 19:51:59 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_lighting_obj(t_scene **scene)
{
	if ((*scene)->type == AMBIENT_LIGHTNING)
	{
		free(((t_ambient_lightning *)(*scene)->data)->rgb);
		free(((t_ambient_lightning *)(*scene)->data));
	}
	else if ((*scene)->type == LIGHT)
	{
		free(((t_light *)(*scene)->data)->origin);
		free(((t_light *)(*scene)->data)->rgb);
		free(((t_light *)(*scene)->data));
	}
}

static void	free_display_obj(t_scene **scene)
{
	if ((*scene)->type == CAMERA)
	{
		free(((t_camera *)(*scene)->data)->origin);
		free(((t_camera *)(*scene)->data)->direction);
		free(((t_camera *)(*scene)->data));
	}
}

static void	free_geometric_obj(t_scene **scene)
{
	if ((*scene)->type == SPHERE)
	{
		free(((t_sphere *)(*scene)->data)->origin);
		free(((t_sphere *)(*scene)->data)->rgb);
		free(((t_sphere *)(*scene)->data));
	}
	else if ((*scene)->type == PLANE)
	{
		free(((t_plane *)(*scene)->data)->origin);
		free(((t_plane *)(*scene)->data)->direction);
		free(((t_plane *)(*scene)->data)->rgb);
		free(((t_plane *)(*scene)->data));
	}
	else if ((*scene)->type == CYLINDER)
	{
		free(((t_cylinder *)(*scene)->data)->origin);
		free(((t_cylinder *)(*scene)->data)->direction);
		free(((t_cylinder *)(*scene)->data)->rgb);
		free(((t_cylinder *)(*scene)->data));
	}
}

void	t_scene_free(t_scene **scene)
{
	t_scene	*tmp;

	tmp = NULL;
	t_scene_set_to_head(scene);
	while ((*scene))
	{
		if ((*scene)->type == AMBIENT_LIGHTNING || (*scene)->type == LIGHT)
			free_lighting_obj(scene);
		else if ((*scene)->type == CAMERA)
			free_display_obj(scene);
		else if ((*scene)->type == SPHERE || (*scene)->type == PLANE || \
			(*scene)->type == CYLINDER)
			free_geometric_obj(scene);
		tmp = *scene;
		*scene = (*scene)->next;
		free(tmp);
		if (*scene)
			(*scene)->prev = NULL;
	}
}
