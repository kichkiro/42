/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:29:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:55:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	The strrchr() function returns a pointer to the last occurrence of the 
	character c in the string s;

	Here "character" means "byte"; this functions do not work with wide or 
	multibyte characters.
 * @return 
	The strrchr() function return a pointer to the matched character or NULL if 
	the character is not found.  
	The terminating null byte is considered part of the string, so that if c is 
	specified as '\0', this functions return a pointer to the terminator.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i--;
	}
	return (0);
}
