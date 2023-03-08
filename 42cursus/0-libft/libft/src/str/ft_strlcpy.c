/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:52:12 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:53:19 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
 	The strlcpy() functions copy strings; 
	It is designed to be safer, more consistent, and less error prone 
	replacements for strncpy(3);
	Unlike this function, take the full size of the buffer (not just the length) 
	and guarantee to NULterminate the result (as long as size is larger than 0);
	Note that a byte for the NUL should be included in size;
	Also note that strlcpy() only operate on true “C” strings;
	This means that for strlcpy() src must be NUL-terminated;

	The strlcpy() function copies up to size - 1 characters from the 
	NUL-terminated string src to dst, NUL-terminating the result;
 * @return 
 	The strlcpy() function return the total length of the string it tried to 
	create.  
	For strlcpy() that means the length of src.  
	While this may seem somewhat confusing, it was done to make truncation 
	detection simple.
	This keeps strlcat() from running off the end of a string.  
	In practice this should not	happen (as it means that either size is 
	incorrect or that dst is not a proper “C” string).  
	The check exists to prevent potential security problems in incorrect code.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (size)
	{
		while (src[++i] && i < (size - 1))
			dst[i] = src[i];
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
