# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/04/06 23:13:22 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := push_swap
LIB        	:= ft 
LIB_TARGET 	:= lib/libft/libft.a
INCS        := \
	./include \
	lib/libft/include
SRC_DIR     := src
SRCS        := \
	push_swap.c \
	perform_actions.c \
	algorithm_short.c \
	algorithm_long.c \
	find_best_path.c \
	\
	lst/t_stack_add_back.c \
	lst/t_stack_check_dup.c \
	lst/t_stack_del_last.c \
	lst/t_stack_free.c \
	lst/t_stack_from_arr.c \
	lst/t_stack_head.c \
	lst/t_stack_is_sorted.c \
	lst/t_stack_last.c \
	lst/t_stack_max.c \
	lst/t_stack_min.c \
	lst/t_stack_second_min.c \
	lst/t_stack_n_is_inside.c \
	lst/t_stack_new.c \
	lst/t_stack_set_to_head.c \
	lst/t_stack_size.c \
	lst/t_stack_to_arr.c \
	lst/t_stack_index_data.c
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
CHECKER		:= \
	lib/libft/src/_get_next_line/ft_get_next_line.c \
	src/push_swap_checker.c \
	src/push_swap_actions.c \
	src/lst/t_stack_is_sorted.c \
	src/lst/t_stack_add_back.c \
	src/lst/t_stack_set_to_head.c \
	src/lst/t_stack_new.c \
	src/lst/t_stack_check_dup.c \
	src/lst/t_stack_n_is_inside.c \
	src/lst/t_stack_free.c
	
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := clang
CFLAGS      := -g -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIB_TARGET)))
LDLIB      	:= $(addprefix -l,$(LIB))
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: banner $(NAME) 

$(NAME): $(OBJS) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME)
	${info }
	${info ${BOLD}Creating  -> ${BLUE}$(NAME)${NO_COLOR}}

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

-include $(DEPS)

clean:
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(BUILD_DIR)
	$(RM) checker.d
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}	🧹 🧹 🧹}

fclean: clean
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)
	$(RM) checker 
	
re:
	$(MAKE) fclean
	$(MAKE) all

bonus: banner $(LIB_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CHECKER) $(LIB_TARGET) -o checker
	${info ${BOLD}Creating  -> ${BLUE}checker${NO_COLOR}}

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

banner:
	${info ${RED}}
	${info ________             __ _ _ _______                    }
	${info ___/ __ \__  _______/ /_ _ _ / ___/      ______ _____  }
	${info __/ /_/ / / / / ___/ __ \_ _ \__ \ | /| / / __ `/ __ \ }
	${info _/ ____/ /_/ (__  ) / / /_ _ _ / / |/ |/ / /_/ / /_/ / }
	${info /_/    \__,_/____/_/ /_/_ _/____/|__/|__/\__,_/ .___/  }
	${info _                                            /_/       }
	${info ${NO_COLOR}}

# ------------------------------------------------------------------------------
