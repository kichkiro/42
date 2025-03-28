/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:06:22 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/14 10:45:22 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hook_translate(int key, struct s_draw *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	if (key == KEY_LEFT)
		data->shift_x += 20;
	else if (key == KEY_RIGHT)
		data->shift_x -= 20;
	else if (key == KEY_UP)
		data->shift_y += 20;
	else if (key == KEY_DOWN)
		data->shift_y -= 20;
	data->img->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->line_length, \
		&data->img->endian);
	draw(*data);
	return (0);
}

static int	hook_zoom(int key, struct s_draw *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	if (key == KEY_W)
		data->zoom *= 1.1;
	else if (key == KEY_S && data->zoom / 1.1 > 0)
		data->zoom /= 1.1;
	data->img->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->line_length, \
		&data->img->endian);
	draw(*data);
	return (0);
}

static int	hook_depth(int key, struct s_draw *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	if (key == KEY_A && data->depth < data->size_x + data->size_y)
	{
		if (!data->depth)
			data->depth = 0.1;
		else
			data->depth *= 1.1;
	}
	else if (key == KEY_D && data->depth / 1.1 > 0)
		data->depth /= 1.1;
	data->img->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->line_length, \
		&data->img->endian);
	draw(*data);
	return (0);
}

static int	hook_rotate(int key, struct s_draw *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	if (key == KEY_Q && data->rot_x < 3.0)
		data->rot_x += 0.1;
	else if (key == KEY_E && data->rot_x > -3.0)
		data->rot_x -= 0.1;
	else if (key == KEY_Z && data->rot_y < 3.0)
		data->rot_y += 0.1;
	else if (key == KEY_X && data->rot_y > -3.0)
		data->rot_y -= 0.1;
	data->img->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->line_length, \
		&data->img->endian);
	draw(*data);
	return (0);
}

int	hooks_key_press(int key, struct s_draw *data)
{
	if (key == KEY_ESC)
		destroy_window(data);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP \
		|| key == KEY_DOWN)
		hook_translate(key, data);
	else if (key == KEY_W || key == KEY_S)
		hook_zoom(key, data);
	else if (key == KEY_A || key == KEY_D)
		hook_depth(key, data);
	else if (key == KEY_Q || key == KEY_E || key == KEY_Z || key == KEY_X)
		hook_rotate(key, data);
	return (0);
}
