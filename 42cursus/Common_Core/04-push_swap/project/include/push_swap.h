/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:32:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 23:12:23 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries ------------------------------------------------------------------>

# include "../lib/libft/include/libft.h"

// Structures ----------------------------------------------------------------->

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

// Linked Lists --------------------------------------------------------------->

/*!
 * @brief 
	Bidirectional linked list where the data of each node is an integer.
 */
typedef struct stack
{
	int				data;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

t_stack	*t_stack_new(int data);
void	t_stack_add_back(t_stack **lst, t_stack *new_node);
int		t_stack_size(t_stack *lst);
void	t_stack_set_to_head(t_stack **lst);
bool	t_stack_n_is_inside(t_stack *lst, int n);
t_stack	*t_stack_head(t_stack *lst);
t_stack	*t_stack_last(t_stack *lst);
int		*t_stack_to_arr(t_stack *lst);
t_stack	*t_stack_from_arr(long *arr, int size, bool need_to_free);
int		t_stack_min(t_stack *lst);
int		t_stack_max(t_stack *lst);
int		t_stack_second_min(t_stack *lst, int min);
bool	t_stack_is_sorted(t_stack *lst);
bool	t_stack_n_is_inside(t_stack *lst, int n);
void	t_stack_del_last(t_stack **lst);
bool	t_stack_check_dup(t_stack *lst);
void	*t_stack_free(t_stack **lst);
int		t_stack_index_data(t_stack *lst, int data);

// Main Functions ------------------------------------------------------------->

bool	perform_actions(t_stack **a, t_stack **b, char *action, bool print);
void	algorithm_long(t_stack **a, t_stack **b);
void	algorithm_short(t_stack **a, t_stack **b);
int		insert_index(t_stack *lst, int n, t_limits limits);
t_path	find_best_path(t_stack *a, t_stack *b, t_limits limits);

#endif
