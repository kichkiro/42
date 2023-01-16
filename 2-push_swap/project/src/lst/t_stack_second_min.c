/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_second_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:56:49 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/16 12:59:18 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * @brief 
	Find the second min.
 * @param lst 
	Linked list.
 * @param min 
	Min of lst.
 * @return 
	Second min.
 */
int	t_stack_second_min(t_stack *lst, int min)
{
	int	second_min;

	second_min = MAX_INT;
	while (lst)
	{
		if (lst->data < second_min && lst->data != min)
			second_min = lst->data;
		lst = lst->next;
	}
	return (second_min);
}
