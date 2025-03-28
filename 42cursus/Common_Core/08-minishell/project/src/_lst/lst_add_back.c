/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:11:34 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/08 23:37:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Adds the node ’new’ at the end of the list.
 * @param lst 
	Linked list.
 * @param new_node 
	The address of a pointer to the node to be added to the list.
 */
void	t_var_add_back(t_var **lst, t_var *new_node)
{
	t_var	*tmp;

	tmp = 0;
	if (*lst)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new_node;
		tmp = *lst;
		*lst = (*lst)->next;
		(*lst)->prev = tmp;
	}
	else
		*lst = new_node;
}

/*!
 * @brief 
	Adds the node ’new’ at the end of the list.
 * @param lst 
	Linked list.
 * @param new_node 
	The address of a pointer to the node to be added to the list.
 */
void	t_cmd_add_back(t_cmd **lst, t_cmd *new_node)
{
	t_cmd	*tmp;

	tmp = 0;
	if (*lst)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new_node;
		tmp = *lst;
		*lst = (*lst)->next;
		(*lst)->prev = tmp;
	}
	else
		*lst = new_node;
}

/*!
 * @brief 
	Adds the node ’new’ at the end of the list.
 * @param lst 
	Linked list.
 * @param new_node 
	The address of a pointer to the node to be added to the list.
 */
void	t_fd_add_back(t_fd **lst, t_fd *new_node)
{
	t_fd	*tmp;

	tmp = 0;
	if (*lst)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new_node;
		tmp = *lst;
		*lst = (*lst)->next;
		(*lst)->prev = tmp;
	}
	else
		*lst = new_node;
}
