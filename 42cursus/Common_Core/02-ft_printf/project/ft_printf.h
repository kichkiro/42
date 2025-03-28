/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:15:26 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:10:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

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
