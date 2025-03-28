/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:44:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/03/29 14:06:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*eat_state(t_philo *philo)
{
	pthread_mutex_lock(&(philo->g->print_mutex));
	if (!someone_died(philo))
		printf("%ld %d is eating 🍝\n", get_timestamp(), philo->id);
	pthread_mutex_unlock(&(philo->g->print_mutex));
	pthread_mutex_lock(&(philo->g->philo_mutex));
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&(philo->g->philo_mutex));
	usleep(philo->g->a.time_to_eat);
	pthread_mutex_lock(&(philo->g->philo_mutex));
	philo->loop++;
	pthread_mutex_unlock(&(philo->g->philo_mutex));
	return (NULL);
}

static void	*sleep_state(t_philo *philo)
{
	pthread_mutex_lock(&(philo->g->print_mutex));
	if (!someone_died(philo))
		printf("%ld %d is sleeping 💤\n", get_timestamp(), philo->id);
	pthread_mutex_unlock(&(philo->g->print_mutex));
	usleep(philo->g->a.time_to_sleep);
	return (NULL);
}

static void	*think_state(t_philo *philo)
{
	pthread_mutex_lock(&(philo->g->print_mutex));
	if (!someone_died(philo))
		printf("%ld %d is thinking 🤔\n", get_timestamp(), philo->id);
	pthread_mutex_unlock(&(philo->g->print_mutex));
	return (NULL);
}

static void	*dead_state(t_philo *philo, t_global *g)
{
	pthread_mutex_lock(&(g->death_mutex));
	g->someone_died = true;
	pthread_mutex_unlock(&(g->death_mutex));
	pthread_mutex_lock(&((*philo).g->print_mutex));
	printf("%ld %d died 💀\n", get_timestamp(), (*philo).id);
	pthread_mutex_unlock(&((*philo).g->print_mutex));
	return (NULL);
}

void	*state_handler(char state, t_philo *philo, t_global *g)
{
	if (state == EAT)
		return (eat_state(philo));
	else if (state == SLEEP)
		return (sleep_state(philo));
	else if (state == THINK)
		return (think_state(philo));
	else if (state == DEAD)
		return (dead_state(philo, g));
	return (NULL);
}
