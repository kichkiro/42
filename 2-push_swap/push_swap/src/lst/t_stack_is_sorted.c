/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_is_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:49:02 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/16 12:58:58 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * @brief
	Check if integers in lst are sorted.
 * @param lst 
	Linked list.
 * @return 
	TRUE if integers are sorted, otherwise FALSE.
 */
bool	t_stack_is_sorted(t_stack *lst)
{
	int	prev;

	prev = -2147483648;
	while (lst)
	{
		if (lst->data >= prev)
			prev = lst->data;
		else
			return (false);
		lst = lst->next;
	}
	return (true);
}
