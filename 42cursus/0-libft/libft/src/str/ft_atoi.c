/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:38:38 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:56:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	The atoi() function converts the initial portion of the string pointed to by 
	nptr to int;
	The behavior is the same as

		strtol(nptr, NULL, 10);

	except that atoi() does not detect errors.
 * @return 
	The converted value or 0 on error.
 */
int	ft_atoi(const char *nptr)
{
	int		i;
	int		n;
	char	sign;

	i = 0;
	n = 0;
	sign = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45)
		sign = -1;
	if (nptr[i] == 43 || nptr[i] == 45)
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (sign)
		n *= sign;
	return (n);
}
