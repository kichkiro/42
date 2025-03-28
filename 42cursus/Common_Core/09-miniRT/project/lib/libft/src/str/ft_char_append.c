/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:53:45 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/18 10:07:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	If s exist, append c to s, else allocate new string.
 * @param s 
	String.
 * @param c 
	Char to append.
 * @param need_to_free 
	If true and string exist, frees the memory of the s.
 * @return 
	Return new allocated string which is the result of s + c.
 */
char	*ft_char_append(char *s, char c, bool to_free)
{
	size_t	i;
	char	*str;

	if (!s)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (!str)
			return (0);
		str[0] = c;
		str[1] = 0;
		return (str);
	}
	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(char) * ++i + 1);
	if (!str)
		return (0);
	str[i - 1] = c;
	str[i--] = 0;
	while (i--)
		str[i] = s[i];
	if (to_free && s)
		ft_free((void **)&s);
	return (str);
}
