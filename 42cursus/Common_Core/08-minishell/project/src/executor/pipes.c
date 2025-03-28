/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:16:54 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/01 14:16:54 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Save the previous file descriptor and new, and add them to the linked list
	containing all the redirects performed so far.
 * @param pipe_fd 
	Pipe file descriptors.
 */
static void	save_prev_fd(int *pipe_fd)
{
	int	prev_fd;
	int	new_fd;

	prev_fd = dup(STDIN_FILENO);
	if (!prev_fd)
		error_handler(PRINT, NULL, 1, true);
	new_fd = pipe_fd[0];
	fd_handler(SET, t_fd_new(STDIN_FILENO, prev_fd, new_fd, true));
}

/*!
 * @brief 
	Redirects output to pipe, if the output is from the terminal, otherwise 
	executes the command in the current output.
 * @param pipe_fd 
	Pipe file descriptors.
 * @param exe 
	Executable path.
 * @param args 
	Arguments for the command.
 * @param var 
	Linked list containing variables.
 */
static void	write_in_pipe(int *pipe_fd, char *exe, char ***args, t_var **var)
{
	bool	terminal_stdout;
	int		actual_fd;

	actual_fd = dup(STDOUT_FILENO);
	if (!actual_fd)
		error_handler(PRINT, NULL, 1, true);
	terminal_stdout = isatty(STDOUT_FILENO);
	if (close(pipe_fd[0]) == -1)
		error_handler(PRINT, NULL, 1, true);
	if (terminal_stdout && dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_handler(PRINT, NULL, 1, true);
	if (close(pipe_fd[1]) == -1)
		error_handler(PRINT, NULL, 1, true);
	if (!is_builtin(args[0][0]))
		execute_external(exe, args);
	else if (exe)
		execute_builtin(args, var);
	if (terminal_stdout && dup2(actual_fd, STDOUT_FILENO) == -1)
		error_handler(PRINT, NULL, 1, true);
}

/*!
 * @brief 
	It waits for the child process to finish and redirects the input to pipe.
 * @param pid 
	PID of the child process.	
 * @param pipe_fd 
	Pipe file descriptors.
 */
static void	read_from_pipe(pid_t pid, int *pipe_fd)
{
	if (waitpid(pid, NULL, 1) == -1)
		error_handler(PRINT, NULL, 1, true);
	if (close(pipe_fd[1]) == -1)
		error_handler(PRINT, NULL, 1, true);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error_handler(PRINT, NULL, 1, true);
}

/*!
* @brief
	Main function of pipe.
	It creates a child process, which takes care of the write side of the pipe,
	while the parent process takes care of the read side.
	When finished, it restores the terminal output.
* @param exe
	The path to the executable.
* @param args
	The arguments to pass to the executable.
*/
void	pipes(char *exe, char ***args, t_var **var)
{
	int		pipe_fd[2];
	pid_t	pid;
	t_fd	*fd;

	if (pipe(pipe_fd) == -1)
		error_handler(PRINT, NULL, 1, true);
	save_prev_fd(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		write_in_pipe(pipe_fd, exe, args, var);
		exit(0);
	}
	else
	{
		read_from_pipe(pid, pipe_fd);
		fd = fd_handler(GET, 0);
		reset_terminal(&fd, false, true);
	}
}
