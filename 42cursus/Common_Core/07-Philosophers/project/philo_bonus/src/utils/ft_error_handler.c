/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:27:43 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/15 23:40:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*!
 * @brief 
	Handle error.
 * @param msg 
	Error message.
 * @return 
	EXIT_FAILURE.
 */
int	ft_error_handler(char *msg)
{
	write(2, RED_BOLD, 7);
	while (*msg)
		write(2, &*msg++, 1);
	write(2, RESET, 4);
	return (EXIT_FAILURE);
}
