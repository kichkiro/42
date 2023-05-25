/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:33:03 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/24 20:19:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	permute(char *tab, int l, int r, char *input);

int	validate_input(char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0')
	{
		if (i % 2 == 0 && av[1][i] < 49 && av[1][i] > 52)
			break ;
		else if (i % 2 != 0 && av[1][i] != 32)
			break ;
		i++;
	}
	if (i == 31)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		n;
	char	view[16];

	n = 16;
	if (argc == 2)
	{
		if (validate_input (argv) == 0)
		{
			permute ("1234123412341234", 0, n - 1, argv[1]);
			return (0);
		}
	}
	write (1, "Input errato", 12);
	return (0);
}
