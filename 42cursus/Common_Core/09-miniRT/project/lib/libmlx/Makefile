# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 18:02:07 by kichkiro          #+#    #+#              #
#    Updated: 2023/09/29 20:44:53 by kichkiro         ###   ########.fr        #
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

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(eval CURRENT_COUNT := $(shell echo $$(($(CURRENT_COUNT) + 1))))
	@$(eval TOTAL_COUNT := $(shell echo $(words $(SRCS))))
	@$(eval PERCENT := $(shell echo $$((($(CURRENT_COUNT) * 100) / \
	$(TOTAL_COUNT)))))
	@printf "\r\033[K[${BOLD}%d%%${NO_COLOR}] ${BOLD}${RED}LibMlx${NO_COLOR} \
	${BOLD}-> Compiling  -> ${RED}$(@:$(BUILD_DIR)/%=%)${NO_COLOR}" $(PERCENT)
	@if [ $(PERCENT) -eq 100 ]; then \
		printf "\r\033[K[${BOLD}%d%%${NO_COLOR}] ${BOLD}${RED}LibMlx\
	  -> ./$(NAME)${NO_COLOR}\n" $(PERCENT);\
	fi

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
	$(eval CURRENT_COUNT := 0)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

# ------------------------------------------------------------------------------
