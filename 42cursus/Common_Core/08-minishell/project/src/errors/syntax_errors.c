/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:07:08 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/18 00:43:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief
	Handles the syntax error for boolean pipes.
 * @param cmd
	Linked list containing command line.
 * @return
	2 indicating a syntax error.
 */
static int	bool_pipe(t_cmd **cmd)
{
	char	*str;

	str = NULL;
	str = ft_strjoin("syntax error near unexpected token `", (*cmd)->token);
	str = ft_strappend(str, "'", true, false);
	error_handler(PRINT, str, 2, false);
	free(str);
	return (2);
}

/*!
 * @brief 
	Extracts the appropriate boolean token from the input prompt.
 * @param prompt 
	The input prompt.
 * @return 
	The boolean token ("&&" or "&").
 */
static char	*and_token(char *prompt)
{
	int	i;

	i = -1;
	while (prompt[++i])
	{
		if (prompt[i] == '&' && prompt[i + 1] == '&')
		{
			return ("&&");
		}
	}
	return ("&");
}

/*!
 * @brief
	Handles syntax error involving boolean operators and parentheses.
 * @param cmd
	Linked list containing command line.
 * @param prompt
	The input prompt.
 * @return
	2 indicating a syntax error.
 */
static int	bool_pipe_parentheses(t_cmd **cmd, char *prompt)
{
	char	*str;
	char	**ph;

	str = NULL;
	ph = ft_split((*cmd)->token, '(');
	if ((*cmd)->next && (*cmd)->next->token[0] == '|')
		str = ft_strappend("syntax error near unexpected token `", "||", 0, 0);
	else if ((*cmd)->token[1] == '&')
		str = ft_strappend("syntax error near unexpected token `'",
				and_token(prompt), 0, 0);
	else
		str = ft_strappend("syntax error near unexpected token `", ph[0], 0, 0);
	str = ft_strappend(str, "'", true, false);
	error_handler(PRINT, str, 2, false);
	free(str);
	return (2);
}

/*!
 * @brief 
	Checks if there are only parentheses in the command line.
 * @param cmd 
	Linked list containing command line.
 * @return 
	0 if only parentheses are found, otherwise returns an error code.
 */
static int	parentheses_only(t_cmd **cmd)
{
	while ((*cmd)->next && (*cmd)->next->token[0] == '(')
		(*cmd) = (*cmd)->next;
	if ((*cmd)->next && (*cmd)->next->token[0] == ')')
	{
		printf("\n");
		return (error_handler(SET, NULL, 1, false));
	}
	t_cmd_set_to_head(cmd);
	return (0);
}

/*!
 * @brief
	Checks for syntax errors in the command line.
 * @param cmd
	Linked list containing the command line.
 * @param prompt
	The input prompt.
 * @return
	0 if no syntax errors are found, otherwise returns an error code.
 */
int	syntax_error(t_cmd **cmd, char *prompt)
{
	if (!ft_strncmp((*cmd)->token, "|", 1)
		|| !ft_strncmp((*cmd)->token, "||", 2)
		|| !ft_strncmp((*cmd)->token, "&", 1)
		|| !ft_strncmp((*cmd)->token, "&&", 2))
		return (bool_pipe(cmd));
	else if (!ft_strncmp((*cmd)->token, "(|", 2)
		|| !ft_strncmp((*cmd)->token, "(||", 3)
		|| !ft_strncmp((*cmd)->token, "(&", 2)
		|| !ft_strncmp((*cmd)->token, "(&&", 3))
		return (bool_pipe_parentheses(cmd, prompt));
	else if ((*cmd)->token[0] == '(' && (*cmd)->next
		&& (*cmd)->next->token[0] == ')')
		return (error_handler(PRINT,
				"syntax error near unexpected token `)'", 2, false));
	else if ((*cmd)->token[0] == '(' && (*cmd)->next && (*cmd)->next->next
		&& (*cmd)->next->token[0] == '(')
		return (parentheses_only(cmd));
	t_cmd_set_to_head(cmd);
	return (0);
}
