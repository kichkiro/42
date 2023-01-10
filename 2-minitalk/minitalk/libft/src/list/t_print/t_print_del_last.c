/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_del_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:08:22 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/28 18:05:23 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Delete last n nodes.
 * @param head 
	The address of a pointer to the first link of a list.
 * @param n 
	Number of last nodes to be deleted.
 */
void	t_print_del_last(t_print **head, size_t n)
{
	t_print	*last;
	t_print	*tmp;

	while (n--)
	{
		tmp = *head;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = 0;
		free(last);
	}
}
