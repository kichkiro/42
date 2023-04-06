/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:06:59 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 23:05:29 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_limits(char **m)
{
	t_check_limits	c;

	c.i = 0;
	while (m[++c.i])
	{
		c.j = -1;
		c.s_len = 0;
		c.n_len = 0;
		c.n = ft_atoi(m[c.i]);
		c.sign = false;
		while (m[c.i][++c.j])
		{
			if (m[c.i][c.j] == '-')
				c.sign = true;
			if (m[c.i][c.j] != ' ' && m[c.i][c.j] != '-' && m[c.i][c.j] != '+')
				c.s_len++;
		}
		if ((c.sign && c.n > 0) || (!c.sign && c.n < 0))
			return (true);
		while (++c.n_len && c.n)
			c.n /= 10;
		if (c.n_len != ++c.s_len && m[c.i][--c.j] != '0')
			return (true);
	}
	return (false);
}

static t_stack	*stack_init(t_stack **lst, char **argv)
{
	*lst = 0;
	while (*argv)
		t_stack_add_back(&(*lst), t_stack_new(ft_atoi(*argv++)));
	if (t_stack_check_dup(*lst))
	{
		write(2, "Error\n", 6);
		t_stack_free(lst);
		exit(0);
	}
	t_stack_set_to_head(&(*lst));
	return (*lst);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1 && !check_limits(argv))
	{
		a = stack_init(&a, ++argv);
		b = 0;
		if (!t_stack_is_sorted(a))
		{
			if (t_stack_size(a) <= 5)
				algorithm_short(&a, &b);
			else
				algorithm_long(&a, &b);
		}
		t_stack_free(&a);
		t_stack_free(&b);
	}
	else if (argc == 1)
		exit(0);
	else
		write(2, "Error\n", 6);
	return (0);
}
