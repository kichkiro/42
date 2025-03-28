/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:45:46 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 14:52:51 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	This function executes an external command by forking a child process and 
	executing the specified executable with the given arguments.
 * @param exe 
	The path to the executable.
 * @param args 
	The arguments for the executable.
 */
void	execute_external(char *exe, char ***args)
{
	pid_t	pid;
	int		exit_code;

	pid = 0;
	exit_code = 0;
	if (!access(exe, X_OK))
	{
		pid = fork();
		if (pid == -1)
			error_handler(PRINT, exe, 1, true);
		else if (!pid)
		{
			if (execve(exe, *args, NULL) == -1)
				exit(EXIT_FAILURE);
			exit(EXIT_SUCCESS);
		}
		else
			waitpid(pid, &exit_code, 0);
		if (exit_code == EXIT_SUCCESS && pid != -1)
			error_handler(SET, NULL, WEXITSTATUS(exit_code), false);
		else
			error_handler(SET, NULL, WEXITSTATUS(exit_code), true);
	}
	else
		error_handler(PRINT, exe, 126, true);
}

/*!
 * @brief 
	This function searches for the executable file in the specified paths and 
	updates the exe parameter with the full path to the executable.
 * @param exe 
	The path to the executable.
 * @param path 
	The array of paths to search for the executable.
 * @return 
	true if the executable is found, false otherwise.
 */
static bool	find_exe(char **exe, char **path)
{
	bool	found;
	char	*tmp;
	size_t	i;

	found = false;
	i = -1;
	*exe = ft_strappend("/", *exe, false, true);
	while (path[++i])
	{
		tmp = ft_strappend(path[i], *exe, false, false);
		if (access(tmp, F_OK) == 0)
		{
			found = true;
			ft_free((void **)exe);
			*exe = ft_strdup(tmp);
			ft_free((void **)&tmp);
			break ;
		}
		ft_free((void **)&tmp);
	}
	ft_strmatrixfree(&path);
	if (!found)
		error_handler(PRINT_F, ft_strjoin(*exe, ": command not found"), 127, 0);
	return (found);
}

/*!
 * @brief 
	This function routes the execution of a command based on its type, such as 
	redirection or pipe.
 * @param cmd 
	Linked list containing command line.
 * @param exe 
	The path to the executable.
 * @param args 
	The arguments for the executable.
 * @param var 
	The list of variables.
 * @return 
	true if the command is executed successfully, false otherwise.
 */
static bool	exec_router(t_cmd **cmd, char *exe, char ***args, t_var **var)
{
	t_fd	*fd;

	if (((*cmd) && (*cmd)->type == REDIRECT) || (*cmd && (*cmd)->token[0] == \
		')' && (*cmd)->type == BOOLEAN && (*cmd)->next && (*cmd)->next->type \
		== REDIRECT))
	{
		if (redirections(cmd, exe, args, var))
			return (false);
		if (*cmd && (*cmd)->next)
			*cmd = (*cmd)->next;
	}
	if ((*cmd && (*cmd)->type == PIPE) || (*cmd && (*cmd)->token[0] == ')' && \
		(*cmd)->type == BOOLEAN && (*cmd)->next && (*cmd)->next->type == PIPE))
		pipes(exe, args, var);
	else if (is_builtin(exe))
		execute_builtin(args, var);
	else if (exe)
		execute_external(exe, args);
	ft_strmatrixfree(args);
	ft_free((void **)&exe);
	fd = fd_handler(GET, 0);
	reset_terminal(&fd, false, true);
	return (true);
}

/*!
 * @brief 
	This function handles the execution of commands with the standard type.
 * @param cmd 
	Linked list containing command line.
 * @param var 
	The list of variables.
 * @param args 
	The arguments for the executable.
 * @param exe 
	The path to the executable.
 * @return 

 */
static bool	standard_type(t_cmd **cmd, t_var **var, char **args, char *exe)
{
	while (*cmd && (*cmd)->type == STANDARD)
	{
		args = ft_strmatrixjoin(args, ft_strdup((*cmd)->token), 1, 1);
		*cmd = (*cmd)->next;
	}
	exe = ft_strdup(args[0]);
	if (is_builtin(exe) || (args && !access(exe, F_OK)) || find_exe(&exe, \
		ft_split(getenv("PATH"), ':')))
	{
		if (!exec_router(cmd, exe, &args, var))
			return (false);
	}
	else
	{
		ft_strmatrixfree(&args);
		ft_free((void **)&exe);
	}
	return (true);
}

/*!
 * @brief 
	This function handles the execution of the command line by iterating through 
	the command linked list and executing each command accordingly.
 * @param cmd 
	Linked list containing command line.
 * @param var 
	The list of variables.
 */
void	execution_system(t_cmd **cmd, t_var **var)
{
	char	**args;
	char	*exe;

	args = NULL;
	exe = NULL;
	while (*cmd && (*cmd)->type != BOOLEAN)
	{
		if ((*cmd)->type == STANDARD)
		{
			if (!standard_type(cmd, var, args, exe))
				return ;
		}
		else if (!exec_router(cmd, NULL, NULL, var))
			return ;
		if (signals_controller(GET, 0) == true)
			return ;
		if (error_handler(GET, 0, 0, 0) != EXIT_SUCCESS)
			break ;
		if (*cmd && (*cmd)->type && (*cmd)->type != BOOLEAN)
			*cmd = (*cmd)->next;
	}
	booleans(cmd, var);
}
