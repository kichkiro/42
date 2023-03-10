/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print_split_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:06:42 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 17:10:40 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	For each item in str, add node whit str item (char) as content. 
 * @param str 
	String to split.
 * @return 
	New malloc() allocated linked list.
 */
t_print	*t_print_split_str(char *str, bool need_to_free)
{
	t_print	*lst;
	int		i;

	i = 0;
	lst = t_print_new_char_node(str[i]);
	while (str[i++ + 1])
		t_print_add_back(&lst, t_print_new_char_node(str[i]));
	if (need_to_free)
		ft_free((void **)&str);
	return (lst);
}
