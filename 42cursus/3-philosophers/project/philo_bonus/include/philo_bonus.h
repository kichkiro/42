/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:21 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/16 13:09:29 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// Libraries ------------------------------------------------------------------>

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/wait.h>

// Macros --------------------------------------------------------------------->

# define RED_BOLD	"\033[1;31m"
# define RESET		"\x1b[0m"

// Structures ----------------------------------------------------------------->

typedef struct s_global
{
	pid_t	*philos;
	int		n_philo;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int		n_loop;
	sem_t	*forks;
	sem_t	*death;
	sem_t	*print;
}	t_global;

typedef struct s_local
{
	int			id;
	time_t		last_meal;
	sem_t		*meal;
	int			n_loop_dup;
	t_global	*g;
}	t_local;

// Functions ------------------------------------------------------------------>

bool	philos_creation(t_global *g);

time_t	ft_get_timestamp(void);
int		ft_error_handler(char *msg);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	*ft_strappend(char *s1, char *s2, bool free_s1, bool free_s2);
size_t	ft_strlen(const char *s);

#endif
