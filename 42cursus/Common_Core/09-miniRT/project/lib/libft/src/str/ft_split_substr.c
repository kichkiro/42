/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_substr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:41:32 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/14 16:23:50 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a substring from the string ’s’;
	The substring begins at index ’start’ and is of	maximum size ’len’.
 * @param s 
	The string from which to create the substring.
 * @param start 
	The start index of the substring in the string s.
 * @param len 
	The maximum length of the substring.
 * @param split 
	If set to 1, truncates string s, up to the position of the substring.
	If set to -1 it frees the string s.
 * @return 
	The substring.
	NULL if the allocation fails.
 */
char	*ft_split_substr(char **s, int start, size_t len, char split)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start < 0)
		start = 0;
	sub = malloc(len + 1);
	if (!sub)
		return (0);
	if ((ssize_t)start > ft_stridx(*s, 0))
	{
		sub[0] = 0;
		return (sub);
	}
	while (i < len && (*s)[start])
		sub[i++] = (*s)[start++];
	sub[i] = 0;
	if (split == 1)
		*s = ft_split_substr(s, ft_stridx(sub, 0), ft_stridx(*s, 0) \
			- ft_stridx(sub, 0), -1);
	if (split == -1)
		ft_free((void **)&(*s));
	return (sub);
}
