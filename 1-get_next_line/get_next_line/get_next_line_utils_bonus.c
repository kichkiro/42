/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:53:45 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 16:23:05 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*!
 * @brief 
	Concatenate/append c to s and frees the memory of the s.
 * @return 
	Return new allocated string which is the result of s + c.
 */
char	*ft_char_append(char *s, char c)
{
	size_t	i;
	char	*str;

	if (!s)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (0);
		str[0] = c;
		str[1] = 0;
		return (str);
	}
	i = 0;
	while (s[i])
		i++;
	str = malloc(sizeof(char) * ++i + 1);
	if (!str)
		return (0);
	str[i - 1] = c;
	str[i--] = 0;
	while (i--)
		str[i] = s[i];
	free(s);
	return (str);
}
