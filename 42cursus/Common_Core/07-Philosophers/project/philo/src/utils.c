/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:10:17 by kichkiro          #+#    #+#             */
/*   Updated: 2023/03/26 18:16:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	someone_died(t_philo *philo)
{
	bool	state;

	pthread_mutex_lock(&(philo->g->death_mutex));
	state = philo->g->someone_died;
	pthread_mutex_unlock(&(philo->g->death_mutex));
	return (state);
}

int	get_input_value(char *s)
{
	int	n;

	n = -1;
	while (*s == 32)
		s++;
	if (*s == 45 || (*s != 43 && (*s < 48 || *s > 57)))
		return (n);
	if (*s == 43)
		s++;
	while (*s >= 48 && *s <= 57)
	{
		if (n == -1)
			n = 0;
		n = n * 10 + *s - 48;
		s++;
	}
	return (n);
}

int	clean_exit(t_global *g, t_philo *philo, t_fork *forks)
{
	if (g)
	{
		if (pthread_mutex_destroy(&g->death_mutex))
			return (EXIT_FAILURE);
		if (pthread_mutex_destroy(&g->philo_mutex))
			return (EXIT_FAILURE);
	}
	if (philo)
		free(philo);
	if (forks)
	{
		if (pthread_mutex_destroy(&forks->fork_mutex))
			return (EXIT_FAILURE);
		free(forks);
	}
	return (EXIT_SUCCESS);
}

int	error_handler(char *msg, t_global *g, t_philo *philo, t_fork *forks)
{
	write(2, RED_BOLD, 7);
	while (*msg)
		write(2, &*msg++, 1);
	write(2, RESET, 4);
	clean_exit(g, philo, forks);
	return (EXIT_FAILURE);
}
