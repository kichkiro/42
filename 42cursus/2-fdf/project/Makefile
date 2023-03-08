# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/02/14 11:46:26 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := fdf
LIBS        := ft mlx
LIBS_TARGET := \
    lib/libft/libft.a \
    lib/libmlx/libmlx.a
INCS        := \
	include \
    lib/libft/include \
	lib/libmlx/include
SRC_DIR     := src
SRCS        := \
	fdf.c \
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

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
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

all: header $(NAME) 

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME) $(MLXFLAGS)
	${info }
	${info ${BOLD}Creating  -> ${BLUE}$(NAME)${NO_COLOR}}

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

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
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

header:
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


# ONLY ARCHIVE ---------------------------------------------------------------->

# # Config ---------------------------------------------------------------------->

# NAME        := fdf
# LIBS        := ft mlx
# LIBS_TARGET := \
#     lib/libft/libft.a \
#     lib/libmlx.a
# INCS        := \
# 	include \
#     lib/libft/include
# SRC_DIR     := src
# SRCS        := \
# 	fdf.c \
# 	draw.c \
# 	hooks.c \
# 	clean.c \
# 	\
# 	lst/t_map_new.c \
# 	lst/t_map_add_back.c \
# 	lst/t_map_set_to_head.c \
# 	lst/t_map_get_size.c \
# 	lst/t_map_get_map.c \
# 	lst/t_map_move_to_index.c \
# 	lst/t_map_copy_lst.c \
# 	lst/t_map_free.c

# SRCS        := $(SRCS:%=$(SRC_DIR)/%)
# BUILD_DIR   := .build
# OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# DEPS        := $(OBJS:.o=.d)
# CC          := clang
# CFLAGS      := -Wall -Wextra -Werror
# MLXFLAGS    := -lXext -lX11 -lm -lbsd
# CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
# LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
# LDLIB      	:= $(addprefix -l,$(LIBS))
# RM          := rm -rf
# MAKEFLAGS   := --no-print-directory
# DIR_DUP     = mkdir -p $(@D)

# .PHONY: clean fclean re
# .SILENT:

# # Rules ----------------------------------------------------------------------->

# all: header $(NAME) 

# $(NAME): $(OBJS) $(LIBS_TARGET)
# 	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME) $(MLXFLAGS)
# 	${info }
# 	${info ${BOLD}Creating  -> ${BLUE}$(NAME)${NO_COLOR}}

# $(LIBS_TARGET):
# 	$(MAKE) -C $(@D)

# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(DIR_DUP)
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
# 	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

# -include $(DEPS)

# clean:
# 	$(RM) $(BUILD_DIR)
# 	$(RM) $(NAME)
# 	for f in $(LIBS_TARGET); do if [ -d $$f ]; then $(MAKE) -C $$f $@; fi done
# 	${info }
# 	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}    🧹 🧹 🧹}

# fclean: clean
# 	$(RM) $(NAME)
# 	$(RM) $(LIBS_TARGET)

# re:
# 	$(MAKE) fclean
# 	$(MAKE) all

# # Style ----------------------------------------------------------------------->

# RED 		:= ${shell tput setaf 1}
# YELLOW		:= ${shell tput setaf 3}
# BLUE		:= ${shell tput setaf 4}
# NO_COLOR	:= ${shell tput sgr0}
# BOLD		:= ${shell tput bold}

# header:
# 	${info ${BLUE}}
# 	${info _______/\\\\\_        _________/\\\__        ________/\\\\\________}
# 	${info ______/\\\///__        ________\/\\\__        ______/\\\///________}
# 	${info ______/\\\______        ________\/\\\__        _____/\\\___________}
# 	${info ____/\\\\\\\\\___        ________\/\\\__        __/\\\\\\\\\_______}
# 	${info ____\////\\\//____        ___/\\\\\\\\\__        _\////\\\//_______}
# 	${info ________\/\\\______        __/\\\////\\\__        ____\/\\\________}
# 	${info _________\/\\\______        _\/\\\__\/\\\__        ____\/\\\_______}
# 	${info __________\/\\\______        _\//\\\\\\\/\\_        ____\/\\\______}
# 	${info ___________\///_______        __\///////\//__        ____\///______}
# 	${info ${NO_COLOR}}

# # ------------------------------------------------------------------------------
