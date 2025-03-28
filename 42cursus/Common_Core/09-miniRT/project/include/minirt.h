/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:00:19 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/23 19:21:01 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// Libraries ------------------------------------------------------------------>

# include "../lib/libft/include/libft.h"
# include "../lib/libmlx/include/mlx.h"
# include "../lib/libvec3/include/vec3.h"
# include "parser.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

// Defines -------------------------------------------------------------------->

// Window -------------------------------------------------------------------->>

# define WIN_WIDTH 		1920
# define WIN_HEIGHT 	1000

// Colors -------------------------------------------------------------------->>

# define HEX_WHITE 		0x00FFFFFF
# define HEX_BLACK 		0x00000000
# define HEX_RED 		0x00FF0000
# define HEX_GREEN 		0x0000FF00
# define HEX_BLUE 		0x000000FF
# define HEX_YELLOW 	0x00FFFF00
# define HEX_MAGENTA 	0x00FF00FF
# define HEX_CYAN 		0x0000FFFF

// Transform ----------------------------------------------------------------->>

# define TRASTLATION_RATIO 1
# define SCALE_RATIO 1
# define ROTATION_RATIO 0.5
# define ROTATION_CAMERA_RATIO 0.1

// Other Defines ------------------------------------------------------------->>

# define XK_MY_SEMICOLON 59

// Structures ----------------------------------------------------------------->

typedef struct s_rgb		t_rgb;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;
typedef struct s_scene		t_scene;
typedef struct s_camera		t_camera;

typedef struct s_img100
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img100;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img100	img;
}	t_mlx;

typedef struct s_mlx_scene
{
	t_mlx		*mlx;
	t_scene		*scene;
}	t_mlx_scene;

// Functions ------------------------------------------------------------------>

// main ---------------------------------------------------------------------->>

// void	initializer(t_mlx **mlx);
void	validator(int argc, char **argv);
void	errors_handler(char *msg, t_mlx *mlx, t_scene **scene);
void	terminator(t_scene **scene, t_mlx *mlx);

// visualizator -------------------------------------------------------------->>

int		visualizator(t_mlx *mlx, t_scene **scene);
void	window_init(t_mlx **mlx);
void	my_pixel_put(t_img100 img, int x, int y, int color);
int		mlx_exit(t_mlx *mlx);
void	window_destroy(t_mlx *mlx);
void	window_labels(t_mlx *mlx);
int		key_hook(int keycode, t_mlx_scene *mlx_scene);
int		mouse_hooks(int key, int x, int y, t_mlx *mlx);

// transform ----------------------------------------------------------------->>

void	traslate(t_mlx_scene *mlx_scene, int keycode);
void	traslate_camera(t_mlx_scene *mlx_scene, int keycode);
void	scale(t_mlx_scene *mlx_scene, int keycode);
void	rotate(t_mlx_scene *mlx_scene, int keycode);
void	rotate_camera(t_mlx_scene *mlx_scene, int keycode);

// log ---------------------------------------------------------------------->>

void	log_sphere(t_sphere *sph);
void	log_cylinder(t_cylinder *cy);
void	log_camera(t_camera *cam);
void	log_key_hook(int keycode);
void	log_mouse_hook(int key, int x, int y);

#endif
