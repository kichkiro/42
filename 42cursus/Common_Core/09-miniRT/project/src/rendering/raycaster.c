/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:56:40 by kichkiro          #+#    #+#             */
/*   Updated: 2023/11/02 18:14:23 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*!
 * @brief
 	Calculate the ray direction for a given pixel on the screen.
 * @param ray
 	Pointer to the ray structure to store the calculated ray.
 * @param cam
 	Pointer to the camera.
 * @param x
 	X-coordinate of the pixel.
 * @param y
 	Y-coordinate of the pixel.
 */
static void	ray_for_pixel(t_ray *ray, t_camera *cam, size_t x, size_t y)
{
	t_texture_coords	map;

	map.u = (2 * ((x + 0.5) / (double)WIN_WIDTH) - 1)
		* (double)(WIN_WIDTH / (double)WIN_HEIGHT);
	map.v = (1 - 2 * (y + 0.5) / (double)WIN_HEIGHT);
	ray->origin = (*cam->origin);
	ray->direction = v_unit((t_v3){
			map.u * cam->u.x + map.v * cam->v.x - cam->d * cam->w.x,
			map.u * cam->u.y + map.v * cam->v.y - cam->d * cam->w.y,
			map.u * cam->u.z + map.v * cam->v.z - cam->d * cam->w.z
		});
}

/*!
 * @brief
 	Perform raycasting to determine the color of a pixel in the scene.
 * @param scene
 	Pointer to the scene.
 * @param cam
 	Pointer to the camera.
 * @param x
 	X-coordinate of the pixel.
 * @param y
 	Y-coordinate of the pixel.
 * @return
 	The color of the pixel as an integer.
 */
int	raycaster(t_scene *scene, t_camera *cam, int x, int y)
{
	t_ray		ray;
	t_intersec	isec;

	ray_for_pixel(&ray, cam, x, y);
	intersections(scene, ray, &isec, 0.0);
	if (isec.has_intersec)
		lighting(scene, &isec);
	return (rgb_to_int(&isec.color));
}
