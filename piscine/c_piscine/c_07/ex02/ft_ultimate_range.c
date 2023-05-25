/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:56:40 by kichkiro          #+#    #+#             */
/*   Updated: 2022/08/04 13:19:32 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		len_range;
	int		i;
	int		*buffer;

	len_range = max - min;
	i = 0;
	buffer = malloc(len_range * 4);
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	else if (!buffer)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	while (i < len_range)
	{
		buffer[i] = min + i;
		i++;
	}
	return (len_range);
}

int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	size;
	int	i = 0;

	min = 5;
	max = 10;
	size = ft_ultimate_range(&tab, min, max);
	while(i < size)
	{
		printf("%d, ", ft_ultimate_range(&tab, min, max));
		i++;
	}

}