/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:37:58 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 23:10:17 by kichkiro         ###   ########.fr       */
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

static char	*actions_to_str(int action)
{
	if (action == 1)
		return ("sa");
	else if (action == 2)
		return ("sb");
	else if (action == 3)
		return ("ss");
	else if (action == 4)
		return ("pa");
	else if (action == 5)
		return ("pb");
	else if (action == 6)
		return ("ra");
	else if (action == 7)
		return ("rb");
	else if (action == 8)
		return ("rr");
	else if (action == 9)
		return ("rra");
	else if (action == 10)
		return ("rrb");
	else if (action == 11)
		return ("rrr");
	else
		return (0);
}

static int	actions_to_int(char *action)
{
	if (!ft_strncmp(action, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(action, "sb\n", 3))
		return (2);
	else if (!ft_strncmp(action, "ss\n", 3))
		return (3);
	else if (!ft_strncmp(action, "pa\n", 3))
		return (4);
	else if (!ft_strncmp(action, "pb\n", 3))
		return (5);
	else if (!ft_strncmp(action, "ra\n", 3))
		return (6);
	else if (!ft_strncmp(action, "rb\n", 3))
		return (7);
	else if (!ft_strncmp(action, "rr\n", 3))
		return (8);
	else if (!ft_strncmp(action, "rra\n", 4))
		return (9);
	else if (!ft_strncmp(action, "rrb\n", 4))
		return (10);
	else if (!ft_strncmp(action, "rrr\n", 4))
		return (11);
	else
		return (0);
}

static bool	lists_init(t_stack **actions, t_stack **a, char **argv)
{
	char	*line;
	int		actions_int;

	while (true)
	{
		line = ft_get_next_line(0);
		if (!line && !ft_free((void **)&line))
			break ;
		actions_int = actions_to_int(line);
		free(line);
		if (!actions_int && !t_stack_free(actions) && !t_stack_free(a))
			ft_exit("Error\n", 0, 2, 1);
		t_stack_add_back(actions, t_stack_new(actions_int));
	}
	if (*actions)
		t_stack_set_to_head(actions);
	while (*argv)
		t_stack_add_back(a, t_stack_new(ft_atoi(*argv++)));
	if (t_stack_check_dup(*a) && !t_stack_free(actions) && !t_stack_free(a))
		exit(0);
	if (*a)
		t_stack_set_to_head(a);
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*actions;
	t_stack	*a;
	t_stack	*b;

	actions = 0;
	a = 0;
	b = 0;
	if (argc < 3 || check_limits(argv))
		exit(0);
	lists_init(&actions, &a, ++argv);
	while (actions && actions->next)
	{
		perform_actions(&a, &b, actions_to_str(actions->data), false);
		actions = actions->next;
	}
	if (actions)
		perform_actions(&a, &b, actions_to_str(actions->data), false);
	if (t_stack_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	t_stack_free(&actions);
	t_stack_free(&a);
	t_stack_free(&b);
	return (0);
}
