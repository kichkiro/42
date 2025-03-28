/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:07:59 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/18 03:05:44 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	run(t_cmd **cmd, t_var **var, char *prompt, t_cmd **head_cmd)
{
	parsing_system(prompt, cmd, *var);
	*head_cmd = *cmd;
	if (*cmd && !syntax_error(cmd, prompt))
		execution_system(cmd, var);
	fd_handler(RESTORE, NULL);
	t_cmd_free(head_cmd);
	*cmd = NULL;
}

static char	*prompt_and_command(char *whoami)
{
	char	*prompt;

	whoami = ft_whoami();
	prompt = readline(whoami);
	ft_free((void **)&whoami);
	return (prompt);
}

int	main(void)
{
	t_var	*var;
	t_cmd	*cmd;
	t_cmd	*head_cmd;
	char	*whoami;
	char	*prompt;

	init_all(&var, &cmd, &head_cmd, &whoami);
	while (true)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGINT, signal_handler);
		prompt = prompt_and_command(whoami);
		if (!prompt && close_shell(prompt))
			break ;
		signals_controller(SET, false);
		if (!invalid_prompt(prompt) && !shell_variables(&var, prompt))
			run(&cmd, &var, prompt, &head_cmd);
		ft_add_history(prompt);
		ft_free((void **)&prompt);
	}
	return (bombfreeall(&var, &head_cmd, prompt));
}
