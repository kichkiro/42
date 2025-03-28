/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:15:10 by kichkiro          #+#    #+#             */
/*   Updated: 2023/05/13 15:01:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define  LIBFT_H

// Libraries ------------------------------------------------------------------>

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>

// Constants ------------------------------------------------------------------>

# define RESET		"\x1b[0m"
# define WHITE		"\033[1m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE_B	"\033[1;1m"
# define RED_B		"\033[1;31m"
# define GREEN_B	"\x1b[1;32m"
# define YELLOW_B	"\x1b[1;33m"
# define BLUE_B		"\x1b[1;34m"
# define MAGENTA_B	"\x1b[1;35m"
# define CYAN_B		"\033[1;36m"

# define MAX_INT	2147483647
# define MIN_INT	-2147483648

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
void	ft_exit(char *msg, char *color, int fd, int exit_code);
char	*ft_char_append(char *s, char c, bool need_to_free);
char	*ft_strappend(char *s1, char *s2, bool free_s1, bool free_s2);
char	*ft_strrev(char *str);
ssize_t	ft_stridx(char *s, int c);
char	*ft_split_substr(char **s, int start, size_t len, char split);
size_t	ft_hexlen(size_t n);
char	*ft_utoa(unsigned int nb);
char	*ft_utoa_hex(unsigned int n, bool is_upper);
char	*ft_ultoa_hex(uintptr_t n);

/*!
 * @brief 
	Structure containing the Longest Incremental/Decremental Subsequence and its 
	length.
 */
typedef struct s_ls
{
	long	*ls;
	int		len;
}	t_ls;

t_ls	*ft_lis(int *arr, int size, bool need_to_free);
t_ls	*ft_lds(int *arr, int size, bool need_to_free);
bool	ft_n_is_in_arr(int *arr, int size, int n);
void	ft_strmatrixfree(char ***matrix);
char	**ft_strmatrixjoin(char **mtx, char *s, bool free_mtx, bool free_s);
size_t	ft_strmatrixlen(char **matrix);

// Get-Next-Line -------------------------------------------------------------->

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

char	*ft_get_next_line(int fd);

// Printf --------------------------------------------------------------------->

/*!
 * @brief 
	Simple unidirectional linked list where the data of each node is a single 
	char.
 */
typedef struct char_node
{
	char				data;
	struct char_node	*next;
}	t_print;

t_print	*t_print_new(char data);
t_print	*t_print_split_str(char *str, bool need_to_free);
void	t_print_add_back(t_print **lst, t_print *new);
void	t_print_add_front(t_print **lst, t_print *new);
void	t_print_add_inside(t_print **head, size_t start, size_t len, char data);
void	t_print_del_last(t_print **head, size_t n);
t_print	*t_print_last(t_print *lst);
int		t_print_size(t_print *lst);

typedef struct flags
{
	int	width;
	int	dash;
	int	dot;
	int	zero;
	int	sharp;
	int	plus;
	int	space;
}	t_flags;

int		ft_printf(const char *s, ...);
int		ft_printf_format(va_list args, char ph, t_flags flags);
void	ft_printf_assembly_line(t_print **result, t_flags flags, char ph);

#endif
