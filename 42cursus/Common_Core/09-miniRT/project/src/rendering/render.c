/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:40:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/12 21:35:26 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*!
 * @brief
	This function renders a white center cross on the screen. It draws a cross
	shape at the center of the window for reference or visualization purposes.
 * @param mlx
	A pointer to mlx structure.
 */
static void	render_center_cross(t_mlx *mlx)
{
	int	i;

	i = -1;
	my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2, HEX_WHITE);
	while (++i < 5)
	{
		my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2 + i, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2, WIN_HEIGHT / 2 - i, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2 + i, WIN_HEIGHT / 2, HEX_WHITE);
		my_pixel_put(mlx->img, WIN_WIDTH / 2 - i, WIN_HEIGHT / 2, HEX_WHITE);
	}
}

/*!
 * @brief
 	This function renders the scene using ray tracing and displays the result on
	the screen.
 * @param mlx
 	Pointer to the MLX structure for graphics handling.
 * @param scene
 	Pointer to the scene to be rendered.
 */
void	render(t_mlx **mlx, t_scene *scene)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_pixel_put((*mlx)->img, x, y, raycaster(scene,
					t_scene_get_camera(scene), x, y));
	}
	render_center_cross(*mlx);
	mlx_put_image_to_window((*mlx)->mlx_ptr, (*mlx)->win_ptr,
		(*mlx)->img.img_ptr, 0, 0);
	window_labels(*mlx);
}
