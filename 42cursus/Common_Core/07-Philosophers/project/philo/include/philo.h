/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/03/29 14:07:36 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Libraries ------------------------------------------------------------------>

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

// Macros --------------------------------------------------------------------->

# define THINK		0
# define EAT		1
# define SLEEP		2
# define DEAD		3

# define UP			1
# define DOWN		0

# define LEFT_FORK	-42
# define RIGHT_FORK 42

# define RED_BOLD	"\033[1;31m"
# define RESET		"\x1b[0m"

// Structures ----------------------------------------------------------------->

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_args
{
	int				n_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				n_loop;
}	t_args;

typedef struct s_global
{
	t_args			a;
	bool			someone_died;
	pthread_t		t_supervisor;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	philo_mutex;
}	t_global;

typedef struct s_philo
{
	t_global		*g;
	unsigned char	id;
	pthread_t		t_philosopher;
	int				loop;
	time_t			last_meal;
	t_fork			*right_fork;
	t_fork			*left_fork;
	bool			right_fork_state;
	bool			left_fork_state;
}	t_philo;

// Functions ------------------------------------------------------------------>

bool	thread_handler(t_global *g, t_philo **philos);
void	*state_handler(char state, t_philo *philo, t_global *g);

int		someone_died(t_philo *philo);
time_t	get_timestamp(void);
int		get_input_value(char *s);
int		clean_exit(t_global *g, t_philo *philo, t_fork *forks);
int		error_handler(char *msg, t_global *g, t_philo *philo, t_fork *forks);

#endif
