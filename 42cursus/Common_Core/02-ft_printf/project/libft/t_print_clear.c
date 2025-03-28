/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:11:20 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:10:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Deletes and frees the given node and every successor of that node, using the
	function ’del’ and free(3).
	Finally, the pointer to the list must be set to NULL.
 * @param lst
	The address of a pointer to a node.
 * @param del 
	The address of the function used to delete the content of the node.
 */
void	t_print_clear(t_print **lst, void (*del)(void*))
{
	t_print	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		t_print_delone(*lst, del);
		*lst = tmp;
	}
	free(tmp);
}
