/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:40:34 by kichkiro          #+#    #+#             */
/*   Updated: 2023/02/03 11:45:39 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_result(t_print *lst, char placeholder)
{
	int		len;
	t_print	*tmp;

	len = 0;
	while (lst)
	{
		if (lst->data && placeholder != 'c')
		{
			write(1, &lst->data, 1);
			len++;
		}
		else if (placeholder == 'c')
		{
			write(1, &lst->data, 1);
			len++;
		}
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (len);
}

static int	ft_printf_cs(va_list args, t_flags flags, char placeholder)
{
	t_print	*result;
	char	*arg_str;

	if (placeholder == 'c')
		result = t_print_new(va_arg(args, int));
	else if (placeholder == 's')
	{
		arg_str = va_arg(args, char *);
		if (!arg_str)
		{
			result = t_print_split_str("(null)", 0);
			placeholder = 0;
		}
		else if (!ft_strlen(arg_str))
			result = t_print_new(0);
		else
			result = t_print_split_str(arg_str, 0);
	}		
	ft_printf_assembly_line(&result, flags, placeholder);
	return (ft_print_result(result, placeholder));
}

static int	ft_printf_idu(va_list args, t_flags flags, char placeholder)
{
	t_print			*result;
	int				arg_signed;
	unsigned int	arg_unsigned;

	if (placeholder == 'i')
	{
		arg_signed = va_arg(args, int);
		result = t_print_split_str(ft_itoa(arg_signed), 1);
	}
	else if (placeholder == 'u')
	{
		arg_unsigned = va_arg(args, unsigned int);
		result = t_print_split_str(ft_utoa(arg_unsigned), 1);
	}
	ft_printf_assembly_line(&result, flags, placeholder);
	return (ft_print_result(result, placeholder));
}

static int	ft_printf_xp(va_list args, t_flags flags, char placeholder)
{
	t_print	*result;
	char	is_upper;
	char	*arg;

	if (placeholder == 'p')
	{
		arg = ft_ultoa_hex(va_arg(args, uintptr_t));
		if (*arg == '0')
		{
			result = t_print_split_str("(nil)", 0);
			arg = ft_free((void **)&arg);
		}
		else
			result = t_print_split_str(ft_strappend("0x", arg, 0, 1), 1);
	}
	else
	{
		is_upper = 0;
		if (placeholder == 'X')
			is_upper = 1;
		arg = ft_utoa_hex(va_arg(args, unsigned int), is_upper);
		result = t_print_split_str(arg, 1);
	}
	ft_printf_assembly_line(&result, flags, placeholder);
	return (ft_print_result(result, placeholder));
}

/*!
 * @brief 
	Handles the conversion of format string placeholders.
 * @param args 
	va_list with arguments.
 * @param ph 
	Placeholder character.
 * @param flags 
	Flags for the placeholder.
 * @return 
	Number of characters printed.
 */
int	ft_printf_format(va_list args, char ph, t_flags flags)
{
	if (ph == 'c')
		return (ft_printf_cs(args, flags, 'c'));
	else if (ph == 's')
		return (ft_printf_cs(args, flags, 's'));
	else if (ph == 'p')
		return (ft_printf_xp(args, flags, 'p'));
	else if (ph == 'd' || ph == 'i')
		return (ft_printf_idu(args, flags, 'i'));
	else if (ph == 'u')
		return (ft_printf_idu(args, flags, 'u'));
	else if (ph == 'x')
		return (ft_printf_xp(args, flags, 'x'));
	else if (ph == 'X')
		return (ft_printf_xp(args, flags, 'X'));
	else
	{
		write(1, "%%", 1);
		return (1);
	}
}
