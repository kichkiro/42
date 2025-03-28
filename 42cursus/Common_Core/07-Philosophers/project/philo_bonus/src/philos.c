/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:13:42 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/16 13:10:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*death_thread(void *args)
{
	t_local	*l;

	l = (t_local *)args;
	while (l->n_loop_dup)
	{
		sem_wait(l->meal);
		if ((ft_get_timestamp() - l->last_meal) > (l->g->time_to_die / 1000))
		{
			sem_wait(l->g->print);
			printf("[%ld] %d died 💀\n", ft_get_timestamp(), l->id);
			sem_post(l->g->death);
		}
		sem_post(l->meal);
	}
	return (NULL);
}

static void	philo_life(t_local *l)
{
	sem_wait(l->g->forks);
	sem_wait(l->g->print);
	printf("[%ld] %d has taken a fork 🍴\n", ft_get_timestamp(), l->id);
	sem_post(l->g->print);
	sem_wait(l->g->forks);
	sem_wait(l->g->print);
	printf("[%ld] %d has taken a fork 🍴\n", ft_get_timestamp(), l->id);
	printf("[%ld] %d is eating 🍝\n", ft_get_timestamp(), l->id);
	sem_post(l->g->print);
	sem_wait(l->meal);
	l->last_meal = ft_get_timestamp();
	sem_post(l->meal);
	usleep(l->g->time_to_eat);
	sem_post(l->g->forks);
	sem_post(l->g->forks);
	sem_wait(l->g->print);
	printf("[%ld] %d is sleeping 💤\n", ft_get_timestamp(), l->id);
	sem_post(l->g->print);
	usleep(l->g->time_to_sleep);
	sem_wait(l->g->print);
	printf("[%ld] %d is thinking 🤔\n", ft_get_timestamp(), l->id);
	sem_post(l->g->print);
	if (l->g->time_to_die - l->g->time_to_eat - l->g->time_to_sleep - 10000 > 0)
		usleep(l->g->time_to_die - l->g->time_to_eat - l->g->time_to_sleep - \
		10000);
}

static bool	init_local(t_local **l, t_global *g, int id)
{
	char	*name_sem;
	sem_t	*last_meal;

	name_sem = ft_strappend("last_meal_", ft_itoa(id), false, true);
	last_meal = sem_open(name_sem, O_CREAT, 0666, 1);
	free(name_sem);
	*l = (t_local *)malloc(sizeof(t_local));
	if (!*l)
		return (false);
	(*l)->id = id;
	(*l)->g = g;
	(*l)->meal = last_meal;
	(*l)->last_meal = ft_get_timestamp();
	(*l)->n_loop_dup = g->n_loop;
	return (true);
}

static int	philo_routine(t_global *g, int id)
{
	t_local		*l;
	pthread_t	death;

	if (!init_local(&l, g, id))
		return (ft_error_handler("Error: malloc\n"));
	if (pthread_create(&death, NULL, death_thread, (void *)l) != 0)
		return (ft_error_handler("Error: pthread_create\n"));
	if (pthread_detach(death) != 0)
		return (ft_error_handler("Error: pthread_detach\n"));
	if (l->id % 2)
		usleep(60000);
	while (l->g->n_loop)
	{
		philo_life(l);
		l->g->n_loop--;
	}
	return (EXIT_SUCCESS);
}

bool	philos_creation(t_global *g)
{
	int	i;

	i = -1;
	while (++i < g->n_philo)
	{
		g->philos[i] = fork();
		if (g->philos[i] == -1)
			return (ft_error_handler("Error: fork\n"));
		else if (g->philos[i] == 0)
		{
			philo_routine(g, i + 1);
			sem_post(g->death);
			exit(0);
		}
	}
	return (true);
}
