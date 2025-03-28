/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:08:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 00:10:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Contains fd, a linked list that keeps track of all redirects performed so 
	far.
	Based on the request, GET, SET, RESTORE executes the corresponding action.
 * @param request 
	Request to perform:
		- GET: return fd list.
		- SET: append new node at the end of the list.
		- RESTORE: for each fd in t_fd, close new_fd and reset prev_fd.
 * @param new_node 
	Possible new node to be added to the end of the list.
 * @return 
	List if request is GET, NULL otherwise.
 */
t_fd	*fd_handler(char request, t_fd *new_node)
{
	static t_fd	*fd;

	if (request == GET)
		return (fd);
	else if (request == SET)
		t_fd_add_back(&fd, new_node);
	else if (request == RESTORE)
	{
		t_fd_set_to_last(&fd);
		while (fd)
		{
			if (close(fd->new_fd) == -1)
				error_handler(PRINT, NULL, 1, true);
			if (dup2(fd->prev_fd, fd->redirect) == -1)
				error_handler(PRINT, NULL, 1, true);
			t_fd_free_last(&fd);
		}
	}
	return (NULL);
}

/*!
 * @brief 
	Reset the terminal fd's.
 * @param fd 
	Linked list containing data from previous redirects.
 * @param reset_stdin
	Reset stdin if true.
 * @param reset_stdout
	Reset stdout if true.
 */
void	reset_terminal(t_fd **fd, bool reset_stdin, bool reset_stdout)
{
	t_fd_set_to_head(fd);
	while (*fd)
	{
		if ((isatty((*fd)->prev_fd) && (*fd)->redirect == STDIN_FILENO && \
			reset_stdin) || ((*fd)->redirect == STDOUT_FILENO && reset_stdout))
		{
			if (dup2((*fd)->prev_fd, (*fd)->redirect) == -1)
				error_handler(PRINT, NULL, 1, true);
		}
		if ((*fd)->next)
			*fd = (*fd)->next;
		else
			break ;
	}
}

/*!
 * @brief 
	Reset previous fd's.
 * @param fd 
	Linked list containing data from previous redirects.
 * @param reset_input
	Reset input if true.
 * @param reset_output
	Reset output if true.
 */
void	reset_prev(t_fd **fd, bool reset_input, bool reset_output)
{
	t_fd_set_to_last(fd);
	while ((*fd))
	{
		if (!reset_input && (*fd)->redirect == STDIN_FILENO)
		{
			if (dup2((*fd)->new_fd, STDIN_FILENO) == -1)
				error_handler(PRINT, NULL, 1, true);
			reset_input = true;
		}
		else if (!reset_output && (*fd)->redirect == STDOUT_FILENO)
		{
			if (dup2((*fd)->new_fd, STDOUT_FILENO) == -1)
				error_handler(PRINT, NULL, 1, true);
			reset_output = true;
		}
		if ((*fd)->prev)
			*fd = (*fd)->prev;
		else
			break ;
	}
}
