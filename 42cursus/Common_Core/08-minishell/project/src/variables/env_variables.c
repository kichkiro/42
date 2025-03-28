/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:02:34 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/24 18:02:34 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	no_prev(t_var **var)
{
	(*var)->next->prev = NULL;
	(*var) = (*var)->next;
}

/*!
* @brief
	Unset an enviroment variable.
* @param arg
	The name of the variable to unset.
* @param var
	The list of variables.
*/
static void	unset_var(char *arg, t_var **var)
{
	while ((*var))
	{
		if (!ft_strncmp((*var)->name, arg, ft_strlen(arg)))
		{
			if (!(*var)->prev && !(*var)->next)
			{
				free((*var));
				(*var) = NULL;
				return ;
			}
			if ((*var)->prev)
				(*var)->prev->next = (*var)->next;
			else
				no_prev(var);
			if ((*var)->next)
				(*var)->next->prev = (*var)->prev;
			free((*var));
			t_var_set_to_head(var);
			return ;
		}
		(*var) = (*var)->next;
	}
	t_var_set_to_head(var);
}

/*!
* @brief
	Unset an enviroment variable.
	If no arguments are given, prints a new line.
* @param args
	Command to execute.
* @param var
	The list of variables.
*/
void	ft_unset(char ***args, t_var **var)
{
	int	i;

	i = 0;
	if (args[0][1])
	{
		while (args[0][++i])
		{
			if (!(*var))
				return ;
			unset_var(args[0][i], var);
		}
	}
	else
		printf("\n");
}
