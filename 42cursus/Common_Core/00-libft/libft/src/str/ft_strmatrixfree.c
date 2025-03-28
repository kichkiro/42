/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatrixfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:51:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/17 01:00:26 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Free a string matrix.
 * @param matrix
	The string matrix.
 */
void	ft_strmatrixfree(char ***matrix)
{
	char	**ptr;

	if (matrix == NULL || *matrix == NULL)
		return ;
	ptr = *matrix;
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	free(*matrix);
	*matrix = NULL;
}
