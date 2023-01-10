/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:50:00 by kichkiro          #+#    #+#             */
/*   Updated: 2022/12/26 19:04:35 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
* @brief 
	Read and returns a line from a single or multiple file descriptor.
* @param fd 
	The file descriptor to read from.
* @return 
	Read line: correct behavior.
	NULL if there is nothing else to read, or an error occurred
 */
char	*ft_get_next_line(int fd)
{
	char	buf;
	char	*line;
	int		r;

	line = 0;
	r = read(fd, &buf, 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || r <= 0)
		return (0);
	while (r > 0 && buf != '\n')
	{
		line = ft_char_append(line, buf, 0);
		r = read(fd, &buf, 1);
	}
	if (buf == '\n')
		line = ft_char_append(line, buf, 0);
	return (line);
}
