/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:43:43 by kichkiro          #+#    #+#             */
/*   Updated: 2022/08/01 13:03:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = ft_strlen(src);
	dup = (char *)malloc(i);
	while (i >= 0)
	{
		dup[i] = src[i];
		i--;
	}
	return (dup);
}
