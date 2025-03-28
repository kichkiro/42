/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:17:57 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:56:09 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function convert lowercase letters to uppercase;

	If c is a lowercase letter, toupper() returns its uppercase equivalent, if 
	an uppercase representation exists in the current locale, otherwise, it 
	returns c;

	If c is neither an unsigned char value nor EOF, the behavior of this 
	function is	undefined.
 * @return 
	The value returned is that of the converted letter, or c if the conversion 
	was not	possible.
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
