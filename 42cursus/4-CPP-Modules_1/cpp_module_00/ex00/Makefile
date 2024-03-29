# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 17:59:55 by kichkiro          #+#    #+#              #
#    Updated: 2023/07/17 12:11:44 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := megaphone
SRCS        := megaphone.cpp
BUILD_DIR   := .build
OBJS        := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := c++
CFLAGS      := -Wall -Wextra -Werror -std=c++98
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

$(BUILD_DIR)/%.o: %.cpp
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
