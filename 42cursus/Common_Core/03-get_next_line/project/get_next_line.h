/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:51:17 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/15 15:14:54 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	*ft_free(void **ptr);
void	*ft_calloc(size_t nmemb, size_t size);
ssize_t	ft_stridx(char *s, int c);
char	*ft_strappend(char *s1, char *s2, bool free_s1, bool free_s2);
char	*ft_split_substr(char **s, int start, size_t len, char split);

#endif
