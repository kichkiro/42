/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:38:50 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/24 20:28:35 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    swap(char *x, char *y)
{
        char    tmp;

        tmp = *x;
        *x = *y;
        *y = tmp;
}

void    permute(char *tab, int start, int end, char *input)
{
	int     i;

	if (start == end)
		// validate_output
	else
	{
		i = 0;
		while (i <= end)
		{
			swap ((tab + start), (tab + i));
			permute (tab, start + 1, end, input);
			swap ((tab + start), (tab + i));
			i++;
		}      
	}
}
