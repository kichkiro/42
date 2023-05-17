# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:44:14 by kichkiro          #+#    #+#              #
#    Updated: 2023/05/13 14:59:54 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME        := libft.a
SRCS        := \
	_get_next_line/ft_get_next_line.c \
	\
	_printf/ft_printf_assembly_line.c \
	_printf/ft_printf_format.c \
	_printf/ft_printf.c \
	\
	algo/ft_lds.c \
	algo/ft_lis.c \
	\
	fd/ft_putchar_fd.c \
	fd/ft_putendl_fd.c \
	fd/ft_putnbr_fd.c \
	fd/ft_putstr_fd.c \
	fd/ft_exit.c \
	\
	hex/ft_hexlen.c \
	hex/ft_ultoa_hex.c \
	hex/ft_utoa_hex.c \
	\
	is/ft_isalnum.c \
	is/ft_isalpha.c \
	is/ft_isascii.c \
	is/ft_isdigit.c \
	is/ft_isprint.c \
	\
	_printf/lst/t_print_add_back.c \
	_printf/lst/t_print_add_front.c \
	_printf/lst/t_print_add_inside.c \
	_printf/lst/t_print_del_last.c \
	_printf/lst/t_print_last.c \
	_printf/lst/t_print_new.c \
	_printf/lst/t_print_size.c \
	_printf/lst/t_print_split_str.c \
	\
	mem/ft_calloc.c \
	mem/ft_free.c \
	mem/ft_bzero.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	\
	str/ft_atoi.c \
	str/ft_char_append.c \
	str/ft_itoa.c \
	str/ft_n_is_in_arr.c \
	str/ft_split_substr.c \
	str/ft_split.c \
	str/ft_strappend.c \
	str/ft_strchr.c \
	str/ft_strdup.c \
	str/ft_stridx.c \
	str/ft_striteri.c \
	str/ft_strjoin.c \
	str/ft_strlcat.c \
	str/ft_strlcpy.c \
	str/ft_strlen.c \
	str/ft_strmapi.c \
	str/ft_strmatrixfree.c \
	str/ft_strmatrixjoin.c \
	str/ft_strmatrixlen.c \
	str/ft_strncmp.c \
	str/ft_strnstr.c \
	str/ft_strrchr.c \
	str/ft_strrev.c \
	str/ft_strtrim.c \
	str/ft_substr.c \
	str/ft_tolower.c \
	str/ft_toupper.c \
	str/ft_utoa.c
SRC_DIR     := src
BUILD_DIR   := .build
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
CC          := clang
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -MMD -MP -I include
AR          := ar
ARFLAGS     := -r -c -s
RM          := rm -rf
MAKEFLAGS   := --no-print-directory
DIR_DUP     = mkdir -p $(@D)

.PHONY: clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

all: header $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info ${BOLD}Creating  -> ${YELLOW}$(NAME)${NO_COLOR})

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info ${BOLD}Compiling -> ${YELLOW}$@${NO_COLOR})

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
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
	${info }
	${info ${BOLD}${YELLOW}LIBFT${NO_COLOR}}

# ------------------------------------------------------------------------------
