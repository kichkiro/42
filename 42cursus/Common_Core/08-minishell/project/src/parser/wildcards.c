/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:37:43 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 00:08:23 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 * @brief 
	This function is used to match a string with a pattern that contains 
	wildcards (*).
	It returns true if the string matches the pattern, otherwise false.
 * @param s 
	The string to be matched.
 * @param pattern 
	The pattern containing wildcards.
 * @return 
	True if the string matches the pattern, false otherwise.
 */
static bool	matcher(char *s, char *pattern)
{
	while (*s || *pattern)
	{
		if (*pattern == '*')
		{
			while (*pattern == '*')
				pattern++;
			if (!*pattern)
				return (true);
			while (*s)
			{
				if (matcher(s++, pattern))
					return (true);
			}
			return (false);
		}
		else if (*pattern == *s)
		{
			pattern++;
			s++;
		}
		else
			return (false);
	}
	return (true);
}

/*!
 * @brief 
	This function retrieves all files in the specified directory and appends 
	tokens to the command list based on certain conditions.
 * @param cmd 
	Linked list containing command line.
 * @param type 
	Pointer to type of the token.
 * @param dir 
	Pointer to the directory structure.
 */
static void	get_all(t_cmd **cmd, char *type, DIR *dir)
{
	struct dirent	*entry;
	char			*tmp;

	entry = readdir(dir);
	tmp = NULL;
	while (entry)
	{
		*type = STANDARD;
		tmp = ft_strdup(entry->d_name);
		if (ft_strncmp(tmp, ".", 1))
			token_append(&tmp, type, cmd, true);
		ft_free((void **)&tmp);
		entry = readdir(dir);
	}
	ft_free((void **)&tmp);
}

/*!
 * @brief 
	This function finds a match for the given token in the specified directory 
	and appends the matched tokens to the command list.
 * @param token 
	The token to be matched.
 * @param cmd 
	Linked list containing command line.
 * @param type 
	Pointer to type of the token.
 * @param dir 
	Pointer to the directory structure.
 */
static void	find_match(char *token, t_cmd **cmd, char *type, DIR *dir)
{
	bool			find_match;
	bool			found;
	char			*tmp_token;
	struct dirent	*entry;

	find_match = false;
	found = false;
	entry = readdir(dir);
	while (entry)
	{
		find_match = matcher(entry->d_name, token);
		if (find_match)
		{
			found = true;
			tmp_token = ft_strdup(entry->d_name);
			if (ft_strncmp(tmp_token, ".", 1))
			{
				*type = STANDARD;
				token_append(&tmp_token, type, cmd, true);
			}
		}
		entry = readdir(dir);
	}
	if (!found)
		token_append(&token, type, cmd, false);
}

/*!
 * @brief 
	This function searches for files in the specified path based on the given 
	token and appends the matched tokens to the command list.
 * @param path 
	The path to search for files.
 * @param token 
	The token to be matched.
 * @param cmd 
	Linked list containing command line.
 * @param type 
	Pointer to type of the token.
 */
static void	find_files(char *path, char *token, t_cmd **cmd, char *type)
{
	DIR	*dir;

	dir = opendir(path);
	if (!dir)
	{
		error_handler(PRINT, NULL, 1, true);
		return ;
	}
	if (!ft_strncmp(token, "*", 2))
		get_all(cmd, type, dir);
	else
		find_match(token, cmd, type, dir);
	closedir(dir);
}

/*!
 * @brief 
	This function handles wildcards in the token by finding matching files and 
	appending them to the command list.
 * @param token 
	The token to be matched.
 * @param cmd 
	Linked list containing command line.
 * @param type 
	Pointer to type of the token.
 */
void	wildcards_handler(char *token, t_cmd **cmd, char *type)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)))
		find_files(cwd, token, cmd, type);
	else
		error_handler(PRINT, NULL, 1, true);
}
