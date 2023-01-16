/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:53:15 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:58:57 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_if_zero(void)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (0);
	str[0] = '0';
	return (str);
}

static char	*ft_if_negative(long nb)
{
	char	*str;
	long	n;
	size_t	len;

	nb *= -1;
	n = nb;
	len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	str[0] = '-';
	while (nb && len--)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}	
	return (str);
}

static char	*ft_if_positive(long nb)
{
	char	*str;
	long	n;
	size_t	len;

	n = nb;
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (nb && len--)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}	
	return (str);
}

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a string	representing the integer 
	received as an argument;
	Negative numbers must be handled.
 * @param n 
	the integer to convert.
 * @return 
	The string representing the integer.
	NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	if (!n)
		return (ft_if_zero());
	else if (n < 0)
		return (ft_if_negative(n));
	else
		return (ft_if_positive(n));
}
