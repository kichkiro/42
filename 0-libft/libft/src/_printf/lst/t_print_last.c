/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:10:28 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/28 18:05:17 by kichkiro         ###   ########.fr       */
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
t_print	*t_print_last(t_print *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
