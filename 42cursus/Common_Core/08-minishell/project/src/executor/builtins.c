/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:49:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/19 17:49:42 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
* @brief
	Executes the builtin command cd.
* @param args
	Folder or path to be changed.
*/
static void	ft_cd(char ***args)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	if (args[0][1])
		path = ft_split(args[0][1], '/');
	if (args[0][1] && args[0][2])
		error_handler(PRINT, "cd: too many arguments", 1, false);
	else if ((!args[0][1] || args[0][1][0] == '~') && !chdir(getenv("HOME")))
		error_handler(SET, NULL, EXIT_SUCCESS, false);
	else if (args[0][1][0] == '-' && !chdir(getenv("OLDPWD")))
	{
		printf("%s\n", getcwd(NULL, 0));
		error_handler(SET, NULL, EXIT_SUCCESS, false);
	}
	else if (chdir(args[0][1]) == -1)
		error_handler(PRINT, ft_strjoin("cd: ", args[0][1]), 1, true);
	else if (!ft_strncmp(args[0][1], "..", 2))
		while (path[i++] && !chdir("."))
			error_handler(SET, NULL, EXIT_SUCCESS, false);
	else if (!chdir(args[0][1]))
		error_handler(SET, NULL, EXIT_SUCCESS, false);
	ft_free((void **)&path);
}

/*!
* @brief
	Executes the builtin command echo with the option -n.
* @param args
	Arguments to be printed.
*/
static void	ft_echo(char ***args)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (!args[0][1])
	{
		printf("\n");
		return ;
	}
	if (!ft_strncmp(args[0][1], "-n", 2) && ++n)
		i++;
	while (args[0][++i])
	{
		if (!args[0][i + 1])
			printf("%s", args[0][i]);
		else
			printf("%s ", args[0][i]);
	}
	if (!n)
		printf("\n");
	error_handler(SET, NULL, EXIT_SUCCESS, false);
}

/*!
* @brief
	Print all the enviroment variables.
* @param args
	Command to execute.
	If an argument is passed, it will print an error message.
* @param var
	List of variables.
*/
static void	ft_env(char ***args, t_var **var)
{
	if (args[0][1])
	{
		printf("env: you can't set an env variable, because the ");
		printf("subject says so\n");
	}
	else
	{
		while ((*var)->next)
		{
			if ((*var)->type == ENV || (*var)->type == EXPORT)
				printf("%s=%s\n", (*var)->name, (*var)->value);
			(*var) = (*var)->next;
		}
		if ((*var)->type == ENV || (*var)->type == EXPORT)
			printf("%s=%s\n", (*var)->name, (*var)->value);
		t_var_set_to_head(var);
	}
	error_handler(SET, NULL, EXIT_SUCCESS, false);
}

/*!
* @brief
	Executes the builtin command.
* @param args
	Arguments to be executed.
* @param var
	List of variables.
*/
void	execute_builtin(char ***args, t_var **var)
{
	if (!ft_strncmp(*args[0], "cd", 2))
		ft_cd(args);
	else if (!ft_strncmp(*args[0], "echo", 4))
		ft_echo(args);
	else if (!ft_strncmp(*args[0], "pwd", 3))
	{
		printf("%s\n", getcwd(NULL, 0));
		error_handler(SET, NULL, EXIT_SUCCESS, false);
	}
	else if (!ft_strncmp(*args[0], "exit", 4))
		exit(close_shell(*args[0]));
	else if (!ft_strncmp(*args[0], "history", 7))
		print_history();
	else if (!ft_strncmp(*args[0], "env", 3))
		ft_env(args, var);
	else if (!ft_strncmp(*args[0], "export", 6))
		ft_export(args, var);
	else if (!ft_strncmp(*args[0], "unset", 5))
		ft_unset(args, var);
}

/*!
* @brief
	Checks if the command is a builtin.
* @param exe
	The command to check.
* @return
	True if the command is a builtin, false otherwise.
*/
bool	is_builtin(char *exe)
{
	if (exe && (!ft_strncmp(exe, "echo", 5) || !ft_strncmp(exe, "cd", 3) || \
		!ft_strncmp(exe, "pwd", 4) || !ft_strncmp(exe, "export", 7) || \
		!ft_strncmp(exe, "unset", 6) || !ft_strncmp(exe, "env", 4) || \
		!ft_strncmp(exe, "exit", 5) || !ft_strncmp(exe, "history", 7)))
		return (true);
	return (false);
}
