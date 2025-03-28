/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:01:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 17:00:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Create a new t_var node.
 * @param name 
	A pointer to a string containing the name of the variable.
 * @param value 
	A pointer to a string containing the value of the variable.
 * @param type 
	A char that indicates the type of the variable (ENV, EXPORT, SHELL).
 * @return 
	A pointer to the newly created t_var node, or NULL if memory allocation fails.
 */
t_var	*t_var_new(char	*name, char *value, char type)
{
	t_var	*node;

	node = malloc(sizeof(t_var));
	if (!node)
		return (0);
	if (name)
		node->name = ft_strdup(name);
	else
		node->name = NULL;
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = NULL;
	node->type = type;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*!
 * @brief 
	Create a new t_cmd node.
 * @param token 
	A pointer to a string containing the token.
 * @param type 
	A char that indicates the type of the token (NONE, STANDARD, REDIRECT, PIPE, 
	BOOLEAN, WILDCARD).
 * @return
	A pointer to the newly created t_cmd node, or NULL if memory allocation 
	fails.
 */
t_cmd	*t_cmd_new(char	*token, char type)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (0);
	node->token = token;
	node->type = type;
	node->next = 0;
	node->prev = 0;
	return (node);
}

/*!
 * @brief 
	Create a new t_fd node.
 * @param redirect 
	Type of redirection (STDIN_FILENO or STDOUT_FILENO).
 * @param prev_fd 
	Actual file descriptor.
 * @param new_fd 
	New file descriptor.
 * @return 
	A pointer to the newly created t_fd node, or NULL if memory allocation 
	fails.
 */
t_fd	*t_fd_new(int redirect, int prev_fd, int new_fd, bool is_pipe)
{
	t_fd	*node;

	node = malloc(sizeof(t_fd));
	if (!node)
		return (0);
	node->redirect = redirect;
	node->prev_fd = prev_fd;
	node->new_fd = new_fd;
	node->pipe = is_pipe;
	node->next = 0;
	node->prev = 0;
	return (node);
}
