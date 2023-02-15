/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/03 11:49:06 by CharlieRoot       #+#    #+#             */
/*   Updated: 2023/01/30 14:08:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_mouse_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[ButtonPress].hook = funct;
	win->hooks[ButtonPress].param = param;
	win->hooks[ButtonPress].mask = ButtonPressMask;
}
