/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:30:52 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 15:04:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Applies the function ’f’ on each character of the string passed as argument,
	passing its index as first argument; 
	Each character is passed by address to ’f’ to be modified if necessary.
 * @param s 
	The string on which to iterate.
 * @param f 
	The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	char	*c;

	i = -1;
	while (s[++i])
	{
		c = &s[i];
		f(i, c);
	}
}
