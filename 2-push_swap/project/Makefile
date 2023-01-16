# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/01/16 12:56:51 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := push_swap
LIB        	:= ft 
LIB_TARGET 	:= ../../0-libft/libft/libft.a 
INCS        := ./include ../../0-libft/libft/include
SRC_DIR     := src
SRCS        := \
	push_swap.c \
	push_swap_actions.c \
	push_swap_algorithm_short.c \
	push_swap_algorithm_long.c \
	push_swap_find_best_path.c \
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
CHECKER		:= src/push_swap_checker.c
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIB_TARGET)))
LDLIB      	:= $(addprefix -l,$(LIB))
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: header $(NAME) 

$(NAME): $(OBJS) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIB) -o $(NAME)
	${info ${BOLD}Creating  -> ${BLUE}$(NAME)${NO_COLOR}}

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${YELLOW}$@${NO_COLOR}}

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

bonus: header $(LIB_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CHECKER) src/push_swap_actions.c \
		$(LIB_TARGET) -o checker
	${info ${BOLD}Creating  -> ${BLUE}checker${NO_COLOR}}

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

header: 
	${info ${RED}}
	${info ________              ______       ________                         }
	${info ___  __ \___  ___________  /_      __  ___/__      _______ ________ }
	${info __  /_/ /  / / /_  ___/_  __ \     _____ \__ | /| / /  __ `/__  __ \}
	${info _  ____// /_/ /_ __   _  / / /     ____/ /__ |/ |/ // /_/ /__  /_/ /}
	${info /_/     \__,_/ /____/ /_/ /_/      /____/ ____/|__/ \__,_/ _  .___/ }
	${info                                                            /_/      }
	${info ${NO_COLOR}}

# ------------------------------------------------------------------------------
