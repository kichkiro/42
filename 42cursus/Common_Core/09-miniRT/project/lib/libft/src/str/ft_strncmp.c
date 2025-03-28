/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:01:37 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:55:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	The strncmp() function compares the two strings s1 and s2 only the first (at 
	most) n bytes of s1 and s2; 
	The locale is not taken into account (for a locale-aware comparison, see 
	str‐coll(3));
	The comparison is done using unsigned characters;

	strncmp() returns an integer indicating the result of the comparison, as 
	follows:

	• 0, if the s1 and s2 are equal (diff s1 - s2);

	• a negative value if s1 is less than s2 (diff s1 - s2);

	• a positive value if s1 is greater than s2 (diff s1 - s2).
 * @return 
	The strncmp() function return an integer less than, equal to, or greater 
	than zero if s1 (or the first n bytes thereof) is found, respectively, to be 
	less than, to match, or be greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
