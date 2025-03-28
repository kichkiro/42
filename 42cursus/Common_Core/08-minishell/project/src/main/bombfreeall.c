/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bombfreeall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:34:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/17 16:16:09 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Frees all allocated memory and resources used by variables, command line, 
	and the input prompt.
 * @param var 
	Linked list containing variables.
 * @param cmd 
	Linked list containing command line.
 * @param prompt 
	The input prompt.
 * @return 
	0 indicating successful execution.
 */
int	bombfreeall(t_var **var, t_cmd **cmd, char *prompt)
{
	t_var_free(var);
	t_cmd_free(cmd);
	free(prompt);
	return (0);
}
