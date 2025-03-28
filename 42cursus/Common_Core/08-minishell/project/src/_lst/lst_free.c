/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:47:39 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 17:05:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief
	Delete and frees the lst.
 * @param lst
	Linked list.
 */
void	*t_var_free(t_var **lst)
{
	t_var	*tmp;

	tmp = 0;
	if (*lst)
	{
		t_var_set_to_head(lst);
		while ((*lst)->next)
		{
			*lst = (*lst)->next;
			tmp = (*lst)->prev;
			free(tmp->name);
			free(tmp->value);
			free(tmp);
			(*lst)->prev = NULL;
		}
		ft_free((void **)&(*lst)->name);
		ft_free((void **)&(*lst)->value);
		free(*lst);
		*lst = NULL;
	}
	return (NULL);
}

/*!
 * @brief
	Delete and frees the lst.
 * @param lst
	Linked list.
 */
void	*t_cmd_free(t_cmd **lst)
{
	t_cmd	*tmp;

	tmp = NULL;
	if (lst && *lst)
	{
		t_cmd_set_to_head(lst);
		while ((*lst)->next)
		{
			*lst = (*lst)->next;
			tmp = (*lst)->prev;
			free(tmp->token);
			free(tmp);
			(*lst)->prev = NULL;
		}
		free((*lst)->token);
		free(*lst);
		*lst = NULL;
	}
	return (NULL);
}

/*!
 * @brief
	Delete and frees the lst.
 * @param lst
	Linked list.
 */
void	*t_fd_free(t_fd **fd)
{
	t_fd	*tmp;

	tmp = 0;
	if (*fd)
	{
		t_fd_set_to_head(fd);
		while ((*fd)->next)
		{
			*fd = (*fd)->next;
			tmp = (*fd)->prev;
			free(tmp);
			(*fd)->prev = NULL;
		}
		free(*fd);
		*fd = NULL;
	}
	return (NULL);
}
