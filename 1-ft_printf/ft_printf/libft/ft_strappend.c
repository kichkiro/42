/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:54:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:24:42 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
 	Concatenate/append s2 to s1.
 * @param s1 
	First string.
 * @param s2 
	Second string.
 * @param free_s1 
	If set to True, frees s1.
 * @param free_s2
	If set to True, frees s2.
 * @return 
	Return new malloc() allocated string which is the result of s1 + s2.	
 */
char	*ft_strappend(char *s1, char *s2, bool free_s1, bool free_s2)
{
	char	*str;
	long	i;
	long	j;

	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (str);
}
