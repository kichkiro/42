/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_set_to_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:57:45 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/16 12:59:21 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * @brief 
	Set lst to first node.
 * @param lst 
	Linked List.
 */
void	t_stack_set_to_head(t_stack **lst)
{
	while ((*lst)->prev)
		*lst = (*lst)->prev;
}
