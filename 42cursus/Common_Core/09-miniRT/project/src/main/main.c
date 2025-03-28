/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:59:30 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/12 21:09:25 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_mlx	*mlx;

	scene = NULL;
	validator(argc, argv);
	parser(argv[1], &scene);
	window_init(&mlx);
	render(&mlx, scene);
	visualizator(mlx, &scene);
	terminator(&scene, mlx);
	return (0);
}
