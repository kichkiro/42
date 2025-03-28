/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:10:45 by kichkiro          #+#    #+#             */
/*   Updated: 2023/07/29 14:28:21 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_result(char *s, double sign)
{
	double	result;
	double	factor;

	result = 0.0;
	factor = 1.0;
	while (s && *s && ft_isdigit(*s))
	{
		result = result * 10.0 + (*s - '0');
		s++;
	}
	if (*s == 46 && s++)
	{
		while (ft_isdigit(*s))
		{
			result = result * 10.0 + (*s - '0');
			factor *= 10.0;
			s++;
		}
	}
	return (sign * result / factor);
}

double	ft_atof(char *s)
{
	int		sign;

	sign = 1;
	while (s && *s && *s == 32)
		s++;
	if (s && *s && *s == 45 && s++)
		sign = -1;
	else if (*s == 43)
		s++;
	return (get_result(s, sign));
}
