# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/10/27 19:33:23 by anvannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := miniRT
LIBS        := ft mlx vec3
LIBS_TARGET := \
				lib/libft/libft.a \
				lib/libmlx/libmlx.a \
				lib/libvec3/libvec3.a
INCS        := \
				include \
				lib/libft/include \
				lib/libmlx/include \
				lib/libvec3/include
SRC_DIR     := src
SRCS        := \
				main/main.c \
				main/errors_handler.c \
				main/validator.c \
				main/terminator.c \
				\
				parsing/parser.c \
				parsing/get_value.c \
				parsing/camera.c \
				parsing/geometric_obj.c \
				parsing/lighting_obj.c \
				\
				rendering/render.c \
				rendering/intersections.c \
				rendering/intersec_cylinder.c \
				rendering/raycaster.c \
				rendering/lighting.c \
				rendering/color.c \
				rendering/color2.c \
				\
				visualization/visualizator.c \
				visualization/hooks.c \
				visualization/window_labels.c \
				\
				log/log_obj.c \
				log/log_hooks.c \
				\
				transform/traslate.c \
				transform/rotate.c \
				transform/scale.c \
				\
				_lst/t_scene_add_back.c \
				_lst/t_scene_new.c \
				_lst/t_scene_set_to_head.c \
				_lst/t_scene_free.c \
				_lst/t_scene_check_unique.c \
				_lst/t_scene_get_obj.c
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := gcc
CFLAGS      := -g #-Wall -Wextra -Werror
MLXFLAGS    := -lXext -lX11 -lm -lbsd
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIB      	:= $(addprefix -l,$(LIBS))
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: banner $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME) $(MLXFLAGS)
	${info }
	${info ${BOLD}Created -> ./$(NAME)${NO_COLOR} 🎉}

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(eval CURRENT_COUNT := $(shell echo $$(($(CURRENT_COUNT) + 1))))
	@$(eval TOTAL_COUNT := $(shell echo $(words $(SRCS))))
	@$(eval PERCENT := $(shell echo $$((($(CURRENT_COUNT) * 100) / \
	$(TOTAL_COUNT)))))
	@printf "\r\033[K[${BOLD}%d%%${NO_COLOR}] ${BOLD}${BLUE}miniRT${NO_COLOR}\
	${BOLD}-> Compiling -> ${BLUE}$(@:$(BUILD_DIR)/%=%)${NO_COLOR}" $(PERCENT)
	@if [ $(PERCENT) -eq 100 ]; then \
		printf "\r\033[K[${BOLD}%d%%${NO_COLOR}] ${BOLD}${BLUE}miniRT\
	${NO_COLOR}\n" $(PERCENT);\
	fi

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}	🧹 🧹 🧹}

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
GREEN		:= ${shell tput setaf 2}
BLUE		:= ${shell tput setaf 4}
YELLOW		:= ${shell tput setaf 3}
CYAN		:= ${shell tput setaf 6}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

banner:
	@echo '${BLUE}    ___       ___       ___       ___       ___       ___   '
	@echo '   /\__\     /\  \     /\__\     /\  \     /\  \     /\  \  '
	@echo '  /::L_L_   _\:\  \   /:| _|_   _\:\  \   /::\  \    \:\  \ '
	@echo ' /:/L:\__\ /\/::\__\ /::|/\__\ /\/::\__\ /::\:\__\   /::\__\'
	@echo ' \/_/:/  / \::/\/__/ \/|::/  / \::/\/__/ \;:::/  /  /:/\/__/'
	@echo '   /:/  /   \:\__\     |:/  /   \:\__\    |:\/__/   \/__/   '
	@echo '   \/__/     \/__/     \/__/     \/__/     \|__|            '
	@echo ''
	@echo '            ✨ My first RayTracer with miniLibX ✨'
	@echo '${NO_COLOR}'

# ------------------------------------------------------------------------------
