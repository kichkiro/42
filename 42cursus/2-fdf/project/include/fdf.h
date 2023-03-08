/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:24:02 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/14 11:07:32 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Libraries ------------------------------------------------------------------>

# include "../lib/libft/include/libft.h"
# include "../lib/libmlx/include/mlx.h"

# include <fcntl.h>
# include <math.h>

// Constants ------------------------------------------------------------------>
# define FACTOR_SCALE       420.0
# define WIN_HEIGHT         1000
# define WIN_WIDTH          1900

enum e_x11_events
{
	KEY_PRESS = 2,
	KEY_RELEASE,
	BUTTON_PRESS,
	BUTTON_RELEASE,
	MOTION_NOTIFY,
	ENTER_NOTIFY,
	LEAVE_NOTIFY,
	FOCUS_IN,
	FOCUS_OUT,
	KEYMAP_NOTIFY,
	EXPOSE,
	GRAPHICS_EXPOSE,
	NOEXPOSE,
	VISIBILITY_NOTIFY,
	CREATE_NOTIFY,
	DESTROY_NOTIFY,
	UNMAP_NOTIFY,
	MAP_NOTIFY,
	MAP_REQUEST,
	REPARENT_NOTIFY,
	CONFIGURE_NOTIFY,
	CONFIGURE_REQUEST,
	GRAVITY_NOTIFY,
	RESIZE_REQUEST,
	CIRCULATE_NOTIFY,
	CIRCULATE_REQUEST,
	PROPERTY_NOTIFY,
	SELECTION_CLEAR,
	SELECTION_REQUEST,
	SELECTION_NOTIFY,
	COLORMAP_NOTIFY,
	CLIENT_MESSAGE,
	MAPPING_NOTIFY,
	GENERIC_EVENT,
	LAST_EVENT,
};

enum e_key
{
	KEY_ESC		= 65307,
	KEY_ENTER	= 65293,
	KEY_SPACE	= 32,
	KEY_RIGHT	= 65363,
	KEY_LEFT	= 65361,
	KEY_UP		= 65362,
	KEY_DOWN	= 65364,
	KEY_Q		= 113,
	KEY_E		= 101,
	KEY_W		= 119,
	KEY_A		= 97,
	KEY_S		= 115,
	KEY_D		= 100,
	KEY_Z		= 122,
	KEY_X		= 120,
};

// Structures ----------------------------------------------------------------->

struct		s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct		s_draw_var
{
	int		abs_x;
	int		abs_y;
	int		sign_x;
	int		sign_y;
	int		err;
	int		e2;
};

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	int				col;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

struct				s_draw
{
	void			*mlx;
	void			*win;
	struct s_data	*img;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				size_x;
	int				size_y;
	int				shift_x;
	int				shift_y;
	double			zoom;
	double			depth;
	double			rot_x;
	double			rot_y;
	t_map			*map;
};

// Main Functions ------------------------------------------------------------->

void	draw(struct s_draw data);
int		destroy_window(struct s_draw *data);
int		hooks_key_press(int key, struct s_draw *data);

// Linked Lists --------------------------------------------------------------->

t_map	*t_map_new(int x, int y, int z, int col);
void	t_map_add_back(t_map **lst, t_map *new_node);
void	t_map_set_to_head(t_map **lst);
int		t_map_get_size_x(t_map *map);
int		t_map_get_size_y(t_map *map);
t_map	*t_map_move_to_index(t_map *map, size_t index);
t_map	*t_map_get_map(char *file);
t_map	*t_map_copy_lst(t_map *original);
void	t_map_free(t_map **lst);

#endif
