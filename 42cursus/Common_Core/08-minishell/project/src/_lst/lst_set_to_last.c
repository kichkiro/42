/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_set_to_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:13:57 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/05 01:51:58 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Set lst to last node.
 * @param lst 
	Linked List.
 */
void	t_fd_set_to_last(t_fd **lst)
{
	if ((*lst) && (*lst)->next)
	{
		while ((*lst) && (*lst)->next)
			*lst = (*lst)->next;
	}
}
