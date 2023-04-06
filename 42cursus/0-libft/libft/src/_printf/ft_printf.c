/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:54:58 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 22:34:06 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_flags_get_value_ext(char *raw, int *i, char ph)
{
	char	*tmp;
	int		n;

	tmp = 0;
	n = 0;
	if (ph == '-')
		(*i)++;
	while (raw[*i] >= '0' && raw[*i] <= '9')
	{
		tmp = ft_char_append(tmp, raw[*i], 42);
		(*i)++;
	}
	(*i)--;
	if (tmp)
		n = ft_atoi(tmp);
	if (!n)
		n = -1;
	ft_free((void **)&tmp);
	return (n);
}

static int	ft_flags_get_value(char *raw, int *i, char ph, char can_repeat)
{
	int		j;

	j = 0;
	if (can_repeat)
	{
		while (raw[*i] == ph)
		{
			(*i)++;
			j++;
		}
		if (ph == '-')
			(*i)--;
	}
	else if (ph && !can_repeat)
		(*i)++;
	if ((ph == '-' && (raw[*i + 1] < '0' || raw[*i + 1] > '9')) \
		|| ((ph == '.' || ph == ' ' || ph == '0') \
		&& (raw[*i] < '0' || raw[*i] > '9')))
		return (-1);
	else if (ph == ' ')
		return (j);
	else
		return (ft_flags_get_value_ext(raw, i, ph));
}

static t_flags	ft_flags_set_value(t_flags flags, char *raw)
{
	int	i;

	i = 0;
	while (raw[i])
	{
		if (raw[i] == '+')
			flags.plus = 1;
		else if (raw[i] == '#')
			flags.sharp = 1;
		else if (raw[i] == ' ')
			flags.space = ft_flags_get_value(raw, &i, ' ', 1);
		else if (raw[i] == '.')
			flags.dot = ft_flags_get_value(raw, &i, '.', 0);
		else if (raw[i] == '0')
			flags.zero = ft_flags_get_value(raw, &i, '0', 0);
		else if (raw[i] == '-')
			flags.dash = ft_flags_get_value(raw, &i, '-', 1);
		else if (raw[i] >= '1' && raw[i] <= '9')
			flags.width = ft_flags_get_value(raw, &i, 0, 0);
		if (raw[i])
			i++;
	}
	return (flags);
}

static t_flags	ft_flags_init(char *s, int *i)
{
	char	*raw;
	t_flags	flags;

	raw = 0;
	flags.dash = 0;
	flags.plus = 0;
	flags.dot = 0;
	flags.sharp = 0;
	flags.space = 0;
	flags.width = 0;
	flags.zero = 0;
	while (s[*i] != 'c' && s[*i] != 's' && s[*i] != 'p' && s[*i] != 'd' && \
		s[*i] != 'i' && s[*i] != 'u' && s[*i] != 'x' && s[*i] != 'X' && \
		s[*i] != '%')
		raw = ft_char_append(raw, s[(*i)++], 42);
	if (raw)
	{
		flags = ft_flags_set_value(flags, raw);
		ft_free((void **)&raw);
	}
	return (flags);
}

/*!
 * @brief 
	Function that mimics the original printf().
 * @details 
	The logic of my own ft_printf() is divided into the following three steps:
	  - In the first step I write character after character as long as different 
		from "%", otherwise I save in an array of char everything between "%" 
		and the placeholder (c, s, d, i, u, p, x, X ) and initialize the flag 
		structure with the correct value;
	  - In the second step I initialize a list of chars with the original value;
	  - In the last step I "assemble" the list of chars with the relative flags, 
	  	in this phase only two operations are carried out, adding and removing 
		nodes, once all the flags have been processed, it prints the final 
		result.
 * @param s 
	The raw string.
 * @return 
	An integer that corresponds to the number of printed characters.
 */
int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	args;
	t_flags	flags;

	len = 0;
	i = -1;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && ++i)
		{
			flags = ft_flags_init((char *)s, &i);
			len += ft_printf_format(args, s[i], flags);
		}
		else
			len += write(1, &(s[i]), 1);
	}
	va_end(args);
	return (len);
}
