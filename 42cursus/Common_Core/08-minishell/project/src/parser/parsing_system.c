/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_system.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:03:22 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 01:06:12 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Appends a token to the command linked list.
 * @param token 
	The token to append.
 * @param type 
	The type of the token.
 * @param cmd 
	Linked list containing command line.
 * @param free_token 
	Indicates whether to free the token after appending.
 */
void	token_append(char **token, char *type, t_cmd **cmd, bool free_token)
{
	t_cmd_add_back(cmd, t_cmd_new(ft_strdup(*token), *type));
	*type = NONE;
	t_cmd_set_to_head(cmd);
	if (free_token)
		ft_free((void **)token);
}

/*!
 * @brief 
	Detects quotes in the input prompt and updates the parsing structure 
	accordingly.
 * @param prompt 
	The input prompt.
 * @param p 
	Pointer to the parsing structure.
 */
static void	quotes_detector(char *prompt, t_parse **p)
{
	if (prompt[(*p)->i] == '\'' && !(*p)->double_quotes)
	{
		(*p)->single_quotes = !(*p)->single_quotes;
		(*p)->flow = false;
	}
	else if (prompt[(*p)->i] == '"' && !(*p)->single_quotes)
	{
		(*p)->double_quotes = !(*p)->double_quotes;
		(*p)->flow = false;
	}
}

/*!
 * @brief 
	Parses the input prompt for standard tokens.
 * @param cmd 
	Linked list containing command line.
 * @param prompt 
	The input prompt.
 * @param p 
	Pointer to the parsing structure.
 * @param wc 
	Wildcard character.
 */
void	parsing_standard_token(t_cmd **cmd, char *prompt, t_parse **p, char wc)
{
	if ((*p)->single_quotes || ((*p)->double_quotes && prompt[(*p)->i] != \
		'$') || (!(*p)->double_quotes && !(*p)->single_quotes && \
		prompt[(*p)->i] != ' ' && prompt[(*p)->i] != '<' && prompt[(*p)->i] != \
		'>' && prompt[(*p)->i] != '$' && prompt[(*p)->i] != '|' && \
		prompt[(*p)->i] != wc && prompt[(*p)->i] != '&' && \
		prompt[(*p)->i] != '(' && prompt[(*p)->i] != ')'))
	{
		(*p)->token = ft_char_append((*p)->token, prompt[(*p)->i], true);
		(*p)->type = STANDARD;
		(*p)->flow = false;
	}
	else if (wc && (*p)->flow && (*p)->type == STANDARD && \
		!(*p)->single_quotes && !(*p)->double_quotes && prompt[(*p)->i] == ' ' \
		&& (*p)->token)
		token_append(&(*p)->token, &(*p)->type, cmd, true);
}

/*!
 * @brief 
	Initializes the parsing structure.
 * @param p 
	Pointer to the parsing structure.
 */
static void	init_parsing(t_parse **p)
{
	*p = (t_parse *)ft_calloc(1, sizeof(t_parse));
	(*p)->i = -1;
	(*p)->type = NONE;
	(*p)->token = (char *)ft_calloc(1, sizeof(char));
	(*p)->var_value = NULL;
	(*p)->single_quotes = false;
	(*p)->double_quotes = false;
	(*p)->flow = true;
}

/*!
 * @brief 
	This function performs the parsing of the command line by iterating through
	the prompt and identifying different tokens and their types.
 * @param prompt 
	The input prompt.
 * @param cmd 
	Linked list containing command line.
 * @param var 
	The list of variables.
 */
void	parsing_system(char *prompt, t_cmd **cmd, t_var *var)
{
	t_parse	*p;

	init_parsing(&p);
	while (prompt[++p->i])
	{
		quotes_detector(prompt, &p);
		if (p->flow)
			parsing_standard_token(cmd, prompt, &p, 42);
		if (p->flow)
			parsing_vars(cmd, prompt, &p, var);
		if (p->flow)
			parsing_redirects(cmd, prompt, &p);
		if (p->flow)
			parsing_pipes(cmd, prompt, &p);
		if (p->flow)
			parsing_booleans(cmd, prompt, &p);
		if (p->flow)
			parsing_wildcards(cmd, prompt, &p);
		p->flow = true;
	}
	if (p->token && p->type != NONE)
		token_append(&p->token, &p->type, cmd, true);
	else
		ft_free((void **)&p->token);
	free(p);
}
