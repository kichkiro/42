/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:34:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 01:10:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Parses variables in the input prompt and appends the expanded value to the 
	token.
 * @param cmd 
	Linked list containing command line.
 * @param prompt 
	The input prompt.
 * @param p 
	Pointer to the parsing structure.
 * @param var 
	Linked list containing variables.
 */
void	parsing_vars(t_cmd **cmd, char *prompt, t_parse **p, t_var *var)
{
	if ((!(*p)->single_quotes && prompt[(*p)->i] == '$') || \
		(!(*p)->single_quotes && prompt[(*p)->i] == '$' && (*cmd) && \
		(*cmd)->prev->type))
	{
		(*p)->var_value = variable_expand(prompt, &(*p)->i, var);
		if ((*p)->var_value)
			(*p)->token = ft_strappend(\
				(*p)->token, (*p)->var_value, true, true);
		(*p)->type = STANDARD;
		(*p)->flow = false;
	}
}

/*!
 * @brief 
	Parses redirects in the input prompt and appends them as tokens to the 
	command line.
 * @param cmd 
	Linked list containing command line.
 * @param prompt 
	The input prompt.
 * @param p 
	Pointer to the parsing structure.
 */
void	parsing_redirects(t_cmd **cmd, char *prompt, t_parse **p)
{
	if (!(*p)->single_quotes && !(*p)->double_quotes && (prompt[(*p)->i] == '<'\
		|| prompt[(*p)->i] == '>'))
	{
		if ((*p)->type == STANDARD)
			token_append(&(*p)->token, &(*p)->type, cmd, true);
		(*p)->token = ft_char_append((*p)->token, prompt[(*p)->i], true);
		if (prompt[(*p)->i + 1] == '<' || prompt[(*p)->i + 1] == '>')
			(*p)->token = ft_char_append((*p)->token, prompt[++(*p)->i], true);
		(*p)->type = REDIRECT;
		token_append(&(*p)->token, &(*p)->type, cmd, true);
	}
}

/*!
 * @brief 
	Parses pipes in the input prompt and appends them as tokens to the command 
	line.
 * @param cmd 
	Linked list containing command line.
 * @param prompt 
	The input prompt.
 * @param p 
	Pointer to the parsing structure.
 */
void	parsing_pipes(t_cmd **cmd, char *prompt, t_parse **p)
{
	if (!(*p)->single_quotes && !(*p)->double_quotes && prompt[(*p)->i] == '|'
		&& prompt[(*p)->i + 1] != '|')
	{
		if ((*p)->type == STANDARD)
			token_append(&(*p)->token, &(*p)->type, cmd, true);
		(*p)->token = ft_char_append((*p)->token, prompt[(*p)->i], true);
		(*p)->type = PIPE;
		token_append(&(*p)->token, &(*p)->type, cmd, true);
	}
}

/*!
 * @brief 
	Parses booleans (logical operators and parentheses) in the input prompt 
	and appends them as tokens to the command line.
 * @param cmd 
	Linked list containing command line.
 * @param prompt 
	The input prompt.
 * @param p 
	Pointer to the parsing structure.
 */
void	parsing_booleans(t_cmd **cmd, char *prompt, t_parse **p)
{
	if (!(*p)->single_quotes && !(*p)->double_quotes && ((prompt[(*p)->i] == \
		'&' && prompt[(*p)->i + 1] == '&') || (prompt[(*p)->i] == '|' && \
		prompt[(*p)->i + 1] == '|') || prompt[(*p)->i] == '(' || \
		prompt[(*p)->i] == ')'))
	{
		if ((*p)->type == STANDARD)
			token_append(&(*p)->token, &(*p)->type, cmd, true);
		(*p)->token = ft_char_append((*p)->token, prompt[(*p)->i], true);
		if (prompt[(*p)->i + 1] == '&' || prompt[(*p)->i + 1] == '|')
			(*p)->token = ft_char_append((*p)->token, prompt[++(*p)->i], true);
		(*p)->type = BOOLEAN;
		token_append(&(*p)->token, &(*p)->type, cmd, true);
	}
}

/*!
 * @brief 
	Parses wildcards in the input prompt and handles them by appending 
	appropriate tokens to the command line.
 * @param cmd 
	Likned list containing command line.
 * @param prompt 
	The input prompt.
 * @param p 
	Pointer to the parsing structure.
 */
void	parsing_wildcards(t_cmd **cmd, char *prompt, t_parse **p)
{
	if (!(*p)->single_quotes && !(*p)->double_quotes && prompt[(*p)->i] == '*')
	{
		(*p)->token = ft_char_append((*p)->token, prompt[(*p)->i], true);
		(*p)->flow = false;
		(*p)->i++;
		while (prompt[(*p)->i] && !(*p)->flow)
		{	
			(*p)->flow = true;
			parsing_standard_token(cmd, prompt, p, 0);
			(*p)->i++;
		}
		wildcards_handler((*p)->token, cmd, &(*p)->type);
		ft_free((void **)&(*p)->token);
		(*p)->i--;
	}
}
