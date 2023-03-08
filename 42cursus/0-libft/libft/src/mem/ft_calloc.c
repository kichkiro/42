/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:11:35 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 13:44:34 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	The calloc() function allocates memory for an array of nmemb elements of 
	size bytes each and returns a pointer to the allocated memory; 
	The memory is set to zero;
	If nmemb or size is 0, then calloc() returns either NULL, or a unique
	pointer value that can later be successfully passed to free();
	If the multiplication of nmemb and size would result in integer overflow, 
	then calloc() returns an error;
	By contrast, an integer overflow would not be detected in the following call
	to malloc(), with the result that an incorrectly sized block of memory would
	be allocated:

		malloc(nmemb * size);
 * @return 
	The calloc() function return a pointer to the allocated memory, which is 
	suitably aligned for any built-in type.  
	On error, these functions return NULL.  
	NULL may also be returned by a successful call to malloc() with a  size  of
	zero, or by a successful call to calloc() with nmemb or size equal to zero.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ptr;
	unsigned int	mem;
	unsigned int	i;

	mem = nmemb * size;
	ptr = malloc(mem);
	if (!ptr)
		return (0);
	i = 0;
	while (mem--)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
