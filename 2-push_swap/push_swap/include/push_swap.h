/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:32:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/01 15:51:54 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct path
{
	int	src;
	int	dst;
	int	actions;
}	t_path;

typedef struct limits
{
	int	min;
	int	max;
}	t_limits;

typedef struct check_limits
{
	int		i;
	int		j;
	int		n;
	bool	sign;
	size_t	s_len;
	size_t	n_len;	
}	t_check_limits;

bool	push_swap_actions(t_stack **a, t_stack **b, char *action, bool print);
void	push_swap_algorithm_long(t_stack **a, t_stack **b);
void	push_swap_algorithm_short(t_stack **a, t_stack **b);
int		insert_index(t_stack *lst, int n, t_limits limits);
t_path	find_best_path(t_stack *a, t_stack *b, t_limits limits);

#endif