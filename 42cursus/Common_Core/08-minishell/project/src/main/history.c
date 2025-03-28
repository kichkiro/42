/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:52:25 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/19 18:52:25 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
* @brief
	Adds the input to the history and the history file.
	If the input is the same as the last input, it will not be added.
	If the input is empty, it will not be added.
* @param prompt
	The input string.
*/
void	ft_add_history(char *prompt)
{
	char	*hist;
	char	*tmp;
	int		fd;

	if (prompt[0] == '\n' || prompt[0] == '\0')
		return ;
	hist = ft_strjoin(getenv("HOME"), "/.minishell_history");
	fd = open(hist, O_RDWR | O_APPEND | O_CREAT, 0644);
	tmp = NULL;
	while (hist)
	{
		ft_free((void **)&tmp);
		tmp = ft_strdup(hist);
		ft_free((void **)&hist);
		hist = ft_get_next_line(fd);
	}
	if (ft_strncmp(prompt, tmp, ft_strlen(prompt)))
	{
		ft_putendl_fd(prompt, fd);
		add_history(prompt);
	}	
	ft_free((void **)&hist);
	ft_free((void **)&tmp);
	close(fd);
}

/*!
* @brief
	Prints the history to the terminal.
*/
void	print_history(void)
{
	char	*hist;
	int		fd;
	int		i;

	i = 1;
	ft_add_history("history");
	hist = ft_strjoin(getenv("HOME"), "/.minishell_history");
	fd = open(hist, O_RDONLY);
	ft_free((void **)&hist);
	hist = ft_get_next_line(fd);
	while (hist)
	{
		ft_free((void **)&hist);
		ft_printf("\t%d.\t%s", i++, hist);
		hist = ft_get_next_line(fd);
	}
	ft_free((void **)&hist);
	close(fd);
}
