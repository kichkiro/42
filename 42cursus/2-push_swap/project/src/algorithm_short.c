/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:06:25 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 23:10:17 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_numbers_algorithm(t_stack **a, t_stack **b, t_limits limits)
{
	int	max_index;

	max_index = t_stack_index_data(*a, limits.max);
	if (!max_index)
	{
		if (t_stack_size(*b) == 2 && t_stack_is_sorted(*b))
			perform_actions(a, b, "rr", true);
		else
			perform_actions(a, b, "ra", true);
	}
	else if (max_index == 1)
	{
		if (t_stack_size(*b) == 2 && t_stack_is_sorted(*b))
			perform_actions(a, b, "rrr", true);
		else
			perform_actions(a, b, "rra", true);
	}
	if ((*a)->data > (*a)->next->data)
		perform_actions(a, b, "sa", true);
	if (t_stack_size(*b) == 2 && t_stack_is_sorted(*b))
		perform_actions(a, b, "rb", true);
}

static void	four_numbers_algorithm(t_stack **a, t_stack **b, t_limits limits)
{
	int			min_index;

	min_index = t_stack_index_data(*a, limits.min);
	if (!min_index)
		perform_actions(a, b, "pb", true);
	else if (min_index == 1)
	{
		perform_actions(a, b, "ra", true);
		perform_actions(a, b, "pb", true);
	}
	else if (min_index == 2)
	{
		perform_actions(a, b, "ra", true);
		perform_actions(a, b, "ra", true);
		perform_actions(a, b, "pb", true);
	}
	else if (min_index == 3)
	{
		perform_actions(a, b, "rra", true);
		perform_actions(a, b, "pb", true);
	}
	three_numbers_algorithm(a, b, limits);
	perform_actions(a, b, "pa", true);
}

static void	five_numbers_algorithm(t_stack **a, t_stack **b, t_limits limits)
{
	int			second_min;
	int			m_i;
	int			sm_i;

	second_min = t_stack_second_min(*a, limits.min);
	m_i = t_stack_index_data(*a, limits.min);
	sm_i = t_stack_index_data(*a, second_min);
	if (!m_i || !sm_i)
		perform_actions(a, b, "pb", true);
	else if ((m_i == 1 || sm_i == 1) && perform_actions(a, b, "ra", true))
		perform_actions(a, b, "pb", true);
	else if ((m_i == 4 || sm_i == 4) && perform_actions(a, b, "rra", true))
		perform_actions(a, b, "pb", true);
	else if (m_i == 2 || sm_i == 2)
	{
		perform_actions(a, b, "ra", true);
		perform_actions(a, b, "ra", true);
		perform_actions(a, b, "pb", true);
	}
	limits.min = t_stack_min(*a);
	four_numbers_algorithm(a, b, limits);
	perform_actions(a, b, "pa", true);
}

/*!
 * @brief 
	Sorting algorithm for numbers >= 2 and <= 5.
 * @details
	The algorithm works as follows:
	  - If the number of elements is greater than 3, the smallest excess 
	  	elements are transferred to stack 'b' in the least number of actions and
		sorted in descending order;
	  - When there are 3 or less elements in stack 'a', the goal of the 
	  	algorithm is to locate the largest element and move it with a single 
		action to the last node;
	  - If the element at the first node is greater than the second element they 
	  	are swapped;
	  - Finally (if there are elements in stack 'b') the two stacks are merged.
 * @param a 
	The address of a pointer to the first node of stack_a.
 * @param b 
	The address of a pointer to the first node of stack_b.
 */
void	algorithm_short(t_stack **a, t_stack **b)
{
	t_limits	limits;

	limits.min = t_stack_min(*a);
	limits.max = t_stack_max(*a);
	if (t_stack_size(*a) <= 3)
		three_numbers_algorithm(a, b, limits);
	else if (t_stack_size(*a) == 4)
		four_numbers_algorithm(a, b, limits);
	else
		five_numbers_algorithm(a, b, limits);
}
