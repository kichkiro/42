/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:41:16 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/25 12:19:49 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	item1;
	int	item2;
	int	tmp;

	while (size -1 != 0)
	{
		i = 0;
		while (size -1 != 0)
		{
			item1 = tab[i];
			item2 = tab[i + 1];
			if (item1 > item2)
			{
				tmp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = tmp;
			}
			i++;
			size--;
		}
		size = i;
	}
}
