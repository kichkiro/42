# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 18:02:07 by kichkiro          #+#    #+#              #
#    Updated: 2023/01/19 09:29:20 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := libmlx.a
SRCS        := \
	mlx_init.c \
	mlx_new_window.c \
	mlx_pixel_put.c \
	mlx_loop.c \
	mlx_mouse_hook.c \
	mlx_key_hook.c \
	mlx_expose_hook.c \
	mlx_loop_hook.c \
	mlx_int_anti_resize_win.c \
	mlx_int_do_nothing.c \
	mlx_int_wait_first_expose.c \
	mlx_int_get_visual.c \
	mlx_flush_event.c \
	mlx_string_put.c \
	mlx_set_font.c \
	mlx_new_image.c mlx_get_data_addr.c \
	mlx_put_image_to_window.c \
	mlx_get_color_value.c \
	mlx_clear_window.c \
	mlx_xpm.c \
	mlx_int_str_to_wordtab.c \
	mlx_destroy_window.c \
	mlx_int_param_event.c \
	mlx_int_set_win_event_mask.c \
	mlx_hook.c \
	mlx_rgb.c \
	mlx_destroy_image.c \
	mlx_mouse.c \
	mlx_screen_size.c \
	mlx_destroy_display.c \
	mlx_int_deal_shm.c \
	mlx_int_rgb_conversion.c
SRC_DIR     := src
BUILD_DIR   := .build
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := gcc
CPPFLAGS    := -MMD -MP -I include
AR          := ar
ARFLAGS     := -r -c -s
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: header $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	${info ${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}}

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CPPFLAGS) -c $< -o $@
	${info ${BOLD}Compiling -> ${RED}$@${NO_COLOR}}

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

header:
	${info }
	${info ${BOLD}${RED}LIBMLX${NO_COLOR}}

# ------------------------------------------------------------------------------
