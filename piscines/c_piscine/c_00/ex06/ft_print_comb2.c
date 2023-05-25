/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:02:24 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/17 17:51:01 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n0, char n1, char n2, char n3)
{
	write (1, &n0, 1);
	write (1, &n1, 1);
	write (1, " ", 1);
	write (1, &n2, 1);
	write (1, &n3, 1);
	if (n0 != '9' || n1 != '8' || n2 != '9' || n3 != '9')
		write (1, ", ", 2);
}

void	ft_check(char n0, char n1, char n2, char n3)
{
	if (n3 > n1 && n2 >= n0)
		ft_putchar (n0, n1, n2, n3);
}

void	ft_for_norminette(char n0, char n1, char n2, char n3)
{	
	while (n3 <= '9')
	{
		ft_check (n0, n1, n2, n3);
		n3++;
	}
}

void	ft_print_comb2(void)
{
	char	n0;
	char	n1;
	char	n2;
	char	n3;

	n0 = '0';
	while (n0 <= '9')
	{
		n1 = '0';
		while (n1 <= '8')
		{
			n2 = '0';
			while (n2 <= '9')
			{
				n3 = '0';
				ft_for_norminette(n0, n1, n2, n3);
				n2++;
			}
			n1++;
		}
		n0++;
	}
}
