/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:28:09 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/17 18:28:39 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief
	This function checks if a variable is already present in the exported
	variable list and updates its value if found.
 * @param var
	The list of variables.
 * @param split_arg
	Array containing the variable name and value.
 * @return
	1 if the variable is found and updated, 0 otherwise.
 */
static int	is_in_exp(t_var **var, char **split_arg)
{
	while ((*var)->next)
	{
		if (!ft_strncmp((*var)->name, split_arg[0], ft_strlen(split_arg[0])))
		{
			if (split_arg[1])
				(*var)->value = split_arg[1];
			free(split_arg);
			t_var_set_to_head(var);
			return (1);
		}
		(*var) = (*var)->next;
	}
	if (!ft_strncmp((*var)->name, split_arg[0], ft_strlen(split_arg[0])))
	{
		if (split_arg[1])
			(*var)->value = split_arg[1];
		free(split_arg);
		t_var_set_to_head(var);
		return (1);
	}
	return (0);
}

/*!
 * @brief
	This function sets an exported variable by parsing the argument and adding
	it to the variable list.
 * @param arg
	The argument containing the variable assignment.
 * @param var
	The list of variables.
 * @return
	1 if the variable is successfully set, 0 otherwise.
 */
static int	set_export_var(char *arg, t_var **var)
{
	char	**split_arg;

	split_arg = ft_split(arg, '=');
	if (is_in_exp(var, split_arg))
		return (1);
	if (split_arg[1])
		t_var_add_back(var, t_var_new(split_arg[0], split_arg[1], EXPORT));
	else
		t_var_add_back(var, t_var_new(split_arg[0], NULL, EXPORT));
	free(split_arg);
	return (1);
}

/*!
* @brief
	Set one or more enviroment variables.
	If the variable already exists, it will be updated.
	If no arguments are passed, it will print all the exportable enviroment
	variables.
* @param args
	Command to execute.
* @param var
	The list of variables.
*/
void	ft_export(char ***args, t_var **var)
{
	int		i;

	i = 0;
	if (args[0][1])
		while (args[0][++i] && set_export_var(args[0][i], var))
			error_handler(SET, NULL, EXIT_SUCCESS, false);
	else
	{
		if (!(*var))
			return ;
		while ((*var)->next)
		{
			if ((*var)->type == EXPORT && (*var)->value)
				printf("declare -x %s=\"%s\"\n", (*var)->name, (*var)->value);
			else if ((*var)->type == EXPORT)
				printf("declare -x %s\n", (*var)->name);
			(*var) = (*var)->next;
		}
		if ((*var)->type == EXPORT && (*var)->value)
			printf("declare -x %s=\"%s\"\n", (*var)->name, (*var)->value);
		else if ((*var)->type == EXPORT)
			printf("declare -x %s\n", (*var)->name);
	}
	error_handler(SET, NULL, EXIT_SUCCESS, false);
	t_var_set_to_head(var);
}
