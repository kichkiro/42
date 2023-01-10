/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:42:34 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:10:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Iterates the list ’lst’ and applies the function ’f’ on the content of each 
	node. 
	Creates a new list resulting of the successive applications of the function 
	’f’. 
	The ’del’ function is used to delete the content of a node if needed.
 * @param lst 
	The address of a pointer to a node.
 * @param f 
	The address of the function used to iterate on the list.
 * @param del 
	The address of the function used to delete the content of a node if needed.
 * @return 
	The new list.
	NULL if the allocation fails.
 */
t_print	*ft_lstmap(t_print *lst, void *(*f)(void *), void (*del)(void *))
{
	t_print	*lst1;
	t_print	*lst2;
	t_print	*lst3;

	lst1 = lst;
	lst2 = 0;
	while (lst)
	{
		lst3 = ft_lstnew(f(lst->content));
		if (!lst3)
		{
			t_print_clear(&lst2, del);
			return (0);
		}
		t_print_add_back(&lst2, lst3);
		lst = lst -> next;
	}
	lst = lst1;
	return (lst2);
}
