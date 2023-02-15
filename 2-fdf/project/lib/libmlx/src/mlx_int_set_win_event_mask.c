/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_set_win_event_mask.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/03 11:49:06 by CharlieRoot       #+#    #+#             */
/*   Updated: 2023/01/19 11:20:48 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx_int.h"

int	mlx_int_set_win_event_mask(t_xvar *xvar)
{
	t_win_list				*win;
	int						mask;
	int						i;
	XSetWindowAttributes	xwa;

	win = xvar->win_list;
	while (win)
	{
		xwa.event_mask = 0;
		i = MLX_MAX_EVENT;
		while (i--)
			xwa.event_mask |= win->hooks[i].mask;
		XChangeWindowAttributes(xvar->display, win->window, CWEventMask, &xwa);
		win = win->next;
	}
}
