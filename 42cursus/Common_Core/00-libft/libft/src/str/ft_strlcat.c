/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:58:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 15:15:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief
	The strlcat() function concatenate strings; 
	It is designed to be safer, more consistent, and less error prone 
	replacements for strncat(3);
	Unlike this function, strlcat() take the full size of the buffer (not just 
	the length) and guarantee to NUL-terminate the result (as long as size is 
	larger than 0 or, in the case of strlcat(), as long as there is at least one 
	byte free in dst);
	Note that a byte for the NUL should be included in size;
	Also note that strlcat() only operate on true “C” strings;  
	This means that for strlcat() both src and dst must be NUL-terminated;

	The strlcat() function appends the NUL-terminated string src to the end of 
	dst;
	It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the 
	result;
 * @return 
	The strlcat() function return the total length of the string they tried to 
	create.
	For strlcat() that means the initial length of dst plus the length of src. 
	While this may seem somewhat confusing, it was done to make truncation 
	detection simple.
	Note, however, that if strlcat() traverses size characters without finding a 
	NUL, the length of the string is considered to be size and the destination 
	string will not be NUL-terminated (since there was no space for the NUL).  
	This keeps strlcat() from running off the end of a string.  
	In practice this should not happen (as it means that either size is 
	incorrect or that dst is not a proper “C” string).  
	The check exists to prevent potential security problems in incorrect code.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!size || size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
