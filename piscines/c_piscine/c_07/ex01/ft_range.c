/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:04:39 by kichkiro          #+#    #+#             */
/*   Updated: 2022/08/04 12:02:57 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len_range;
	int	*range;

	len_range = max - min;
	range = malloc(len_range * 4);
	if (len_range <= 0 || !range)
		return (0);
	while (max >= min)
	{
		range[len_range] = max;
		max--;
		len_range--;
	}
	return (range);
}
