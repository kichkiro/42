/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:15:48 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/29 14:25:15 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
