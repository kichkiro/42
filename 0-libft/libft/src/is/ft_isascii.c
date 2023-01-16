/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:54:25 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/27 20:27:44 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
 	Checks whether c is a 7-bit unsigned char value that fits into the ASCII 
	character set.
 * @return 
 	The values returned are nonzero if the character c falls into the tested 
	class, and zero if not.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
