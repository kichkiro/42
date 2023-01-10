/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_set_to_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:57:45 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/28 18:08:25 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
