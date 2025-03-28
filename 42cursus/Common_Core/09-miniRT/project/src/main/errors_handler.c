/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:09:31 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/04 13:02:37 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	errors_handler(char *msg, t_mlx *mlx, t_scene **scene)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	if (scene)
		t_scene_free(scene);
	if (mlx)
		window_destroy(mlx);
	exit(1);
}
