/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:40:58 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 15:00:46 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	The  memcmp()  function  compares  the first n bytes (each interpreted as 
	unsigned char) of the memory areas s1 and s2.
 * @return 
	The memcmp() function returns an integer less than, equal to, or greater 
	than zero if the first n bytes of s1 is found, respectively, to be less 
	than, to match, or be greater than the first n bytes of s2.
	For a nonzero return value, the sign is determined by the sign of the  
	difference between the first pair of bytes (interpreted as unsigned char) 
	that differ in s1 and s2.
	If n is zero, the return value is zero.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
