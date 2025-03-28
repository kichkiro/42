/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_flush_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/02 18:58:11 by CharlieRoot       #+#    #+#             */
/*   Updated: 2023/01/19 10:59:20 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_flush_event(t_xvar *xvar)
{
	XEvent	ev;

	while (XPending(xvar->display))
		XNextEvent(xvar->display, &ev);
}
