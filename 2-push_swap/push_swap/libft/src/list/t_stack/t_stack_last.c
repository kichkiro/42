/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:13:57 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/28 18:09:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Returns the last node of the list.
 * @param lst
	The beginning of the list.
 * @return
	Last node of the list.	
 */
t_stack	*t_stack_last(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
