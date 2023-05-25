/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:20 by anvannin          #+#    #+#             */
/*   Updated: 2022/07/17 14:33:09 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	riga;
	int	col;

	col = 1;
	while (col <= y && x > 0)
	{
		riga = 1;
		while (riga <= x)
		{
			if ((col == 1 && riga == 1) || (col == y && riga == x)
				|| (col == 1 && riga == x) || (riga == 1 && col == y))
				ft_putchar('o');
			else if ((col == 1 || col == y || riga == 1 || riga == x)
				&& !(riga == 1 || riga == x))
				ft_putchar('-');
			else if ((col == 1 || col == y || riga == 1 || riga == x)
				&& (riga == 1 || riga == x))
				ft_putchar('|');
			else
				ft_putchar(' ');
			riga++;
		}
		ft_putchar('\n');
		col++;
	}
}
