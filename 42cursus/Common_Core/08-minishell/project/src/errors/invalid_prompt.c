/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:56:59 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/16 14:13:14 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Check if the prompt contains unclosed brackets outside of quotes.
 * @param prompt 
	The prompt string to check.
 * @param open 
	Open brackets:  '(' or '[' or '{'.
 * @param closed 
	Closed brackets: ')' or ']' or '}'.
 * @return 
	true if all brackets are closed, false otherwise.
 */
static bool	closed_brackets(char *prompt, char open, char closed)
{
	bool	single_quotes;
	bool	double_quotes;
	char	count_brackets;
	size_t	i;

	single_quotes = false;
	double_quotes = false;
	count_brackets = 0;
	i = -1;
	while (prompt[++i])
	{
		if (prompt[i] == '\'' && !double_quotes)
			single_quotes = !single_quotes;
		else if (prompt[i] == '"' && !single_quotes)
			double_quotes = !double_quotes;
		else if (!single_quotes && !double_quotes)
		{
			if (prompt[i] == open)
				count_brackets++;
			else if (prompt[i] == closed)
				count_brackets--;
		}
	}
	return (!count_brackets);
}

/*!
 * @brief 
	Checks if the prompt string contains a backslash or a semicolon outside of
	quotes.
 * @param prompt 
	The prompt string to check.
 * @return 
	false if the prompt string contains a backslash or a semicolon outside of
	quotes, true otherwise.
 */
static bool	backslash_or_semicolon(const char *prompt)
{
	bool	single_quotes;
	bool	double_quotes;
	size_t	len;
	size_t	i;
	char	c;

	single_quotes = false;
	double_quotes = false;
	len = ft_strlen(prompt);
	i = 0;
	c = 0;
	while (i < len)
	{
		c = prompt[i];
		if (prompt[i] == '\'' && !double_quotes)
			single_quotes = !single_quotes;
		else if (prompt[i] == '"' && !single_quotes)
			double_quotes = !double_quotes;
		else if (!single_quotes && !double_quotes && (c == '\\' || c == ';'))
			return (false);
		i++;
	}
	return (true);
}

/*!
 * @brief 
	Checks if all quotes in the prompt string are properly closed.
 * @param prompt 
	The prompt string to check.
 * @return 
	true if all quotes are closed, false otherwise.
 */
static bool	closed_quotes(char *prompt)
{
	bool	single_quotes;
	bool	double_quotes;
	size_t	len;
	size_t	i;

	single_quotes = false;
	double_quotes = false;
	len = ft_strlen(prompt);
	i = 0;
	while (i < len)
	{
		if (prompt[i] == '\'' && !double_quotes)
			single_quotes = !single_quotes;
		else if (prompt[i] == '"' && !single_quotes)
			double_quotes = !double_quotes;
		i++;
	}
	return (!single_quotes && !double_quotes);
}

/*!
 * @brief
	Checks if the given prompt contains any invalid characters or syntax.
	Invalid characters include '\' and ';', invalid syntax includes	unclosed 
	quotes.
 * @param prompt 
	The prompt string to check.
 * @return 
	true if invalid prompt is detected, false otherwise.
 */
bool	invalid_prompt(char *prompt)
{
	bool	invalid;

	invalid = true;
	if (!backslash_or_semicolon(prompt))
		error_handler(PRINT, "detected '\\' or ';'", 1, false);
	else if (!closed_quotes(prompt))
		error_handler(PRINT, "detected unclosed quotes", 1, false);
	else if (!closed_brackets(prompt, '(', ')'))
		error_handler(PRINT, "detected unclosed parentheses", 1, false);
	else if (!closed_brackets(prompt, '[', ']'))
		error_handler(PRINT, "detected unclosed square brackets", 1, false);
	else if (!closed_brackets(prompt, '{', '}'))
		error_handler(PRINT, "detected unclosed braces", 1, false);
	else if (prompt[0] == '&' && prompt[1] != '&')
		error_handler(PRINT, "syntax error near unexpected token `&'", 2, 0);
	else
		invalid = false;
	return (invalid);
}
