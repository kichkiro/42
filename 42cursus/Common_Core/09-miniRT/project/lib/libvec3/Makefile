# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 19:07:36 by anvannin          #+#    #+#              #
#    Updated: 2023/10/12 21:44:45 by anvannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := libvec3.a
SRCS        := \
				vec3_basic.c \
				vec3_basic2.c \
				vec3_adv.c \
				vec3_rot.c \
				vec3_trig.c \
				vec3_pointer.c \
				vec3_normalize.c
SRC_DIR     := src
BUILD_DIR   := .build
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := gcc
CPPFLAGS    := -MMD -MP -I include
AR          := ar
ARFLAGS     := -r -c -s
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(eval CURRENT_COUNT := $(shell echo $$(($(CURRENT_COUNT) + 1))))
	@$(eval TOTAL_COUNT := $(shell echo $(words $(SRCS))))
	@$(eval PERCENT := $(shell echo $$((($(CURRENT_COUNT) * 100) / \
	$(TOTAL_COUNT)))))
	@printf "\r\033[K[${BOLD}%d%%${NO_COLOR}] ${BOLD}${CYAN}LibVec3${NO_COLOR} \
	${BOLD}-> Compiling -> ${CYAN}$(@:$(BUILD_DIR)/%=%)${NO_COLOR}" $(PERCENT)
	@if [ $(PERCENT) -eq 100 ]; then \
		printf "\r\033[K[${BOLD}%d%%${NO_COLOR}] ${BOLD}${CYAN}LibVec3\
	 -> ./$(NAME)${NO_COLOR}\n" $(PERCENT);\
	fi

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
	$(eval CURRENT_COUNT := 0)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Style ----------------------------------------------------------------------->

CYAN		:= ${shell tput setaf 6}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

# ------------------------------------------------------------------------------
