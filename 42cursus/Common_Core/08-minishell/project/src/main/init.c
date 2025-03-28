/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:06:33 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/25 13:06:33 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief
	Initializes the environment variables.
 * @param var
	The list of variables.
 */
static void	init_env(t_var **var)
{
	int		i;
	char	**str;

	i = -1;
	str = NULL;
	while (__environ[++i])
	{
		str = ft_split(__environ[i], '=');
		if (str[0][0] == '_')
			t_var_add_back(var, t_var_new(str[0], str[1], ENV));
		else
			t_var_add_back(var, t_var_new(str[0], str[1], EXPORT));
		ft_strmatrixfree(&str);
	}
	t_var_set_to_head(var);
}

static char	*ft_str_replace(char *str, char c, char r)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			str[i] = r;
	return (str);
}

/*!
* @brief
	Initializes the history file.
*/
static void	init_history(void)
{
	char	*hist;
	int		fd;

	hist = ft_strjoin(getenv("HOME"), "/.minishell_history");
	fd = open(hist, O_RDWR | O_APPEND | O_CREAT, 0644);
	ft_free((void **)&hist);
	hist = ft_get_next_line(fd);
	while (hist)
	{
		hist = ft_str_replace(hist, '\n', '\0');
		if (hist[0] || hist[0] != '\n')
		{
			add_history(hist);
			ft_free((void **)&hist);
			hist = ft_get_next_line(fd);
		}
	}
	ft_free((void **)&hist);
	close(fd);
}

/*!
 * @brief
	Initializes all the variables and the history file.
 * @param var
	The list of variables.
 */
void	init_all(t_var **var, t_cmd **cmd, t_cmd **head_cmd, char **whoami)
{
	*var = NULL;
	*cmd = NULL;
	*head_cmd = NULL;
	*whoami = NULL;
	init_env(var);
	init_history();
}
