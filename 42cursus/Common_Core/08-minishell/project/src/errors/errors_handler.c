/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:53:07 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 00:37:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	This function handles error messages and exit status in the minishell 
	program.
 * @param request 
	The type of error handling request.
 * @param msg 
	The error message to be printed.
 * @param code 
	The exit status code.
 * @param print_perror 
	Indicates whether to print the error description from perror.
 * @return 
	The exit status code.
 */
int	error_handler(char request, char *msg, int code, bool print_perror)
{
	static int	exit_status;

	if (request == GET)
		return (exit_status);
	else if (request == SET)
		exit_status = code;
	else if (request == PRINT || request == PRINT_F)
	{
		exit_status = code;
		ft_putstr_fd(RED"minishell: ", STDERR_FILENO);
		if (msg)
			ft_putstr_fd(msg, STDERR_FILENO);
		if (print_perror)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			perror(NULL);
		}
		ft_putstr_fd(RESET, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (request == PRINT_F)
		free(msg);
	return (exit_status);
}
