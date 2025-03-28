/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:48:57 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/16 12:59:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * @brief 
	Find min in lst.
 * @param lst 
	Linked list.
 * @return 
	Min.
 */
int	t_stack_min(t_stack *lst)
{
	int	min;

	min = MAX_INT;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}
