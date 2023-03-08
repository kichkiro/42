/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_move_to_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:03:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/11 17:11:39 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*!
 * @brief 
	Move the t_map pointer to the desired index.
 * @param map 
 	Pointer to the start of a t_map linked list.
 * @param index 
 	Index of the desired t_map element.
 * @return 
 	Pointer to the desired t_map element.
 */
t_map	*t_map_move_to_index(t_map *map, size_t index)
{
	while (--index && map->next)
		map = map->next;
	if (index)
	{
		map->x = 0;
		map->y = 0;
		map->z = 0;
		map->col = 0;
	}
	return (map);
}
