/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatrixlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:22:09 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/21 19:53:05 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Returns the length of a matrix.
 * @param matrix
	The matrix to get the length of. 
 * @return 
	The length of the matrix.
 */
size_t	ft_strmatrixlen(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}
