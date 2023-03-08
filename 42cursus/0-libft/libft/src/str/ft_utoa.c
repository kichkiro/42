/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:00:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:19:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a string representing the of unsigned 
	integer received as an argument.
 * @param n 
	The unsigned integer to convert in string.
 * @return 
	The string representing the unsigned integer.
	NULL if the allocation fails.
 */
char	*ft_utoa(unsigned int nb)
{
	char			*str;
	unsigned int	n;
	size_t			len;

	n = nb;
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (!nb)
		len++;
	str = ft_calloc(len + 1, sizeof(char));
	if (!nb)
		str[0] = '0';
	while (nb && len--)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}	
	return (str);
}
