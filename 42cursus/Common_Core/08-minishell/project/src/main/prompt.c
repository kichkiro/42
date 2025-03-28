/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:27:53 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/19 16:27:53 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	This function determines the user's directory level by comparing the current 
	working directory path with the user's name.
 * @return 
	 The user's directory level.
 */
static int	usr_dir_level(void)
{
	int		i;
	int		j;
	char	**path;
	char	*cwd;

	i = 0;
	j = 2;
	cwd = getcwd(NULL, 0);
	path = ft_split(cwd, '/');
	while (path[i])
	{
		if (!ft_strncmp(path[i], getenv("USER"), ft_strlen(path[i])))
			j = i;
		i++;
	}
	ft_free((void **)&cwd);
	ft_strmatrixfree(&path);
	return (j);
}

/*!
 * @brief 
	This function builds a path string by concatenating directory names from the
	path array.
 * @param path 
	The array containing directory names.
 * @param i 
	The index indicating the starting position in the path array.
 * @return 
	The built path string.
 */
static char	*build_path(char **path, int i)
{
	char	*str;
	int		j;

	j = usr_dir_level();
	if (i > j)
	{
		str = ft_strdup("~/");
		i = j;
	}
	else
	{
		str = ft_strdup("/");
		i = -1;
	}
	while (path[++i])
	{
		if (!path[i + 1])
			str = ft_strappend(str, path[i], true, false);
		else
			str = ft_strappend(str, ft_char_append(path[i], '/', false), 1, 1);
	}
	return (str);
}

/*!
* @brief
	Returns a string containing the relative path of the current directory.
* @return
	The relative path string.
*/
static char	*curent_dir(void)
{
	char	**path;
	char	*cwd;
	char	*ret;
	int		i;

	cwd = getcwd(NULL, 0);
	i = 0;
	path = ft_split(cwd, '/');
	while (path[i])
		i++;
	ft_free((void **)&cwd);
	ret = build_path(path, i);
	ft_strmatrixfree(&path);
	return (ret);
}

/*!
* @brief
	Returns the command prompt a string.
* @return
	The prompt string.
*/
char	*ft_whoami(void)
{
	char	*prompt;

	prompt = ft_strappend(BLUE"\n┌─"RESET, WHITE_B"[", false, false);
	prompt = ft_strappend(prompt, getenv("USER"), true, false);
	prompt = ft_strappend(prompt, "@minishell] "RESET, true, false);
	prompt = ft_strappend(prompt, RED_B, true, false);
	prompt = ft_strappend(prompt, curent_dir(), true, true);
	prompt = ft_strappend(prompt, RESET"\n", true, false);
	prompt = ft_strappend(prompt, BLUE"└─"RESET, true, false);
	prompt = ft_strappend(prompt, RED_B"[$] "RESET, true, false);
	return (prompt);
}
