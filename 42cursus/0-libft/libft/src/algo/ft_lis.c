/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:50:53 by kichkiro          #+#    #+#             */
/*   Updated: 2023/01/10 16:56:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search_replace(long *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

static t_ls	*get_lis(int *arr, int size, long *tmp, int *index)
{
	t_ls	*lis;
	int		tmp_len;
	int		i;

	lis = malloc(sizeof(t_ls));
	lis->len = -1;
	i = 0;
	while (++i < size)
		tmp[i] = ((long)MAX_INT) + 1;
	i = 0;
	while (++i < size)
	{
		index[i] = search_replace(tmp, 0, i, arr[i]);
		if (lis->len < index[i])
			lis->len = index[i];
	}
	lis->ls = (long *)malloc((lis->len + 1) * sizeof(long));
	i = size;
	tmp_len = lis->len;
	while (--i >= 0)
	{
		if (index[i] == tmp_len)
			lis->ls[tmp_len--] = arr[i];
	}
	return (lis);
}

/*!
 * @brief 
	The Longest Increasing Subsequence (LIS) problem is to find the length of 
	the longest subsequence of a given sequence such that all elements of the 
	subsequence are sorted in increasing order; For example, the length of LIS 
	for {10, 22, 9, 33, 21, 50, 41, 60} is 5 and LIS is {10, 22, 33, 50, 60}.
 * @param arr 
	Array to search for the LIS.
 * @param size 
	Lenght of arr.
 * @return 
	LIS and its length.
 */
t_ls	*ft_lis(int *arr, int size, bool need_to_free)
{
	long	*tmp;
	int		*index;
	t_ls	*lis;

	tmp = (long *)malloc(size * sizeof(long));
	tmp[0] = arr[0];
	index = (int *)malloc(size * sizeof(int));
	index[0] = 0;
	lis = get_lis(arr, size, tmp, index);
	lis->len += 1;
	free(tmp);
	free(index);
	if (need_to_free)
		free(arr);
	return (lis);
}
