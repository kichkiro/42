/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:48:18 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:44:25 by kichkiro         ###   ########.fr       */
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
	The start index of the substring in the string ’s.
 * @param len 
	The maximum length of the substring.
 * @return 
	The substring.
	NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s || !ft_strlen(s) || !len || start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (0);
	while (i < len && s[start])
		sub[i++] = s[start++];
	return (sub);
}
