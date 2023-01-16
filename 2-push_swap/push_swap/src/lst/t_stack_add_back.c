/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:11:34 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/16 12:58:35 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * @brief 
	Adds the node ’new’ at the end of the list.
 * @param lst 
	Linked list.
 * @param new 
	The address of a pointer to the node to be added to the list.
 */
void	t_stack_add_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*tmp;

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
