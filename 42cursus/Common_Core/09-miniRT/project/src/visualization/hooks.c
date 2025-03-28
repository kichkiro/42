/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:47 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/28 16:10:44 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// left/right arrows: move object left/right
// up/down arrows: move object farther/closer
// shift/ctrl: move object up/down
static int	object_hooks(t_mlx_scene *mlx_scene, int keycode)
{
	if (keycode == XK_Shift_R || keycode == XK_Control_R || keycode == XK_Up
		|| keycode == XK_Right || keycode == XK_Down || keycode == XK_Left)
		traslate(mlx_scene, keycode);
	else if (keycode == XK_period || keycode == XK_MY_SEMICOLON
		|| keycode == XK_comma || keycode == XK_slash)
		scale(mlx_scene, keycode);
	else if (keycode == XK_i || keycode == XK_k || keycode == XK_j
		|| keycode == XK_l)
		rotate(mlx_scene, keycode);
	else
		return (0);
	return (1);
}

// w/s: move camera forward/backward
// a/d: move camera left/right
// q/e: move camera up/down
// numpad 2/4/6/8: rotate camera
static int	camera_hooks(t_mlx_scene *mlx_scene, int keycode)
{
	if (keycode == XK_w || keycode == XK_s || keycode == XK_a || keycode == XK_d
		|| keycode == XK_q || keycode == XK_e)
		traslate_camera(mlx_scene, keycode);
	else if (keycode == XK_t || keycode == XK_f || keycode == XK_g
		|| keycode == XK_h)
		rotate_camera(mlx_scene, keycode);
	else
		return (0);
	return (1);
}

// esc: close window
// r: reset scene
int	key_hook(int keycode, t_mlx_scene *mlx_scene)
{
	if (keycode == XK_Escape)
		return (mlx_exit(mlx_scene->mlx));
	else if (keycode == XK_r)
		printf("R pressed\n");
	else if (object_hooks(mlx_scene, keycode))
		return (1);
	else if (camera_hooks(mlx_scene, keycode))
		return (1);
	else
		return (0);
	return (1);
}

// left click: select object to move
// right click: deselect object
// scroll up/down: zoom in/out
int	mouse_hooks(int key, int x, int y, t_mlx *mlx)
{
	if (key == 1 || key == 2 || key == 4 || key == 5)
		log_mouse_hook(key, x, y);
	else
		return (0);
	return (1);
	mlx_exit(mlx);
}
