/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_del_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:32:17 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/28 18:11:23 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Delete last node.
 * @param lst 
	Linked list.
 */
void	t_stack_del_last(t_stack **lst)
{
	*lst = t_stack_last(*lst);
	*lst = (*lst)->prev;
	free((*lst)->next);
	(*lst)->next = 0;
}
