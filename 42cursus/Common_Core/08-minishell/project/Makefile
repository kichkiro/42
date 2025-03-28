# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 17:59:55 by kichkiro          #+#    #+#              #
#    Updated: 2023/05/18 01:25:14 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME		:= minishell
SRCS		:= \
				main/main.c 				\
				main/init.c 				\
				main/signal_handler.c 		\
				main/prompt.c 				\
				main/history.c 				\
				main/bombfreeall.c		\
				\
				errors/errors_handler.c 	\
				errors/invalid_prompt.c 	\
				errors/syntax_errors.c 		\
				\
				parser/parsing_system.c 	\
				parser/parsing_ext.c 		\
				parser/variable_expand.c 	\
				parser/wildcards.c 			\
				\
				executor/execution_system.c \
				executor/builtins.c 		\
				executor/fd_handler.c		\
				executor/redirections.c 	\
				executor/heredoc.c 			\
				executor/booleans.c 		\
				executor/pipes.c 			\
				\
				variables/env_variables.c 	\
				variables/shell_variables.c \
				variables/export_variables.c \
				\
				_lst/lst_add_back.c 		\
				_lst/lst_free_last.c 		\
				_lst/lst_free.c 			\
				_lst/lst_new.c 				\
				_lst/lst_set_to_head.c 		\
				_lst/lst_set_to_last.c
SRC_DIR     := src
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
LIB_TARGET  := ./lib/libft.a
INCS        := ./include ./lib
CC          := gcc
CFLAGS      := -g -Wall -Wextra -Werror
READLINE    := -lreadline
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDLIBS      := -L./lib -lft
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: all clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: banner $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB_TARGET) $(LDLIBS) $(READLINE) -o $(NAME)
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

RED			:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

banner:
	${info ${RED}}
	${info █████████████████████████████████████████████████████ }
	${info █▄─▀█▀─▄█▄─▄█▄─▀█▄─▄█▄─▄█─▄▄▄▄█─█─█▄─▄▄─█▄─▄███▄─▄███ }
	${info ██─█▄█─███─███─█▄▀─███─██▄▄▄▄─█─▄─██─▄█▀██─██▀██─██▀█ }
	${info ▀▄▄▄▀▄▄▄▀▄▄▄▀▄▄▄▀▀▄▄▀▄▄▄▀▄▄▄▄▄▀▄▀▄▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀ }
	${info ${NO_COLOR}}

# ------------------------------------------------------------------------------




