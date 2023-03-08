/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:51:04 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/13 16:00:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*!
* @brief 
	Delete and frees the lst.
* @param lst 
	Linked list.
*/
void	t_map_free(t_map **lst)
{
	t_map	*tmp;

	tmp = 0;
	if (*lst)
	{
		t_map_set_to_head(lst);
		while ((*lst)->next)
		{
			*lst = (*lst)->next;
			tmp = (*lst)->prev;
			free(tmp);
			(*lst)->prev = 0;
		}
		free(*lst);
		*lst = 0;
	}
}
