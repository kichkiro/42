/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:44:38 by kichkiro          #+#    #+#             */
/*   Updated: 2023/11/02 18:13:42 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_sphere(char *line, t_scene *scene)
{
	t_sphere	*spere;

	spere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!spere)
		errors_handler("parser: malloc()", NULL, &scene);
	spere->origin = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	spere->diameter = get_value(&line, scene);
	spere->rgb = get_rgb(&line, scene);
	return ((void *)spere);
}

void	*parse_plane(char *line, t_scene *scene)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		errors_handler("parser: malloc()", NULL, &scene);
	plane->origin = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	plane->direction = get_coords(&line, scene);
	if (plane->direction->x > 1 || plane->direction->x < -1
		|| plane->direction->y > 1 || plane->direction->y < -1
		|| plane->direction->z > 1 || plane->direction->z < -1)
		errors_handler("parser: plane direction must be normalized in range \
			-1.0-1.0", NULL, &scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	plane->rgb = get_rgb(&line, scene);
	return ((void *)plane);
}

void	*parse_cylinder(char *line, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		errors_handler("parser: malloc()", NULL, &scene);
	cylinder->origin = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	cylinder->direction = get_coords(&line, scene);
	if (cylinder->direction->x > 1 || cylinder->direction->x < -1
		|| cylinder->direction->y > 1 || cylinder->direction->y < -1
		|| cylinder->direction->z > 1 || cylinder->direction->z < -1)
		errors_handler("parser: cylinder direction must be normalized in range \
			-1.0-1.0", NULL, &scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	cylinder->diameter = get_value(&line, scene);
	cylinder->height = get_value(&line, scene);
	cylinder->rgb = get_rgb(&line, scene);
	return ((void *)cylinder);
}
