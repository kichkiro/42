/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:22:53 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/08 17:25:55 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile char	*g_bits_to_send = 0;

static void	encode_bits(char c)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '1', true);
		else
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '0', true);
		i++;
	}
}

static void	send_message(pid_t server_pid, char *message)
{
	int		sig;
	size_t	i;
	size_t	j;

	sig = 0;
	i = 0;
	while (i < ft_strlen(message))
	{
		encode_bits(message[i]);
		j = 0;
		while (j < 8)
		{
			if (g_bits_to_send[j] == '1')
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			kill(server_pid, sig);
			usleep(50);
			j++;
		}
		ft_free((void **)&g_bits_to_send);
		i++;
	}
}

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		usleep(1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 3)
		ft_exit("Wrong number of arguments...\n", RED_B, 2, 1);
	ft_bzero(&act, sizeof(act));
	act.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
