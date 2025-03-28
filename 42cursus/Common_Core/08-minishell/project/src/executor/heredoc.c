/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:05:42 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 16:17:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Gets the document with readline().
 * @param delimiter 
	Heredoc delimiter.
 * @param doc 
	Heredoc document.
 * @param sig
	It is used to keep track of whether a SIGINT is received during the 
	acquisition of the heredoc.
 */
static void	get_doc(char *delimiter, char **doc, bool *sig)
{
	char	*prompt;

	while (true)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		prompt = readline(YELLOW_B"> "RESET);
		if (signals_controller(GET, 0) == true || !prompt)
		{
			signals_controller(SET, false);
			ft_free((void **)doc);
			*sig = true;
			break ;
		}
		if (!ft_strncmp(prompt, delimiter, ft_strlen(delimiter)) && \
			ft_strlen(prompt) == ft_strlen(delimiter))
			break ;
		*doc = ft_strappend(*doc, prompt, true, true);
		*doc = ft_strappend(*doc, "\n", true, false);
	}
	ft_free((void **)&prompt);
	if (!*doc)
		*doc = ft_strappend(*doc, "", true, false);
}

/*!
 * @brief 
	It uses pipe as a temporary file, writes the document to it on the write 
	side and redirects the input to the read side.
 * @param doc 
	Heredoc document.
 * @param cmd 
	Linked list containing command line.
 */
static void	redirection_pipe(char *doc, t_cmd **cmd)
{
	int	prev_fd;
	int	new_fd;
	int	pipe_fd[2];

	prev_fd = dup(STDIN_FILENO);
	if (!prev_fd)
		error_handler(PRINT, NULL, 1, true);
	if (pipe(pipe_fd) == -1)
		error_handler(PRINT, NULL, 1, true);
	new_fd = pipe_fd[0];
	if (write(pipe_fd[1], doc, ft_strlen(doc)) == -1)
		error_handler(PRINT, NULL, 1, true);
	if (dup2(new_fd, STDIN_FILENO) == -1)
		error_handler(PRINT, NULL, 1, true);
	if (close(pipe_fd[1]) == -1)
		error_handler(PRINT, NULL, 1, true);
	fd_handler(SET, t_fd_new(STDIN_FILENO, prev_fd, new_fd, false));
	if ((*cmd) && (*cmd)->next && (*cmd)->next->type == REDIRECT)
		*cmd = (*cmd)->next;
}

/*!
 * @brief 
	Main function of the heredoc.
	Check whether the output fd is from the terminal or not.
	Temporarily resets the terminal fd.
	Acquires the document with readline().
	Resets the previous input and output fd's.
	Writes the document to pipe and refries the input to it.
 * @param delimiter 
	Heredoc delimiter.
 * @param cmd 
	Linked list containing command line.
 * @param sig
	It is used to keep track of whether a SIGINT is received during the 
	acquisition of the heredoc.
 */
void	heredoc(char *delimiter, t_cmd **cmd, bool *sig)
{
	t_fd	*fd;
	char	*doc;
	bool	terminal_out;

	fd = fd_handler(GET, NULL);
	doc = NULL;
	terminal_out = isatty(STDOUT_FILENO);
	reset_terminal(&fd, true, !terminal_out);
	get_doc(delimiter, &doc, sig);
	reset_prev(&fd, true, !terminal_out);
	reset_terminal(&fd, false, terminal_out);
	redirection_pipe(doc, cmd);
	ft_free((void **)&doc);
}
