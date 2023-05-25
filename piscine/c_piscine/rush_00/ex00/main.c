/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:04:29 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/17 18:12:33 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_pseudo_atoi(char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}	
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc == 3)
	{
		if ((*argv[1] >= 'A' && *argv[1] <= 'Z')
			|| (*argv[1] >= 'a' && *argv[1] <= 'z')
			|| (*argv[2] >= 'A' && *argv[2] <= 'Z')
			|| (*argv[2] >= 'a' && *argv[2] <= 'z'))
			write(1, "Please insert a number", 22);
		x = ft_pseudo_atoi(argv[1]);
		y = ft_pseudo_atoi(argv[2]);
		if (x >= 0 && y >= 0)
			rush(x, y);
		else
			write(1, "Please insert a positive number", 31);
	}
	else if (argc < 3)
		write(1, "Too few arguments", 17);
	else
		write(1, "Too many arguments", 18);
	return (0);
}
