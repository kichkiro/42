/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:48:48 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/13 16:02:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mlx_new_pixel_put(struct s_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static struct s_draw_var	draw_var_init(struct s_draw coords)
{
	struct s_draw_var	var;

	var.abs_x = abs(coords.end_x - coords.start_x);
	var.abs_y = abs(coords.end_y - coords.start_y);
	if (coords.start_x < coords.end_x)
		var.sign_x = 1;
	else
		var.sign_x = -1;
	if (coords.start_y < coords.end_y)
		var.sign_y = 1;
	else
		var.sign_y = -1;
	if (var.abs_x > var.abs_y)
		var.err = var.abs_x / 2;
	else
		var.err = -var.abs_y / 2;
	return (var);
}

static void	draw_line(struct s_draw data)
{
	struct s_draw_var	var;

	var = draw_var_init(data);
	while (true)
	{
		if (data.start_y + data.shift_y > 0 && data.start_y + data.shift_y < \
			WIN_HEIGHT && data.start_x + data.shift_x > 0 && data.start_x + \
			data.shift_x < WIN_WIDTH)
			mlx_new_pixel_put(data.img, data.start_x + data.shift_x, \
				data.start_y + data.shift_y, data.map->col);
		if (data.start_x == data.end_x && data.start_y == data.end_y)
			break ;
		var.e2 = var.err;
		if (var.e2 > -var.abs_x)
		{
			var.err -= var.abs_y;
			data.start_x += var.sign_x;
		}
		if (var.e2 < var.abs_y)
		{
			var.err += var.abs_x;
			data.start_y += var.sign_y;
		}
	}
}

static void	set_coords(struct s_draw data, t_map **next_line, double i)
{
	data.start_x = (data.map->prev->x * data.size_x + i * data.rot_x) * \
		data.zoom - data.zoom * data.rot_x;
	data.start_y = (data.map->prev->y * data.size_x + i * data.rot_y - \
		data.map->prev->z * data.depth) * data.zoom - data.zoom * \
		data.rot_y;
	if (data.map->x)
	{
		data.end_x = (data.map->x * data.size_x + i * data.rot_x) * \
			data.zoom;
		data.end_y = (data.map->y * data.size_x + i * data.rot_y - \
			data.map->z * data.depth) * data.zoom;
		draw_line(data);
	}
	if ((*next_line)->next)
	{
		(*next_line) = (*next_line)->next;
		data.end_x = ((*next_line)->x * data.size_x + i * data.rot_x + \
			data.size_x * data.rot_x) * data.zoom - data.zoom * data.rot_x;
		data.end_y = ((*next_line)->y * data.size_x + i * data.rot_y + \
			data.size_x * data.rot_y - (*next_line)->z * data.depth) * \
			data.zoom - data.zoom * data.rot_y;
		draw_line(data);
	}
}

void	draw(struct s_draw data)
{
	t_map	*next_line;
	double	i;

	next_line = t_map_move_to_index(t_map_copy_lst(data.map), data.size_x);
	i = 0;
	while (data.map->next && data.start_y <= WIN_HEIGHT * 3)
	{
		data.map = data.map->next;
		set_coords(data, &next_line, i);
		i++;
	}
	t_map_free(&next_line);
	mlx_put_image_to_window(data.mlx, data.win, data.img->img, 0, 0);
}
