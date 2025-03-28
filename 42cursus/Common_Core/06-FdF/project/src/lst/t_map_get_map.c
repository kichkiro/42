/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:27:10 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/15 10:36:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	atoi_hex(char *hex)
{
	int	decimal;
	int	val;
	int	len;

	if (!*hex)
		return (0xffffff);
	decimal = 0;
	len = ft_strlen(hex) - 1;
	while (*hex)
	{
		if (*hex >= '0' && *hex <= '9')
			val = *hex - 48;
		else if (*hex >= 'a' && *hex <= 'f')
			val = *hex - 97 + 10;
		else if (*hex >= 'A' && *hex <= 'F')
			val = *hex - 65 + 10;
		decimal += val * pow(16, len--);
		hex++;
	}
	return (decimal);
}

static void	get_coords(char *line, int x, int y, t_map **map)
{
	char	*z_s;
	char	*col;

	while (*line)
	{
		z_s = (char *)ft_calloc(11, sizeof(char));
		col = (char *)ft_calloc(9, sizeof(char));
		while (*line && *line == 32)
			line++;
		while (*line && *line != 32 && *line != 44 && *line != 10)
			z_s = ft_char_append(z_s, *line++, true);
		if (*line == 44)
		{
			while (*line++ && *line != 32 && *line != 10)
				col = ft_char_append(col, *line, true);
		}
		if (*line && *line != 10 && line++)
			t_map_add_back(map, t_map_new(x++, y, ft_atoi(z_s), atoi_hex(col)));
		free(z_s);
		free(col);
		if (*line == 10 || !*line)
			break ;
	}
}

/*!
 * @brief 
	This function reads a file and converts it into a t_map structure.
 * @param file 
	The name of the file to be processed.
 * @return 
	A pointer to the t_map structure that contains the information from the 
	file.
 */
t_map	*t_map_get_map(char *file)
{
	t_map	*map;
	int		fd;
	char	*line;
	size_t	y;
	size_t	x;

	map = 0;
	fd = open(file, O_RDONLY);
	x = 0;
	y = 0;
	while (true)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		get_coords(line, x, y, &map);
		ft_free((void **)&line);
		y++;
	}
	t_map_set_to_head(&map);
	return (map);
}
