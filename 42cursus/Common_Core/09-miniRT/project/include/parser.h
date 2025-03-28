/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:45:57 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/19 19:57:22 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// Libraries ------------------------------------------------------------------>

# include "minirt.h"
# include <fcntl.h>

// Defines -------------------------------------------------------------------->

# define AMBIENT_LIGHTNING	1
# define CAMERA				2
# define LIGHT				3
# define SPHERE				4
# define PLANE				5
# define CYLINDER			6

// Structures ----------------------------------------------------------------->

typedef struct s_scene	t_scene;

typedef struct s_rgb
{
	double			red;
	double			green;
	double			blue;
}	t_rgb;

typedef struct s_ambient_lightning
{
	double			ratio;
	t_rgb			*rgb;
}	t_ambient_lightning;

typedef struct s_camera
{
	t_v3			*origin;
	t_v3			*direction;
	double			fov;

	t_v3			u;
	t_v3			v;
	t_v3			w;
	double			d;
}	t_camera;

typedef struct s_light
{
	t_v3			*origin;
	double			brightness;
	t_rgb			*rgb;
}	t_light;

typedef struct s_sphere
{
	t_v3			*origin;
	double			diameter;
	t_rgb			*rgb;
}	t_sphere;

typedef struct s_plane
{
	t_v3			*origin;
	t_v3			*direction;
	t_rgb			*rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_v3			*origin;
	t_v3			*direction;
	double			diameter;
	double			height;
	t_rgb			*rgb;
}	t_cylinder;

// Linked Lists --------------------------------------------------------------->

typedef struct s_scene
{
	int				id;
	unsigned char	type;
	bool			unique;
	bool			selected;
	void			*data;
	struct s_scene	*prev;
	struct s_scene	*next;
}	t_scene;

t_scene				*t_scene_new(int id, char type, bool unique, void *data);
void				t_scene_add_back(t_scene **lst, t_scene *new);
void				t_scene_set_to_head(t_scene **scene);
void				t_scene_free(t_scene **scene);
bool				t_scene_check_unique(t_scene *scene, char type, bool uniq);
t_camera			*t_scene_get_camera(t_scene *scene);
t_light				*t_scene_get_light(t_scene *scene);
t_ambient_lightning	*t_scene_get_ambient_light(t_scene *scene);

// Functions ------------------------------------------------------------------>

void				parser(char *filename, t_scene **scene);
t_v3				*get_coords(char **line, t_scene *scene);
t_rgb				*get_rgb(char **line, t_scene *scene);
double				get_value(char **line, t_scene *scene);
void				*parse_ambient_lightning(char *line, t_scene *scene);
void				*parse_camera(char *line, t_scene *scene);
void				*parse_light(char *line, t_scene *scene);
void				*parse_sphere(char *line, t_scene *scene);
void				*parse_plane(char *line, t_scene *scene);
void				*parse_cylinder(char *line, t_scene *scene);

#endif
