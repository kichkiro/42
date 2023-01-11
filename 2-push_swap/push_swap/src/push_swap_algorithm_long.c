/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_long.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:21:27 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/12 00:07:04 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_step_algorithm_long(t_stack **a, t_stack **b)
{
	t_ls	*s_lis;
	t_stack	*lis;

	s_lis = ft_lis(t_stack_to_arr(*a), t_stack_size(*a), 1);
	lis = t_stack_from_arr(s_lis->ls, s_lis->len, 1);
	while (t_stack_size(*a) > s_lis->len)
	{
		if (!lis || (*a)->data != lis->data)
			push_swap_actions(a, b, "pb", true);
		else
		{
			push_swap_actions(a, b, "ra", true);
			if (lis && lis->next)
			{
				lis = lis->next;
				free(lis->prev);
				lis->prev = 0;
			}
			else
				t_stack_free(&lis);
		}
	}
	free(s_lis);
	t_stack_free(&lis);
}

static void	second_step_algorithm_long(t_stack **a, t_stack **b, t_limits lmts)
{
	t_path	p;

	while (*b)
	{
		p = find_best_path(*a, *b, lmts);
		while (true)
		{
			if (!p.dst && !p.src && push_swap_actions(a, b, "pa", true))
				break ;
			else if (p.dst > 0 && p.src > 0 \
				&& push_swap_actions(a, b, "rr", true) && p.dst--)
				p.src--;
			else if (p.dst < 0 && p.src < 0 \
				&& push_swap_actions(a, b, "rrr", true) && p.dst++)
				p.src++;
			else if (p.src > 0 && push_swap_actions(a, b, "rb", true))
				p.src--;
			else if (p.src < 0 && push_swap_actions(a, b, "rrb", true))
				p.src++;
			else if (p.dst > 0 && push_swap_actions(a, b, "ra", true))
				p.dst--;
			else if (p.dst < 0 && push_swap_actions(a, b, "rra", true))
				p.dst++;
		}
	}
}

static void	third_step_algorithm_long(t_stack **a, t_stack **b, t_limits lmts)
{
	int	min_index;

	min_index = insert_index(*a, lmts.min, lmts);
	while (min_index)
	{
		if (min_index > 0)
		{
			push_swap_actions(a, b, "ra", true);
			min_index--;
		}
		else
		{
			push_swap_actions(a, b, "rra", true);
			min_index++;
		}	
	}
	while (t_stack_last(*a)->data == lmts.min)
		push_swap_actions(a, b, "rra", true);
}

/*!
 * @brief 
	The algorithm is divided into three steps:
	  - In the first phase all the elements that are not part of the longest 
		incremental subsequence are transferred to stack 'b'.
	  - As long as stack 'b' is not empty, each time the element that "costs" 
	  	less in terms of actions is identified and transferred.
	  - Finally, if the smallest element is not on the first node, the list is
	    rotated.
 * @param a 
	The address of a pointer to the first node of stack_a.
 * @param b 
	The address of a pointer to the first node of stack_b.
 */
void	push_swap_algorithm_long(t_stack **a, t_stack **b)
{
	t_limits	lmts;

	lmts.min = t_stack_min(*a);
	lmts.max = t_stack_max(*a);
	first_step_algorithm_long(a, b);
	second_step_algorithm_long(a, b, lmts);
	third_step_algorithm_long(a, b, lmts);
}
