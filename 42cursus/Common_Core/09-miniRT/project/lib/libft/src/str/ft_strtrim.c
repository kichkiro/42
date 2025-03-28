/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:28:36 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/12 18:19:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (true);
		i++;
	}
	return (false);
}

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters 
	specified in ’set’ removed from the beginning and the end of the string.
 * @param s1 
	The string to be trimmed.
 * @param set 
	The reference set of characters to trim.	
 * @return 
	The trimmed string.
	NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	char	*ret;
	size_t	i;

	i = 0;
	while (check_set(s1[i], set))
		i++;
	tmp = ft_substr(s1, i, ft_strlen(s1) - i);
	if (!tmp)
		return (0);
	i = ft_strlen(tmp) - 1;
	while (check_set(tmp[i], set))
		i--;
	ret = ft_substr(tmp, 0, i + 1);
	free(tmp);
	if (!ret)
		return (0);
	return (ret);
}
