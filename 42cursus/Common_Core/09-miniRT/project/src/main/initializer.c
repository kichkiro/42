/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:35:49 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/12 21:32:50 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initializer(t_mlx **mlx, t_scene **scene)
{
	*mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	if (!*mlx)
		errors_handler("malloc()", NULL, NULL);
	window_init(*mlx);
	*scene = NULL;
}
