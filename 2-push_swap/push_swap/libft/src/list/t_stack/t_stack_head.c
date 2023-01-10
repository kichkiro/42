/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:38:44 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/28 18:10:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	Search and return first node of lst.
 * @param lst 
	Linked list.
 * @return 
	Head of the lst.
 */
t_stack	*t_stack_head(t_stack *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
