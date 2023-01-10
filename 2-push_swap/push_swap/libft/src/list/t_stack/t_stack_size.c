/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:15:20 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/28 18:08:08 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Counts the number of nodes in a list.
 * @param lst 
	The beginning of the list
 * @return 
	The length of the list.
 */
int	t_stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->prev)
		lst = lst->prev;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
