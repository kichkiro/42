/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:57:45 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:10:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Takes as a parameter a node and frees the memory of the node’s content using
	the function ’del’ given as a parameter and free the node. 
	The memory of ’next’ must not be freed.
 * @param lst 
	The node to free.
 * @param del
	The address of the function used to delete the content.
 */
void	t_print_delone(t_print *lst, void (*del)(void*))
{
	del(lst);
}
