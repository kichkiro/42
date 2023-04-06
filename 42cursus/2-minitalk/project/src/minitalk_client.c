/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:24:17 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 22:41:37 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char	*g_bits_to_send = 0;

/**
 * @brief 
	Encodes a character into 8 bits and appends the bits to a global char array.
 * @details 
	The function takes a character and encodes it into 8 bits, which are then 
	appended to a global char array, g_bits_to_send;
	If the bit is 1, it appends '1' to the array, else it appends '0' to the 
	array.
 * @param c 
 	The character to be encoded.
 */
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

/**
 * @brief 
	Sends a message to a server process.
 * @details 
	The function takes a server process ID and a message string, encodes each 
	character of the message into bits and sends the bits to the server process 
	using the signals SIGUSR1 and SIGUSR2;
	Each bit is sent as a signal, with a delay of 50 microseconds between each 
	signal.
 * @param server_pid 
	The ID of the server process.
 * @param message 
	The message string to be sent to the server process.
 */
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

/**
 * @brief 
	The main function.
 * @details 
	The function takes two arguments: a server process ID and a message string;
	If the number of arguments is not equal to 3, the function exits with an 
	error message;
	Otherwise, the function calls the send_message function with the given 
	server process ID and message string.
 * @param argc 
	The number of arguments passed to the program.
 * @param argv 
	An array of strings containing the program arguments.
 * @return 
	0 if the program runs successfully.
 */
int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_exit("Wrong number of arguments...\n", RED_B, 2, 1);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
