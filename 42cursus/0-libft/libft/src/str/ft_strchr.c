/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:11:37 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/06 17:17:25 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	The strchr() function return a pointer to the first occurrence of the 
	character c in the string s.
 * @return 
	The  strchr() function return a pointer to the matched character or NULL if 
	the character is not found.  
	The terminating null byte is considered part of the string, so that if c is 
	specified as '\0', this function return a pointer to the terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!c)
	{
		while (s[i])
			i++;
		return ((char *) s + i);
	}
	c %= 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	return (0);
}
