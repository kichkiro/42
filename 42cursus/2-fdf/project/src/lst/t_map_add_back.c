/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:43:48 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/12 23:09:44 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*!
 * @brief 
    Adds the node ’new’ at the end of the list.
 * @param lst 
	Linked list.
 * @param new 
	The address of a pointer to the node to be added to the list.
 */
void	t_map_add_back(t_map **lst, t_map *new_node)
{
	t_map	*tmp;

	tmp = 0;
	if (*lst)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new_node;
		tmp = *lst;
		*lst = (*lst)->next;
		(*lst)->prev = tmp;
	}
	else
		*lst = new_node;
}
