/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:46:26 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/28 18:50:11 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*parse_ambient_lightning(char *line, t_scene *scene)
{
	t_ambient_lightning	*am_light;

	am_light = (t_ambient_lightning *)malloc(sizeof(t_ambient_lightning));
	if (!am_light)
		errors_handler("parser: malloc()", NULL, &scene);
	am_light->ratio = get_value(&line, scene);
	if (am_light->ratio < 0 || am_light->ratio > 1)
		errors_handler("parser: ambient lighting ratio must be in range \
			0.0-1.0", NULL, &scene);
	if (am_light->ratio < 0.01)
		am_light->ratio = 0.01;
	while (line && *line && (ft_isdigit(*line) || *line == 46))
		line++;
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	am_light->rgb = get_rgb(&line, scene);
	am_light->rgb->red /= 255;
	am_light->rgb->green /= 255;
	am_light->rgb->blue /= 255;
	return ((void *)am_light);
}

void	*parse_light(char *line, t_scene *scene)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		errors_handler("parser: malloc()", NULL, &scene);
	light->origin = get_coords(&line, scene);
	while (line && *line && (*line == 9 || *line == 32))
		line++;
	light->brightness = get_value(&line, scene);
	if (light->brightness < 0 || light->brightness > 1)
		errors_handler("parser: light brightness must be in range 0.0-1.0",
			NULL, &scene);
	if (light->brightness < 0.01)
		light->brightness = 0.01;
	light->rgb = get_rgb(&line, scene);
	light->rgb->red /= 255;
	light->rgb->green /= 255;
	light->rgb->blue /= 255;
	return ((void *)light);
}
