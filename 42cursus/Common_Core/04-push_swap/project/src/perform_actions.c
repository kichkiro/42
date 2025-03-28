/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:59:43 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 23:10:43 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **lst)
{
	int	tmp_data;

	tmp_data = 0;
	if (*lst && (*lst)->next)
	{
		tmp_data = (*lst)->data;
		(*lst)->data = (*lst)->next->data;
		(*lst)->next->data = tmp_data;
	}
}

static void	push(t_stack **lst1, t_stack **lst2)
{
	if (*lst1)
	{
		if (*lst2)
		{
			(*lst2)->prev = t_stack_new((*lst1)->data);
			(*lst2)->prev->next = *lst2;
			(*lst2)->prev->prev = 0;
			*lst2 = (*lst2)->prev;
		}
		else
			*lst2 = t_stack_new((*lst1)->data);
		if ((*lst1)->next != 0)
		{
			*lst1 = (*lst1)->next;
			free((*lst1)->prev);
			(*lst1)->prev = 0;
		}
		else
		{
			free(*lst1);
			*lst1 = 0;
		}
	}
}

static void	rotate(t_stack **lst)
{
	t_stack	*tmp;

	tmp = 0;
	if (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		(*lst)->prev = 0;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = tmp;
		(*lst)->next->prev = *lst;
		(*lst)->next->next = 0;
		while ((*lst)->prev)
			*lst = (*lst)->prev;
	}
}

static void	reverse_rotate(t_stack **lst)
{
	t_stack	*tmp;

	tmp = 0;
	if (*lst)
	{
		tmp = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = tmp;
		(*lst)->next->prev = *lst;
		(*lst)->prev->next = 0;
		(*lst)->prev = 0;
	}
}

/*!
 * @brief
	Performs the 11 permitted actions.
 * @details
	sa (swap a): Swap the first 2 elements at the top of stack a;
		Do nothing if there is only one or no elements;
	sb (swap b): Swap the first 2 elements at the top of stack b;
		Do nothing if there is only one or no elements;
	ss : sa and sb at the same time;
	pa (push a): Take the first element at the top of b and put it at the 
		top	of a; Do nothing if a is empty;
	pb (push b): Take the first element at the top of a and put it at the 
		top of b; Do nothing if a is empty;
	ra (rotate a): Shift up all elements of stack a by 1;
		The first element becomes the last one;
	rb (rotate b): Shift up all elements of stack b by 1;
		The first element becomes the last one;
	rr : ra and rb at the same time;
	rra (reverse rotate a): Shift down all elements of stack a by 1;
		The last element becomes the first one;
	rrb (reverse rotate b): Shift down all elements of stack b by 1;
		The last element becomes the first one;
	rrr : rra and rrb at the same time;
 * @param a 
	Bidirectional linked list represent Stack A.
 * @param b 
	Bidirectional linked list represent Stack B.
 * @param action 
	The action to perform.
 */
bool	perform_actions(t_stack **a, t_stack **b, char *action, bool print)
{
	if (!ft_strncmp(action, "sa", 3) || !ft_strncmp(action, "ss", 3))
		swap(&(*a));
	if (!ft_strncmp(action, "sb", 3) || !ft_strncmp(action, "ss", 3))
		swap(&(*b));
	if (!ft_strncmp(action, "pa", 3))
		push(&(*b), &(*a));
	if (!ft_strncmp(action, "pb", 3))
		push(&(*a), &(*b));
	if (!ft_strncmp(action, "ra", 3) || !ft_strncmp(action, "rr", 3))
		rotate(&(*a));
	if (!ft_strncmp(action, "rb", 3) || !ft_strncmp(action, "rr", 3))
		rotate(&(*b));
	if (!ft_strncmp(action, "rra", 3) || !ft_strncmp(action, "rrr", 3))
		reverse_rotate(&(*a));
	if (!ft_strncmp(action, "rrb", 3) || !ft_strncmp(action, "rrr", 3))
		reverse_rotate(&(*b));
	if (print)
		ft_printf("%s\n", action);
	return (true);
}
