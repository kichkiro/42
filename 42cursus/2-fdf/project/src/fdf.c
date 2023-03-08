/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:52 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/14 11:06:56 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	struct_init(struct s_draw *data, t_map *map, struct s_data *img)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, \
		"FDF - kichkiro");
	data->img = img;
	data->start_x = 0;
	data->start_y = 0;
	data->end_x = 0;
	data->end_y = 0;
	data->shift_x = 350;
	data->shift_y = 350;
	data->size_y = t_map_get_size_y(map);
	data->size_x = t_map_get_size_x(map);
	data->zoom = FACTOR_SCALE / (data->size_x * data->size_y);
	data->depth = 0;
	data->rot_x = 1;
	data->rot_y = 0;
	data->map = map;
}

int	main(int argc, char **argv)
{
	struct s_draw	data;
	struct s_data	img;
	t_map			*map;

	if (argc != 2)
		ft_exit("Wrong number of args...", RED, 1, 0);
	map = t_map_get_map(argv[1]);
	struct_init(&data, map, &img);
	img.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	draw(data);
	mlx_hook(data.win, DESTROY_NOTIFY, 0, destroy_window, &data);
	mlx_hook(data.win, KEY_PRESS, 1, hooks_key_press, &data);
	mlx_loop(data.mlx);
	return (0);
}
