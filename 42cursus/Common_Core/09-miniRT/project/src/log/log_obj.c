/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:13:53 by anvannin          #+#    #+#             */
/*   Updated: 2023/10/24 18:33:34 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	log_sphere(t_sphere *sp)
{
	printf("---------------------------SPHERE---------------------------\n");
	printf("x: %f\ty: %f\tz: %f\n", sp->origin->x, sp->origin->y,
		sp->origin->z);
	printf("diameter:%f\tcolor: ", sp->diameter);
	print_rgb_hex(sp->rgb);
	printf("------------------------------------------------------------\n");
}

void	log_cylinder(t_cylinder *cy)
{
	printf("--------------------------CYLINDER--------------------------\n");
	printf("x: %f\ty: %f\tz: %f\n", cy->origin->x, cy->origin->y,
		cy->origin->z);
	printf("diameter:%f height:%f\t", cy->diameter, cy->height);
	printf("color: ");
	print_rgb_hex(cy->rgb);
	printf("direction: [%f, %f, %f]\n", cy->direction->x, cy->direction->y,
		cy->direction->z);
	printf("------------------------------------------------------------\n");
}

void	log_camera(t_camera *cam)
{
	printf("---------------------------CAMERA---------------------------\n");
	printf("x: %f\ty: %f\tz: %f\n", cam->origin->x, cam->origin->y,
		cam->origin->z);
	printf("fov: %f\n", cam->fov);
	printf("direction: [%f, %f, %f]\n", cam->direction->x, cam->direction->y,
		cam->direction->z);
	printf("------------------------------------------------------------\n");
}
