/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:05:03 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/12 21:32:38 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (!ft_strncmp(filename + (i - 3), ".rt", 3))
		return (true);
	return (false);
}

void	validator(int argc, char **argv)
{
	if (argc != 2)
		errors_handler("usage: ./minirt <path_scene>.rt", NULL, NULL);
	else if (!check_filename(argv[1]))
		errors_handler("invalid filename: it must end with .rt", NULL, NULL);
}
