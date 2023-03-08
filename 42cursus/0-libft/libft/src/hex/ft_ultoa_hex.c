/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:02:48 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 16:36:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a string representing the hexadecimal 
	of unsigned long integer (uintptr_t) received as an argument.
 * @param n 
	The uintptr_t to convert in hexadecimal string.
 * @return 
	The string representing the uintptr_t in exadecimal format.
	NULL if the allocation fails.
 */
char	*ft_ultoa_hex(uintptr_t n)
{
	char	*base;
	char	*str;
	size_t	i;

	base = "0123456789abcdef";
	str = ft_calloc(ft_hexlen(n) + 1, sizeof(char));
	str[0] = '0';
	i = 0;
	while (n)
	{
		str[i] = base[n % 16];
		n /= 16;
		i++;
	}
	ft_strrev(str);
	return (str);
}
