/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:17:55 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/17 14:42:57 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n0, char n1, char n2)
{
	write (1, &n0, 1);
	write (1, &n1, 1);
	write (1, &n2, 1);
	if (n0 != '7' || n1 != '8' || n2 != '9')
		write (1, ", ", 2);
}

void	ft_check(char n0, char n1, char n2)
{
	if (n0 != n1 && n0 != n2 && n1 != n2)
	{
		if (n2 > n1 && n1 > n0)
			ft_putchar (n0, n1, n2);
	}
}

void	ft_print_comb(void)
{
	char	n0;
	char	n1;
	char	n2;

	n0 = '0';
	n1 = '1';
	n2 = '2';
	while (n0 <= '7')
	{
		n1 = '0';
		while (n1 <= '8')
		{
			n2 = '0';
			while (n2 <= '9')
			{
				ft_check (n0, n1, n2);
				n2++;
			}
			n1++;
		}
		n0++;
	}
}
