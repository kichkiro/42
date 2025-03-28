/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:07:27 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/11 00:17:37 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Determines whether a given prompt string contains a valid assignment 
	statement.
 * @details
	- The prompt must start with a variable name.
	- The first character of the variable name must be a letter or an 
		underscore.
	- If the first character is an underscore, there must be at least one 
		letter, digit, or underscore before the brackets and the assignment 
		operator.
	- All characters between the first character and the assignment operator can 
		be numbers, letters, underscores, or square brackets.
	- If there are square brackets, they must appear in the sequence: an opening 
		bracket, a number, a closing bracket, and the assignment operator.
 * @param prompt
	A pointer to a character array that contains the prompt string to be checked.
 * @return 
	Variable name if the prompt string contains a valid assignment statement, 
	NULL otherwise.
 */
static char	*is_assignment(char *prompt)
{
	size_t	i;
	ssize_t	var_name_len;

	i = 0;
	var_name_len = ft_stridx(prompt, '=');
	if (var_name_len == -1 || (prompt[i] != '_' && !ft_isalpha(prompt[i])) || \
		(prompt[i] == '_' && prompt[i + 1] != '_' && !ft_isalnum(prompt[i + 1]))
		|| !prompt[var_name_len + 1])
		return (NULL);
	while (prompt[++i] != '=')
	{
		if (prompt[i] != '_' && !ft_isalnum(prompt[i]) && prompt[i] != '[')
			return (NULL);
		if (prompt[i] == '[')
		{
			var_name_len = ft_stridx(prompt, '[');
			while (prompt[++i] != ']')
			{
				if (!ft_isdigit(prompt[i]) || ft_stridx(prompt, ']') == -1)
					return (NULL);
			}
		}
	}
	return (ft_substr(prompt, 0, var_name_len));
}

// To be finished...
// static char	*get_var_value(char *prompt, size_t var_name_len)
// {
// 	char	*var_value;
// 	int		i;

// 	i = var_name_len + 1;
// 	if (prompt[i] == ' ')
// 	{
// 		ft_putstr_fd(RED"minishell: invalid variable value\n"RESET, 2);
// 		return (NULL);
// 	}
// 	while (prompt[i++])
// 	{
// 		if (prompt[i] != '\'' && prompt[i] != '"' && prompt[i] != '(' && 
// 			prompt[i] != ')' && prompt[i] != '$')
// 			var_value = ft_char_append(prompt, prompt[i], true);
// 		else 
// 		{
// 		}
// 	}
// 	return (var_value);
// }

// Temporary function that takes care of taking the value of the variable.
static char	*tmp_get_var_value(char *prompt, size_t var_name_len)
{
	return (ft_substr(prompt, var_name_len + 1, ft_strlen(prompt) - \
	var_name_len));
}

/*!
 * @brief 
	Function that handles the assignment of shell variables.
	It checks whether the prompt contains a valid and, if so, takes the variable 
	name and its value and adds them to the list of variables.
 * @param var 
	List of variables.
 * @param prompt 
	Prompt string.
 * @return 
	True if the prompt string contains a valid assignment statement, false
	otherwise.
 */
bool	shell_variables(t_var **var, char *prompt)
{
	char	*var_name;
	char	*var_value;

	var_name = is_assignment(prompt);
	if (!var_name)
		return (false);
	var_value = tmp_get_var_value(prompt, ft_strlen(var_name));
	t_var_add_back(var, t_var_new(var_name, var_value, SHELL));
	t_var_set_to_head(var);
	return (true);
}
