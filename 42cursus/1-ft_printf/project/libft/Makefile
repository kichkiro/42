# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 10:44:14 by kichkiro          #+#    #+#              #
#    Updated: 2023/01/10 17:01:29 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   	= ../libftprintf.a
CC	   	= clang
CFLAGS 	= -Wall -Wextra -Werror
SRCS   	= ft_isalnum.c ft_isprint.c ft_strncmp.c ft_isalpha.c ft_isascii.c \
			ft_strlen.c ft_isdigit.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
			ft_strlcpy.c ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_toupper.c ft_tolower.c \
			ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			t_print_add_front.c t_print_size.c t_print_last.c t_print_add_back.c \
			t_print_delone.c t_print_clear.c \
			ft_char_append.c ft_free.c ft_strappend.c ft_hexlen.c \
			ft_strrev.c ft_utoa.c ft_utoa_hex.c ft_ultoa_hex.c \
			t_print_split_str.c t_print_add_inside.c t_print_del_last.c \
			t_print_new_char_node.c
OBJS   	= $(SRCS:.c=.o)
AR 		= ar -rcs
RM	   	= rm -f

all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS) 

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
