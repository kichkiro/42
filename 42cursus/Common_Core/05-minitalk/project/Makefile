# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:51:06 by kichkiro          #+#    #+#              #
#    Updated: 2023/02/15 10:32:13 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME		:= minitalk
NAME_SERVER	:= server
NAME_CLIENT	:= client
SRCS_SERVER := minitalk_server.c
SRCS_CLIENT := minitalk_client.c
SRC_DIR     := src
SRCS_SERVER := $(SRCS_SERVER:%=$(SRC_DIR)/%)
SRCS_CLIENT := $(SRCS_CLIENT:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS_SERVER := $(SRCS_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_CLIENT := $(SRCS_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_SERVER := $(OBJS_SERVER:.o=.d)
DEPS_CLIENT := $(OBJS_CLIENT:.o=.d)
LIB         := ft
LIB_TARGET  := ./lib/libft/libft.a 
INCS        := ./includes ./lib/libft/include
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIB_TARGET)))
LDLIBS      := $(addprefix -l,$(LIB))
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: all clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: header $(NAME)

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_SERVER) $(LDLIBS) -o $(NAME_SERVER)
	${info ${BOLD}Creating  -> ${BLUE}$(NAME_SERVER)${NO_COLOR}}

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_CLIENT) $(LDLIBS) -o $(NAME_CLIENT)
	${info ${BOLD}Creating  -> ${BLUE}$(NAME_CLIENT)${NO_COLOR}}

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

-include $(DEPS_SERVER)
-include $(DEPS_CLIENT)

clean:
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}	🧹 🧹 🧹}

fclean: clean
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	
re:
	$(MAKE) fclean
	$(MAKE) all

# Bonus ----------------------------------------------------------------------->

SRCS_SERVER_BONUS 	:= minitalk_server_bonus.c
SRCS_CLIENT_BONUS 	:= minitalk_client_bonus.c
SRCS_SERVER_BONUS 	:= $(SRCS_SERVER_BONUS:%=$(SRC_DIR)/%)
SRCS_CLIENT_BONUS 	:= $(SRCS_CLIENT_BONUS:%=$(SRC_DIR)/%)
OBJS_SERVER_BONUS 	:= $(SRCS_SERVER_BONUS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_CLIENT_BONUS 	:= $(SRCS_CLIENT_BONUS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS_SERVER_BONUS 	:= $(OBJS_SERVER_BONUS:.o=.d)
DEPS_CLIENT_BONUS 	:= $(OBJS_CLIENT_BONUS:.o=.d)

-include $(DEPS_SERVER_BONUS)
-include $(DEPS_CLIENT_BONUS)

bonus: header $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $(OBJS_SERVER_BONUS) $(LDLIBS) -o $(NAME_SERVER)
	${info ${BOLD}Creating  -> ${BLUE}$(NAME_SERVER)${NO_COLOR}}
	$(CC) $(LDFLAGS) $(OBJS_CLIENT_BONUS) $(LDLIBS) -o $(NAME_CLIENT)
	${info ${BOLD}Creating  -> ${BLUE}$(NAME_CLIENT)${NO_COLOR}}

# Style ----------------------------------------------------------------------->

RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

header:
	${info ${NO_COLOR}}	
	${info ███    ███ ██ ███    ██ ██ ████████  █████  ██      ██   ██ }
	${info ████  ████ ██ ████   ██ ██    ██    ██   ██ ██      ██  ██  }
	${info ██ ████ ██ ██ ██ ██  ██ ██    ██    ███████ ██      █████   }
	${info ██  ██  ██ ██ ██  ██ ██ ██    ██    ██   ██ ██      ██  ██  }
	${info ██      ██ ██ ██   ████ ██    ██    ██   ██ ███████ ██   ██ }
	${info ${NO_COLOR}}
	
# ------------------------------------------------------------------------------
