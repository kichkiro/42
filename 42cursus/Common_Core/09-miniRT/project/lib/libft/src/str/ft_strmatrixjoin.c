/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatrixjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:16:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/11 16:49:56 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Joins a string to a matrix.
 * @param mtx 
	Matrix to join the string to.
 * @param s
	String to join to the matrix.
 * @param free_matrix 
	Whether to free the matrix or not.
 * @return 
	The new matrix.
 */
char	**ft_strmatrixjoin(char **mtx, char *s, bool free_mtx, bool free_s)
{
	char	**new_matrix;
	size_t	len;
	size_t	i;

	if (!mtx)
	{
		new_matrix = ft_calloc(2, sizeof(char *));
		new_matrix[0] = ft_strdup(s);
		if (free_s)
			free(s);
		return (new_matrix);
	}
	len = ft_strmatrixlen(mtx);
	new_matrix = ft_calloc(len + 2, sizeof(char *));
	i = -1;
	while (++i < len)
		new_matrix[i] = ft_strdup(mtx[i]);
	new_matrix[i] = ft_strdup(s);
	if (free_mtx)
		ft_strmatrixfree(&mtx);
	if (free_s)
		free(s);
	return (new_matrix);
}
