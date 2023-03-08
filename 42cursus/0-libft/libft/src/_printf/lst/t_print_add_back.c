/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:54:41 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/28 18:05:50 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Adds the node ’new’ at the end of the list.
 * @param lst 
	The address of a pointer to the first link of a list.
 * @param new 
	The address of a pointer to the node to be added to the list.
 */
void	t_print_add_back(t_print **lst, t_print *new)
{
	t_print	*last;

	last = t_print_last(*lst);
	if (last)
		last->next = new;
	else
		*lst = new;
}
