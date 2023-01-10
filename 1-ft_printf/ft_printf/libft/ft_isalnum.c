/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:48:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 14:57:13 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
 	Checks for an alphanumeric character; it is equivalent to (isalpha(c) || 
	isdigit(c)).
 * @return
	The values returned are nonzero if the character c falls into the tested 
	class, and zero if not.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) == 1 || ft_isdigit(c) == 1);
}
