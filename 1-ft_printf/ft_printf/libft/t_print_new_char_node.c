/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_new_char_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:05:07 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:10:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with the value of the parameter
	’content’. 
	The variable ’next’ is initialized to NULL.
 * @param content
	The content to create the node with.
 * @return 
	The new node.
 */
t_print	*t_print_new_char_node(char content)
{
	t_print	*lst;

	lst = malloc(sizeof(t_print));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}
