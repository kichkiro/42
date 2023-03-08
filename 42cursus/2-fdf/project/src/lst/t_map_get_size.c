/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_get_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:52:36 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/11 20:15:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	t_map_get_size_x(t_map *map)
{
	int	x;

	x = 1.0;
	while (map->next->x)
	{
		x++;
		map = map->next;
	}
	return (x);
}

int	t_map_get_size_y(t_map *map)
{
	int	x;
	int	y;
	int	i;

	x = t_map_get_size_x(map);
	y = 1.0;
	i = 0;
	while (map->next)
	{
		if (i == x)
		{
			y++;
			i = 1;
		}
		map = map->next;
		i++;
	}
	return (y);
}
