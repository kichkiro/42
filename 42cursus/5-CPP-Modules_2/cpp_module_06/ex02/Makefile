# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 14:53:55 by kichkiro          #+#    #+#              #
#    Updated: 2024/05/02 13:02:14 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := type
SRCS        := main.cpp Base.cpp
SRC_DIR     := src
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
INCS        := ./include
CC          := c++
CFLAGS      := -std=c++98 -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: all clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: banner $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	${info }
	${info ${BOLD}Creating  -> ${WHITE}$(NAME)${NO_COLOR}}

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${WHITE}$@${NO_COLOR}}

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}    🧹 🧹 🧹}

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Style ----------------------------------------------------------------------->

YELLOW		:= ${shell tput setaf 3}
WHITE		:= ${shell tput setaf 7}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

banner:
	${info ${BOLD}${WHITE} }
	${info █████████████████████████████████████████████████████████████████ }
	${info █─▄▄▄─███░█████░█████▄─▀█▀─▄█─▄▄─█▄─▄▄▀█▄─██─▄█▄─▄███▄─▄▄─█─▄▄▄▄█ }
	${info █─███▀█▄▄░▄▄█▄▄░▄▄████─█▄█─██─██─██─██─██─██─███─██▀██─▄█▀█▄▄▄▄─█ }
	${info ▀▄▄▄▄▄▀▀▀▄▀▀▀▀▀▄▀▀▀▀▀▄▄▄▀▄▄▄▀▄▄▄▄▀▄▄▄▄▀▀▀▄▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀ }
	${info ${NO_COLOR} }

# ------------------------------------------------------------------------------
