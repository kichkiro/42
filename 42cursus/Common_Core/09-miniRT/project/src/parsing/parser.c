/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:18:44 by kichkiro          #+#    #+#             */
/*   Updated: 2023/11/02 18:13:17 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*!
 * @brief
	Checks whether the scene contains a camera, light, and ambient lightning.
 * @param scene
	Pointer to the linked list that contains the objects in the scene.
 */
static void	final_check(t_scene *scene)
{
	t_scene_get_camera(scene);
	t_scene_get_light(scene);
	t_scene_get_ambient_light(scene);
}

/*!
 * @brief
	Checks the first two characters of the line and returns the type of the
	object.
 * @param line
	The line of the .rt file to be parsed.
 * @return
	The type of the scene object.
 */
static char	get_type(char *line)
{
	if (!ft_strncmp(line, "sp", 2))
		return (SPHERE);
	else if (!ft_strncmp(line, "pl", 2))
		return (PLANE);
	else if (!ft_strncmp(line, "cy", 2))
		return (CYLINDER);
	else if (!ft_strncmp(line, "A", 1))
		return (AMBIENT_LIGHTNING);
	else if (!ft_strncmp(line, "C", 1))
		return (CAMERA);
	else if (!ft_strncmp(line, "L", 1) || !ft_strncmp(line, "l", 1))
		return (LIGHT);
	else
		errors_handler("parser: invalid identifier", NULL, NULL);
	return (0);
}

/*!
 * @brief
	Checks whether the first character starts with lowercase or uppercase
	letter.
	If it is unique, check that there are no other objects of the same type
	in the list of objects in the scene.
	If it is not unique, it checks that there is no other object of the same
	type labeled as unique.
 * @param line
	The line of the .rt file to be parsed.
 * @param scene
	Pointer to the linked list that contains the objects in the scene.
 * @param type
	The type of the scene object.
 * @return
	true if obj is unique, false otherwise.
 */
static bool	get_unique(char *line, t_scene *scene, char type)
{
	bool	unique;

	if (*line > 64 && *line < 91)
		unique = true;
	else if (*line > 96 && *line < 123)
		unique = false;
	else
		errors_handler("parser: the first character of the type must be a "\
			"letter", NULL, &scene);
	if (!t_scene_check_unique(scene, type, unique))
		errors_handler("parser: there can be a single object of the same type "\
			"if its type starts with a capital letter ", NULL, &scene);
	return (unique);
}

/*!
 * @brief
	Checks the type of the object and calls the corresponding function to
	parse the object.
 * @param line
	The line of the .rt file to be parsed.
 * @param type
	The type of the scene object.
 * @param scene
	Pointer to the linked list that contains the objects in the scene.
 * @return
	Pointer to the object.
 */
static void	*get_data(char *line, char type, t_scene *scene)
{
	while (*line != 32 && *line != 9)
		line++;
	if (type == AMBIENT_LIGHTNING)
		return (parse_ambient_lightning(line, scene));
	else if (type == LIGHT)
		return (parse_light(line, scene));
	else if (type == CAMERA)
		return (parse_camera(line, scene));
	else if (type == SPHERE)
		return (parse_sphere(line, scene));
	else if (type == PLANE)
		return (parse_plane(line, scene));
	else if (type == CYLINDER)
		return (parse_cylinder(line, scene));
	return (NULL);
}

/*!
 * @brief
	Parses the .rt file and creates a linked list of objects in the scene.
 * @param filename
	The name of the .rt file to be parsed.
 * @param scene
	Pointer to the linked list that contains the objects in the scene.
 */
void	parser(char *filename, t_scene **scene)
{
	char	*line;
	int		id;
	char	type;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		errors_handler("parser: open()", NULL, NULL);
	id = 0;
	while (true)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		else if (*line == 10 && !ft_free((void **)&line))
			continue ;
		type = get_type(line);
		t_scene_add_back(scene, t_scene_new(id, type, get_unique(line, *scene, \
			type), get_data(line, type, *scene)));
		ft_free((void **)&line);
		id++;
	}
	close(fd);
	final_check(*scene);
}
