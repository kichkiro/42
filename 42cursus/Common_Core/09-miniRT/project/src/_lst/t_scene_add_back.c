/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scene_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:47:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/12 21:37:33 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	t_scene_add_back(t_scene **lst, t_scene *new)
{
	if (lst && *lst)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		new->prev = *lst;
		(*lst)->next = new;
	}
	else
		*lst = new;
}
// *lst = (*lst)->next;
