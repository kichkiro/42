/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:22:50 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/08 17:18:05 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile char	*g_received_bits = 0;

static char	decode_bits(volatile char *bits)
{
	char	c;
	size_t	i;

	c = 0;
	i = 0;
	while (i < 8)
	{
		if (bits[i] == '1')
			c |= (1 << i);
		else
			c |= 0;
		i++;
	}
	return (c);
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	char	c;

	(void)context;
	if (sig == SIGUSR1)
		g_received_bits = ft_char_append((char *)g_received_bits, '1', 1);
	else if (sig == SIGUSR2)
		g_received_bits = ft_char_append((char *)g_received_bits, '0', 1);
	else
		exit(1);
	if (ft_strlen((char *)g_received_bits) == 8)
	{
		c = decode_bits(g_received_bits);
		write(1, &c, 1);
		ft_free((void **)&g_received_bits);
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
		ft_exit("Too many arguments...\n", RED_B, 2, 1);
	ft_printf("%sServer PID ->%s %i%s\n", WHITE_B, MAGENTA_B, getpid(), RESET);
	while (true)
	{
		ft_bzero(&act, sizeof(act));
		act.sa_sigaction = &sig_handler;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
	}
	return (0);
}
