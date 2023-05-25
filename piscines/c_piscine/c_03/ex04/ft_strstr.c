/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:40:01 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/25 11:41:11 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (to_find[i2] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + i2] == to_find[i2] && str[i + i2] != '\0')
			i2++;
		if (to_find[i2] == '\0')
			return (str + i);
		i++;
		i2 = 0;
	}
	return (0);
}
