# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/05/16 13:13:19 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME 		:= philo_bonus
INCS 		:= ./include
SRC_DIR 	:= src
SRCS 		:=	\
				main.c						\
				philos.c 				\
				\
				utils/ft_calloc.c			\
				utils/ft_error_handler.c	\
				utils/ft_get_timestamp.c 	\
				utils/ft_itoa.c				\
				utils/ft_strappend.c		\
				utils/ft_strlen.c
SRCS 		:= $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR 	:= .build
OBJS 		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS 		:= $(OBJS:.o=.d)
CC 			:= gcc
CFLAGS 		:= -g -pthread -Wall -Wextra -Werror 
CPPFLAGS 	:= $(addprefix -I,$(INCS)) -MMD -MP
RM 			:= rm -rf
MAKEFLAGS 	:= --no-print-directory
DIR_DUP 	= mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: header $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(NAME)${NO_COLOR}}

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${RED}$@${NO_COLOR}}

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR} 🧹 🧹 🧹}

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

header:
	${info ${RED}}
	${info █████████████████████████████████████████████████████████████████ }
	${info █▄─▄▄─█─█─█▄─▄█▄─▄███─▄▄─█─▄▄▄▄█─▄▄─█▄─▄▄─█─█─█▄─▄▄─█▄─▄▄▀█─▄▄▄▄█ }
	${info ██─▄▄▄█─▄─██─███─██▀█─██─█▄▄▄▄─█─██─██─▄▄▄█─▄─██─▄█▀██─▄─▄█▄▄▄▄─█ }
	${info ▀▄▄▄▀▀▀▄▀▄▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▀▄▄▄▀▀▀▄▀▄▀▄▄▄▄▄▀▄▄▀▄▄▀▄▄▄▄▄▀ }
	${info ${NO_COLOR}}
