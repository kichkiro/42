/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:38:50 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 23:09:30 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_down(t_stack *lst, int n, t_limits lmtst)
{
	int	down;

	down = -1;
	while (++down > -1)
	{
		if ((!lst->prev && t_stack_last(lst)->data > lst->data \
			&& ((n <= lst->data && n >= lmtst.min) || (n >= lst->data \
			&& n >= t_stack_last(lst)->data && n <= lmtst.max))) \
			|| (lst->prev && lst->data < lst->prev->data && ((n >= lst->data \
			&& n <= lmtst.max && n >= lst->prev->data) || (n <= lst->data \
			&& n <= lst->prev->data && n >= lmtst.min))) || (lst->prev \
			&& lst->next && lst->data > lst->next->data && n <= lst->data \
			&& n >= lst->prev->data) || (!lst->prev \
			&& lst->data >= t_stack_last(lst)->data && n <= lst->data \
			&& n >= t_stack_last(lst)->data) || (!lst->next \
			&& lst->data <= t_stack_head(lst)->data && n <= lst->data \
			&& n >= lst->prev->data) || (!lst->next \
			&& lst->data > t_stack_head(lst)->data && n <= lst->data \
			&& n >= lst->prev->data) || (lst->next && lst->prev \
			&& lst->data <= lst->next->data && n <= lst->data && n >= \
			lst->prev->data))
			break ;
		lst = lst->next;
	}
	return (down);
}

/*!
 * @brief 
	Find the right insertion position of 'n' in 'lst'; 
 * @details
	The right insertion position is when 'n' is greater than the previous
	element and less than the following one, since 'lst' is a list of integers 
	in ascending order;

	If the index is on a "conjunction", i.e the position where PREV is greater 
	than NEXT 'n' must be, depending on the case, less/equal to MAX or 
	greater/equal to MIN;

	The check goes both ways, so from HEAD to LAST and will then return a 
	positive integer, and from LAST to HEAD and will return a negative integer.
 * @param lst 
	The address of a pointer to the first node of an ascending sorted list of 
	integers, where the conjunction need not necessarily be between HEAD and 
	LAST.
 * @param n 
	An integer that must be greater than/equal to MIN and less than/equal to 
	MAX.
 * @param lmtst 
	A structure that contains two integers corresponding to the smallest element 
	and the biggest element.
 * @return 
	An integer representing the insertion index.
 */
int	insert_index(t_stack *lst, int n, t_limits lmtst)
{
	int	down;
	int	up;

	down = index_down(lst, n, lmtst);
	lst = t_stack_last(lst);
	up = 0;
	while (++up < down)
	{
		if ((!lst->next && lst->data > t_stack_head(lst)->data \
			&& n <= lst->data && n >= lst->prev->data) || (lst->prev \
			&& lst->data < lst->prev->data && ((n >= lst->data \
			&& n <= lmtst.max && n >= lst->prev->data) || (n <= lst->data \
			&& n <= lst->prev->data && n >= lmtst.min))) || (lst->prev \
			&& lst->next && lst->data > lst->next->data && n <= lst->data \
			&& n >= lst->prev->data) || (!lst->next \
			&& lst->data <= t_stack_head(lst)->data && n <= lst->data \
			&& n >= lst->prev->data) || (lst->next && lst->prev \
			&& lst->data <= lst->next->data && n <= lst->data \
			&& n >= lst->prev->data))
			break ;
		lst = lst->prev;
	}
	if (up < down)
		return (up * -1);
	return (down);
}

static int	get_actions(t_path path, int *actions)
{
	if (!path.dst && !path.src)
		*actions = 1;
	else if (path.dst >= 0 && path.src >= 0)
	{
		if (path.dst >= path.src)
			*actions = path.dst + 1;
		else
			*actions = path.src + 1;
	}
	else if (path.dst <= 0 && path.src <= 0)
	{
		if (path.dst <= path.src)
			*actions = (path.dst * -1) + 1;
		else
			*actions = (path.src * -1) + 1;
	}
	else
	{
		if (path.dst < 0)
			path.dst *= -1;
		if (path.src < 0)
			path.src *= -1;
		*actions = path.src + path.dst + 1;
	}
	return (*actions);
}

static void	set_t_path(t_path *dest, t_path src, bool to_null, bool no_actions)
{
	if (to_null)
	{
		if (!no_actions)
			dest->actions = 0;
		dest->dst = 0;
		dest->src = 0;
	}
	else
	{
		dest->actions = src.actions;
		dest->dst = src.dst;
		dest->src = src.src;
	}
}

/*!
 * @brief 
	Looks for the element that can be transferred with the least number of 
	actions from stack 'b' to stack 'a' and returns the coordinates of the right 
	element in stack 'b', the insertion position in stack 'a' and number of 
	actions	needed to perform this transfer.
 * @param a 
	The address of a pointer to the first node of stack_a.
 * @param b 
	The address of a pointer to the first node of stack_b.
 * @param lmtst 
	A structure that contains two integers corresponding to the smallest element 
	and the biggest element.
 * @return 
	A structure where 'src' is an integer representing the index of the number 
	in stack 'b' to transfer, 'dst' is an integer corresponding to the index of 
	the	correct insert position in stack 'a' and 'actions' is the number of 
	actions needed to perform this transfer.
 */
t_path	find_best_path(t_stack *a, t_stack *b, t_limits lmtst)
{
	t_stack	*stack_b_copy;
	t_path	path;
	t_path	best_path;

	stack_b_copy = t_stack_last(b);
	set_t_path(&path, path, true, false);
	set_t_path(&best_path, best_path, true, false);
	while ((!path.actions || path.src < path.actions) && b)
	{
		path.dst = insert_index(a, b->data, lmtst);
		if (get_actions(path, &path.actions) < best_path.actions \
			|| !best_path.actions)
			set_t_path(&best_path, path, false, false);
		b = b->next;
		path.src++;
	}
	set_t_path(&path, path, true, true);
	while (--path.src * -1 < path.actions && stack_b_copy)
	{
		path.dst = insert_index(a, stack_b_copy->data, lmtst);
		if (get_actions(path, &path.actions) < best_path.actions)
			set_t_path(&best_path, path, false, false);
		stack_b_copy = stack_b_copy->prev;
	}
	return (best_path);
}
