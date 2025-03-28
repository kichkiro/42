/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:34:12 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:34:53 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
 	The memset() function fills the first n bytes of the memory area pointed to 
	by s with the constant byte c.
 * @return 
 	The memset() function returns a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*ps;

	ps = (char *)s;
	while (n)
		ps[--n] = (char)c;
	return (ps);
}
