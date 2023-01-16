/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:02:36 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/16 12:59:27 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * @brief 
	Create an array allocated with malloc(3), where each element corresponds to 
	'data' of each node of lst.
 * @param lst 
	Linked list.
 * @return 
	An array of integers.
 */
int	*t_stack_to_arr(t_stack *lst)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(t_stack_size(lst) * sizeof(int));
	i = 0;
	while (lst)
	{
		arr[i++] = lst->data;
		lst = lst->next;
	}
	return (arr);
}
