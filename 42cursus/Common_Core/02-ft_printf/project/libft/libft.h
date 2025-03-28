/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:15:10 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:24:42 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define  LIBFT_H

// Libraries ------------------------------------------------------------------>

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

// Libft Base ----------------------------------------------------------------->

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);

struct s_split
{
	char	set[1];
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
};

char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Custom Functions ----------------------------------------------------------->

void	*ft_free(void **ptr);
char	*ft_char_append(char *s, char c, bool need_to_free);
char	*ft_strappend(char *s1, char *s2, bool free_s1, bool free_s2);
char	*ft_strrev(char *str);
size_t	ft_hexlen(size_t n);
char	*ft_utoa(unsigned int nb);
char	*ft_utoa_hex(unsigned int n, char is_upper);
char	*ft_ultoa_hex(uintptr_t n);

// Linked Lists --------------------------------------------------------------->

typedef struct s_print
{
	char			content;
	struct s_print	*next;
}	t_print;

void	t_print_add_front(t_print **lst, t_print *new);
int		t_print_size(t_print *lst);
t_print	*t_print_last(t_print *lst);
void	t_print_add_back(t_print **lst, t_print *new);
void	t_print_delone(t_print *lst, void (*del)(void*));
void	t_print_clear(t_print **lst, void (*del)(void*));
t_print	*t_print_new_char_node(char content);
t_print	*t_print_split_str(char *str, bool need_to_free);
void	t_print_del_last(t_print **head, size_t n);
void	t_print_add_inside(t_print **head, size_t start, size_t len, char data);

#endif
