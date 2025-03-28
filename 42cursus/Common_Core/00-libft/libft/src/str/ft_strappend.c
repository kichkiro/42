/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:54:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/13 15:42:30 by kichkiro         ###   ########.fr       */
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
	char	*s;
	ssize_t	i;
	ssize_t	j;

	if (!s1)
		s = (char *)ft_calloc(ft_strlen(s2) + 1, sizeof(char));
	else
		s = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s)
		return (0);
	i = -1;
	while (s1 && s1[++i])
		s[i] = s1[i];
	j = -1;
	if (!s1)
		i++;
	while (s2 && s2[++j])
		s[i++] = s2[j];
	if (free_s1 && s1)
		ft_free((void **)&s1);
	if (free_s2 && s2)
		ft_free((void **)&s2);
	return (s);
}
