/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:00:14 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/15 00:00:24 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*!
 * @brief 
    The strlen() function calculates the length of the string pointed to by s, 
	excluding the terminating null byte ('\0').
 * @return 
    The strlen() function returns the number of bytes in the string pointed to 
	by s.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
