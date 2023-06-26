# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/06/26 15:40:40 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME		:= fdf
SRCS        := \
				main.c \
				draw.c \
				hooks.c \
				clean.c \
				\
				lst/t_map_new.c \
				lst/t_map_add_back.c \
				lst/t_map_set_to_head.c \
				lst/t_map_get_size.c \
				lst/t_map_get_map.c \
				lst/t_map_move_to_index.c \
				lst/t_map_copy_lst.c \
				lst/t_map_free.c
SRC_DIR     := src
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
LIB  		:= ./lib/libft.a ./lib/libmlx.a
INCS        := ./include ./lib
CC          := gcc
CFLAGS      := -g -Wall -Wextra -Werror
MLXFLAGS    := -lXext -lX11 -lm -lbsd
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: all clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: banner $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(MLXFLAGS)
	${info }
	${info ${BOLD}Creating  -> ${YELLOW}$(NAME)${NO_COLOR}}

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${YELLOW}$@${NO_COLOR}}

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}    🧹 🧹 🧹}

fclean: clean
	$(RM) $(NAME) $(NAME_CLIENT)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: all

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

banner:
	${info ${BLUE}}
	${info _______/\\\\\_        _________/\\\__        ________/\\\\\________}
	${info ______/\\\///__        ________\/\\\__        ______/\\\///________}
	${info ______/\\\______        ________\/\\\__        _____/\\\___________}
	${info ____/\\\\\\\\\___        ________\/\\\__        __/\\\\\\\\\_______}
	${info ____\////\\\//____        ___/\\\\\\\\\__        _\////\\\//_______}
	${info ________\/\\\______        __/\\\////\\\__        ____\/\\\________}
	${info _________\/\\\______        _\/\\\__\/\\\__        ____\/\\\_______}
	${info __________\/\\\______        _\//\\\\\\\/\\_        ____\/\\\______}
	${info ___________\///_______        __\///////\//__        ____\///______}
	${info ${NO_COLOR}}

# ------------------------------------------------------------------------------
