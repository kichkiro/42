/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:47:39 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/29 14:25:38 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Delete and frees the lst.
 * @param lst 
	Linked list.
 */
void	t_stack_free(t_stack **lst)
{
	t_stack	*tmp;

	tmp = 0;
	if (*lst)
	{
		t_stack_set_to_head(lst);
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
