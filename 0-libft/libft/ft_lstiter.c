/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:47:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:10:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Iterates the list ’lst’ and applies the function ’f’ on the content of each 
	node.
 * @param lst 
	The address of a pointer to a node.
 * @param f 
	The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_print *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
