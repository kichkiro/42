/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:40:10 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/28 14:57:16 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	window_init(t_mlx **mlx)
{
	*mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	if (!*mlx)
		errors_handler("visualizator: calloc()", *mlx, NULL);
	(*mlx)->mlx_ptr = mlx_init();
	if (!(*mlx)->mlx_ptr)
		errors_handler("visualizator: mlx()", *mlx, NULL);
	(*mlx)->win_ptr = mlx_new_window((*mlx)->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"MiniRT");
	if (!(*mlx)->win_ptr)
		errors_handler("visualizator: mlx()", *mlx, NULL);
	(*mlx)->img.img_ptr = mlx_new_image((*mlx)->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!((*mlx)->img.img_ptr))
		errors_handler("visualizator: mlx()", *mlx, NULL);
	(*mlx)->img.addr = mlx_get_data_addr((*mlx)->img.img_ptr,
			&(*mlx)->img.bits_per_pixel, &(*mlx)->img.line_length,
			&(*mlx)->img.endian);
}

void	my_pixel_put(t_img100 img, int x, int y, int color)
{
	char	*pixel;

	pixel = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	mlx_exit(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
}

void	window_destroy(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
}

int	visualizator(t_mlx *mlx, t_scene **scene)
{
	t_mlx_scene	*mlx_scene;

	mlx_scene = malloc(sizeof(t_mlx_scene));
	mlx_scene->mlx = mlx;
	mlx_scene->scene = *scene;
	mlx_do_key_autorepeaton(mlx->mlx_ptr);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, mlx_exit, mlx);
	mlx_hook(mlx->win_ptr, 2, 1l << 0, &key_hook, mlx_scene);
	mlx_loop(mlx->mlx_ptr);
	free(mlx_scene);
	return (1);
}
// mlx_mouse_hook(mlx->win_ptr, &mouse_hooks, scene);
