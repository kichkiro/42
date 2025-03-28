/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:53:08 by kichkiro          #+#    #+#             */
/*   Updated: 2022/11/15 18:19:47 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Calculates the length of a hexadecimal number.
 * @param n 
	Number.
 * @return 
	Returns a size_t representing the length of a number in hexadecimal format.
 */
size_t	ft_hexlen(size_t n)
{
	size_t	i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}
