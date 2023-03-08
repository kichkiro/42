/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:59 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/25 20:10:14 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a string representing the hexadecimal 
	of unsigned integer received as an argument.
 * @param n 
	The unsigned integer to convert in hexadecimal string.
 * @return 
	The string representing the unsigned integer in exadecimal format.
	NULL if the allocation fails.
 */
char	*ft_utoa_hex(unsigned int n, bool is_upper)
{
	char	*base;
	char	*str;
	size_t	i;

	base = "0123456789abcdef";
	if (is_upper)
		base = "0123456789ABCDEF";
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
