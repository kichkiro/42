/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:33:13 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/24 18:33:34 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	log_key_hook2(int keycode)
{
	if (keycode == XK_e)
		printf("e pressed\n");
	else if (keycode == XK_t)
		printf("t pressed\n");
	else if (keycode == XK_f)
		printf("f pressed\n");
	else if (keycode == XK_g)
		printf("g pressed\n");
	else if (keycode == XK_h)
		printf("h pressed\n");
}

void	log_key_hook(int keycode)
{
	if (keycode == XK_Shift_L)
		printf("shift pressed\n");
	else if (keycode == XK_Control_L)
		printf("control pressed\n");
	else if (keycode == XK_Up)
		printf("up arrow pressed\n");
	else if (keycode == XK_Right)
		printf("right arrow pressed\n");
	else if (keycode == XK_Down)
		printf("down arrow pressed\n");
	else if (keycode == XK_Left)
		printf("left arrow pressed\n");
	else if (keycode == XK_w)
		printf("w pressed\n");
	else if (keycode == XK_s)
		printf("s pressed\n");
	else if (keycode == XK_a)
		printf("a pressed\n");
	else if (keycode == XK_d)
		printf("d pressed\n");
	else if (keycode == XK_q)
		printf("q pressed\n");
	else
		log_key_hook2(keycode);
}

void	log_mouse_hook(int key, int x, int y)
{
	if (key == 1)
		printf("left button pressed: %d %d\n", x, y);
	else if (key == 2)
		printf("right button pressed: %d %d\n", x, y);
	else if (key == 4)
		printf("scroll up\n");
	else if (key == 5)
		printf("scroll down\n");
}
