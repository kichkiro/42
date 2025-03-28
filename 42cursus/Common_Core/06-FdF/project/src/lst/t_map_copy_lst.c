/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_copy_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:56:16 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/11 13:58:00 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*!
 * @brief 
	This function creates a copy of a linked list of type t_map.
	The function allocates memory for a new node for each node in the original 
	linked list, copies the values of x, y, z, and col to the new node, and 
	links the new nodes together to form a new linked list.
 * @param original 
	Is a pointer to the first node in the original linked list.
 * @return 
	The new linked list is returned as a pointer to the first node (head).
 */
t_map	*t_map_copy_lst(t_map *original)
{
	t_map	*copy;
	t_map	*head;
	t_map	*tail;

	head = 0;
	tail = 0;
	while (original)
	{
		copy = (t_map *)malloc(sizeof(t_map));
		copy->x = original->x;
		copy->y = original->y;
		copy->z = original->z;
		copy->col = original->col;
		copy->next = 0;
		copy->prev = tail;
		if (!head)
			head = copy;
		if (tail)
			tail->next = copy;
		tail = copy;
		original = original->next;
	}
	return (head);
}
