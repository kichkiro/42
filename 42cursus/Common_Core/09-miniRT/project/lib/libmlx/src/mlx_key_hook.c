/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/03 11:49:06 by CharlieRoot       #+#    #+#             */
/*   Updated: 2023/01/30 14:09:14 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

/*!
 * @brief
	Hook into key events.
 * @param win
	The window instance.
 * @param funct
	The handler function, will be called as follows:
		(*f)(int key_code, void *param);
 * @param param 
	The parameter to give on each event.
 * @return 
	Has no return value (bc).
 */
int	mlx_key_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[KeyRelease].hook = funct;
	win->hooks[KeyRelease].param = param;
	win->hooks[KeyRelease].mask = KeyReleaseMask;
}
