/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:36:26 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:26:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief  
	The bzero() function erases the data in the n bytes of the memory starting 
	at the location pointed to by s, by writing zeros (bytes containing '\0') 
	to that area.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
