/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booleans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:33:32 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/12 16:25:34 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	Processes opening parentheses in boolean expressions
	This function is used to handle opening parentheses in boolean expressions.
	It iterates through the command line arguments until it finds the 
	corresponding closing parentheses, then calls the execution_system() 
	function to handle the expression.
 * @param cmd 
 	A pointer to a pointer of struct t_cmd
 * @param var 
 	A pointer to a pointer of struct t_var
 */
static void	open_parenthesis(t_cmd **cmd, t_var **var)
{
	while (*cmd && (*cmd)->token[0] == '(' && (*cmd)->type == BOOLEAN)
		*cmd = (*cmd)->next;
	if (*cmd)
		execution_system(cmd, var);
}

/*!
 * @brief 
 	Processes closing parentheses in boolean expressions
	This function is used to handle closing parentheses in boolean expressions.
	It iterates through the command line arguments until it finds the 
	corresponding opening parentheses, then calls the execution_system() 
	function to handle the expression.
 * @param cmd 
	A pointer to a pointer of struct t_cmd
 * @param var 
 	A pointer to a pointer of struct t_var
 */
static void	closed_parerthesis(t_cmd **cmd, t_var **var)
{
	while (*cmd && (*cmd)->token[0] == ')' && (*cmd)->type == BOOLEAN)
		*cmd = (*cmd)->next;
	if (*cmd)
		execution_system(cmd, var);
}

/*!
 * @brief 
 	Routes boolean expressions to the appropriate handling function
	This function is used to route boolean expressions to the appropriate 
	handling function based on the operator used.
	If the operator is "&&", it calls the router() function to handle it. 
	If the operator is "||", it calls the or_operator() and router() functions 
	to handle it.
 * @param cmd 
 	A pointer to a pointer of struct t_cmd
 * @param var 
 	A pointer to a pointer of struct t_var
 */
static void	bool_router(t_cmd **cmd, t_var **var)
{
	*cmd = (*cmd)->next;
	if (*cmd && (*cmd)->token[0] == '(')
	{
		while ((*cmd) && (*cmd)->token[0] == '(')
			*cmd = (*cmd)->next;
		execution_system(cmd, var);
		booleans(cmd, var);
		if ((*cmd) && (*cmd)->token[0] == '|' && !error_handler(GET, 0, 0, 0))
		{
			while ((*cmd) && (*cmd)->token[0] != ')')
				*cmd = (*cmd)->next;
			while ((*cmd) && (*cmd)->token[0] == ')')
				*cmd = (*cmd)->next;
			booleans(cmd, var);
		}
		else if (*cmd && (*cmd)->token[0] == ')')
		{
			while ((*cmd) && (*cmd)->token[0] == ')')
				*cmd = (*cmd)->next;
			booleans(cmd, var);
		}
	}
	else if (*cmd)
		execution_system(cmd, var);
}

/*!
 * @brief 
	Processes the "or" operator in boolean expressions
	This function is used to handle the "or" operator in boolean expressions.
	It iterates through the command line arguments until it finds the next 
	operator, then routes the expression to the appropriate handling function.
 * @param cmd 
	A pointer to a pointer of struct t_cmd
 */
static void	or_operator(t_cmd **cmd)
{
	int	parentheses;

	parentheses = 0;
	while (*cmd && (*cmd)->token[0] != '&' )
	{
		*cmd = (*cmd)->next;
		while (*cmd && (*cmd)->token[0] == '(')
		{
			parentheses++;
			*cmd = (*cmd)->next;
		}
		while (parentheses > 0)
		{
			while ((*cmd) && (*cmd)->token[0] != ')')
				*cmd = (*cmd)->next;
			while ((*cmd) && (*cmd)->token[0] == ')')
			{
				parentheses--;
				*cmd = (*cmd)->next;
			}
		}
		if (*cmd && (*cmd)->token[0] == '|' && (*cmd)->type == BOOLEAN)
			return ;
	}
}

/*!
 * @brief 
 	Processes boolean expressions in command line arguments.
	This function is used to handle boolean expressions in command line 
	arguments.
	It determines whether the argument is a boolean expression and calls other 
	functions to handle it accordingly.
 * @param cmd 
	A pointer to a pointer of struct t_cmd
 * @param var 
 	A pointer to a pointer of struct t_var
 */
void	booleans(t_cmd **cmd, t_var **var)
{
	if (!(*cmd) || (*cmd)->type != BOOLEAN)
		return ;
	else if ((*cmd)->token[0] == '(')
		open_parenthesis(cmd, var);
	else if ((*cmd)->token[0] == ')')
		closed_parerthesis(cmd, var);
	if (*cmd && error_handler(GET, 0, 0, 0) == EXIT_SUCCESS)
	{
		if (!ft_strncmp((*cmd)->token, "&&", 2))
			bool_router(cmd, var);
		else if (!ft_strncmp((*cmd)->token, "||", 2))
		{
			or_operator(cmd);
			if (*cmd)
				bool_router(cmd, var);
		}
	}
	else if (*cmd && error_handler(GET, 0, 0, 0) != EXIT_SUCCESS && \
		!ft_strncmp((*cmd)->token, "||", 2))
		bool_router(cmd, var);
}
