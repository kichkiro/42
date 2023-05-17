/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:43:46 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/16 12:58:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*killer_thread(void *args)
{
	t_global	*g;
	int			i;

	g = (t_global *)args;
	i = -1;
	sem_wait(g->death);
	while (++i < g->n_philo)
	{
		if (kill(g->philos[i], SIGKILL) == -1)
		{
			ft_error_handler("Error: kill\n");
			return (NULL);
		}
	}
	return (NULL);
}

static int	clean_exit(t_global *g)
{
	int		i;
	char	*name_sem;

	i = -1;
	while (++i < g->n_philo)
	{
		name_sem = ft_strappend("last_meal_", ft_itoa(i + 1), false, true);
		sem_unlink(name_sem);
		free(name_sem);
	}
	sem_close(g->death);
	sem_unlink("death");
	sem_close(g->print);
	sem_unlink("print");
	sem_close(g->forks);
	sem_unlink("forks");
	free(g->philos);
	free(g);
	return (EXIT_SUCCESS);
}

static int	get_input_value(char *s)
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

static bool	init_global(t_global **g, int argc, char **argv)
{
	*g = (t_global *)malloc(sizeof(t_global));
	if (!*g)
		return (false);
	(*g)->n_philo = get_input_value(argv[1]);
	(*g)->time_to_die = get_input_value(argv[2]) * 1000;
	(*g)->time_to_eat = get_input_value(argv[3]) * 1000;
	(*g)->time_to_sleep = get_input_value(argv[4]) * 1000;
	(*g)->n_loop = -2;
	(*g)->philos = (pid_t *)ft_calloc((*g)->n_philo, sizeof(pid_t));
	if (!(*g)->philos)
		return (false);
	if (argc == 6)
		(*g)->n_loop = get_input_value(argv[5]);
	if ((*g)->n_philo == -1 || (*g)->time_to_die == -1 || (*g)->time_to_eat \
		== -1 || (*g)->time_to_sleep == -1 || (*g)->n_loop == -1)
		return (false);
	(*g)->forks = sem_open("forks", O_CREAT, 0666, (*g)->n_philo);
	(*g)->print = sem_open("print", O_CREAT, 0666, 1);
	(*g)->death = sem_open("death", O_CREAT, 0666, 0);
	if ((*g)->forks == SEM_FAILED || (*g)->print == SEM_FAILED \
		|| (*g)->death == SEM_FAILED)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	pthread_t	killer;
	t_global	*g;

	if (argc < 5 || argc > 6)
		return (ft_error_handler("Wrong number of args\n"));
	else if (!init_global(&g, argc, argv))
		return (ft_error_handler("Wrong args\n"));
	else if (!philos_creation(g))
		return (ft_error_handler("Error: create_philos\n"));
	else if (pthread_create(&killer, NULL, killer_thread, (void *)g) != 0)
		return (ft_error_handler("Error: pthread_create\n"));
	else if (pthread_join(killer, NULL) != 0)
		return (ft_error_handler("Error: pthread_join\n"));
	return (clean_exit(g));
}
