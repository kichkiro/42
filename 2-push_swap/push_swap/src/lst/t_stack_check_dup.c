/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_check_dup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:51:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/16 12:58:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * @brief 
	Check if there are duplicates in lst.
 * @param lst 
	Linked list.
 * @return 
	TRUE if there is a duplicate, FALSE otherwise.
 */
bool	t_stack_check_dup(t_stack *lst)
{
	int		n;
	t_stack	*tmp;

	t_stack_set_to_head(&lst);
	tmp = 0;
	while (lst)
	{
		t_stack_add_back(&tmp, t_stack_new(lst->data));
		lst = lst->next;
	}
	t_stack_set_to_head(&tmp);
	while (tmp->next)
	{
		tmp = tmp->next;
		n = tmp->prev->data;
		free(tmp->prev);
		tmp->prev = 0;
		if (t_stack_n_is_inside(tmp, n))
		{
			t_stack_free(&tmp);
			return (true);
		}
	}
	t_stack_free(&tmp);
	return (false);
}
