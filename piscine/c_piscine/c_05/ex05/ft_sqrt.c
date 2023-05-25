/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:28:54 by kichkiro          #+#    #+#             */
/*   Updated: 2022/08/04 11:33:25 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	n;

	n = nb;
	i = 2;
	if (n <= 0)
		return (0);
	else if (n == 1)
		return (1);
	else if (n >= 2)
	{
		while (i * i <= n)
		{
			if (i * i == n)
				return (i);
			i++;
		}
	}
	return (0);
}
