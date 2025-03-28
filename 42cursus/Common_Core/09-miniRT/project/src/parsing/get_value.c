/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:07:49 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/28 16:57:44 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	get_value(char **line, t_scene *scene)
{
	char	*tmp;
	double	value;

	tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		errors_handler("parser: calloc()", NULL, &scene);
	while (line && *line && (**line == 9 || **line == 32))
		(*line)++;
	while (line && *line && **line && **line != 44 && **line != 32 && \
		**line != 9)
	{
		tmp = ft_char_append(tmp, **line, true);
		(*line)++;
	}
	if (line && *line && **line)
		(*line)++;
	value = ft_atof(tmp);
	ft_free((void **)&tmp);
	return (value);
}

t_v3	*get_coords(char **line, t_scene *scene)
{
	t_v3	*coords;

	coords = (t_v3 *)malloc(sizeof(t_v3));
	if (!coords)
		errors_handler("parser: malloc()", NULL, &scene);
	while (line && *line && (**line == 9 || **line == 32))
		(*line)++;
	coords->x = get_value(line, scene);
	coords->y = get_value(line, scene);
	coords->z = get_value(line, scene);
	return (coords);
}

t_rgb	*get_rgb(char **line, t_scene *scene)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		errors_handler("parser: malloc()", NULL, &scene);
	while (line && *line && (**line == 9 || **line == 32))
		(*line)++;
	rgb->red = get_value(line, scene);
	rgb->green = get_value(line, scene);
	rgb->blue = get_value(line, scene);
	if (rgb->red < 0 || rgb->red > 255 || rgb->green < 0 || rgb->green > 255 \
		|| rgb->blue < 0 || rgb->blue > 255)
		errors_handler("parser: rgb value must be in range 0-255", NULL,
			&scene);
	return (rgb);
}
