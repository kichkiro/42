/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:51:11 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/14 17:46:50 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*!
 * @brief 
	If the ptr is not NULL, it is freed and set to NULL.
 * @return
	NULL.
 */
void	*ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
	return (*ptr);
}

/*!
 * @brief 
	The calloc() function allocates memory for an array of nmemb elements of 
	size bytes each and returns a pointer to the allocated memory.  
	The memory is set to zero.
	If nmemb or size is 0, then calloc() returns either NULL, or a unique
	pointer value that can later be successfully passed to free().  
	If the multiplication of nmemb and size would result in integer overflow, 
	then calloc() returns an error.  
	By contrast, an integer overflow would not be detected in the following call
	to malloc(), with the result that an incorrectly sized block of memory would
	be allocated:

		malloc(nmemb * size);
 * @return 
	RETURN VALUE
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

/*!
 * @brief 
	This function searches for c in s and if present returns an integer 
	representing the index of c.
 * @return 
	Int representing the index of c.
	-1 if c not present.
 */
ssize_t	ft_stridx(char *s, int c)
{
	ssize_t	i;

	i = 0;
	if (!c)
	{
		if (!*s)
			return (0);
		while (s[i])
			i++;
		return (i);
	}
	while (s[i] || (!c && !s[i]))
	{
		if (s[i] == c || (!c && !s[i]))
			return (i);
		i++;
	}
	return (-1);
}

/*!
 * @brief 
 	Concatenate/append s2 to s1.
 * @param s1 
	First string.
 * @param s2 
	Second string.
 * @param free_s1 
	If set to True, frees s1.
 * @param free_s2
	If set to True, frees s2.
 * @return 
	Return new malloc() allocated string which is the result of s1 + s2.	
 */
char	*ft_strappend(char *s1, char *s2, bool free_s1, bool free_s2)
{
	char	*str;
	long	i;
	long	j;

	str = ft_calloc(ft_stridx(s1, 0) + ft_stridx(s2, 0) + 1, sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = 0;
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (str);
}

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of	maximum size ’len’.
 * @param s 
	The string from which to create the substring.
 * @param start 
	The start index of the substring in the string s.
 * @param len
	The maximum length of the substring.
 * @param split
	If set to 1, truncates string s, up to the position of the substring.
	If set to -1 it frees the string s.
 * @return 
	The substring.
	NULL if the allocation fails.
 */
char	*ft_split_substr(char **s, int start, size_t len, char split)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start < 0)
		start = 0;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (0);
	if ((ssize_t)start > ft_stridx(*s, 0))
		return (sub);
	while (i < len && (*s)[start])
		sub[i++] = (*s)[start++];
	if (split == 1)
		*s = ft_split_substr(s, ft_stridx(sub, 0), ft_stridx(*s, 0) \
			- ft_stridx(sub, 0), -1);
	if (split == -1)
		ft_free((void **)&(*s));
	return (sub);
}
