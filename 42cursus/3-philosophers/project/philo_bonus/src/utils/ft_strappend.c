/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:52:54 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/14 23:53:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = 0;
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (str);
}
