/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:53:57 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/16 12:59:05 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * @brief 
	Find max in lst.
 * @param lst 
	Linked list.
 * @return 
	Max.
 */
int	t_stack_max(t_stack *lst)
{
	int	max;

	max = MIN_INT;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}
