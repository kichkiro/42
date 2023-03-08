/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:50:00 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/21 16:36:54 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
* @brief 
	Returns one line at a time from a text file.
* @param fd 
	The file descriptor to read from.
* @return 
	Read line: correct behavior.
	NULL if there is nothing else to read, or an error occurred.
 */
char	*ft_get_next_line(int fd)
{
	static char	*lines;
	char		*buf;
	int			r;

	r = 0;
	buf = 0;
	if (!lines)
		lines = ft_calloc(1, sizeof(char));
	while (ft_stridx(lines, '\n') == -1)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		r = read(fd, buf, BUFFER_SIZE);
		if (r > 0 || *buf)
			lines = ft_strappend(lines, buf, true, false);
		else
		{
			ft_free((void **)&buf);
			buf = ft_split_substr(&lines, 0, ft_stridx(lines, 0), -1);
			if (fd < 0 || BUFFER_SIZE <= 0 || (r <= 0 && !*buf))
				return (ft_free((void **)&buf));
			return (buf);
		}
		ft_free((void **)&buf);
	}
	return (ft_split_substr(&lines, 0, ft_stridx(lines, '\n') + 1, 1));
}
