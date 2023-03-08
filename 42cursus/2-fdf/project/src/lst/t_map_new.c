/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:05:55 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/13 14:55:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a new node;
	The member variable ’data’ is initialized with the value of the parameter
	’data’;
	The variable ’next’ is initialized to NULL.
 * @param data 
	The data to create the node with.
 * @return 
	The new node.
 */
t_map	*t_map_new(int x, int y, int z, int col)
{
	t_map	*lst;

	lst = (t_map *)malloc(sizeof(t_map));
	if (!lst)
		return (0);
	lst->x = x;
	lst->y = y;
	lst->z = z;
	lst->col = col;
	lst->next = 0;
	lst->prev = 0;
	return (lst);
}
