/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:43:10 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/23 12:41:10 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

// time : O(1)
// space: O(1)
t_2d_line	**free_line_arr(t_2d_line **line_arr, size_t length)
{
	size_t	i;

	i = 0;
	while (i <= length)
	{
		free_line(line_arr[i]);
		i += 1;
	}
	free(line_arr);
}

// time : O(n)
// space: O(n)
t_2d_line	**msortl_post_n_loop(t_2d_line **line_arr,
	t_2d_line **dst_arr, size_t i, size_t stop)
{
	while (i <= stop)
	{
		dst_arr[i] = copy_line(line_arr[i]);
		if (dst_arr[i] == NULL)
		{
			free_line_arr(dst_arr, i - 1);
			dst_arr = NULL;
			i = stop;
		}
		i += 1;
	}
	return (dst_arr);
}

// time : O(1)
// space: O(1)
t_2d_line	**msortl_mid_n_loop(t_2d_line **line_arr,
	t_2d_line **dst_arr, size_t *i, size_t j)
{
	dst_arr[*i] = copy_line(line_arr[j]);
	if (dst_arr[*i] == NULL)
	{
		free_line_arr(dst_arr, *i - 1);
		return (NULL);
	}
	*i += 1;
	return (dst_arr);
}

// time : O(n)
// space: O(1)
t_2d_line	**msortl_n_loop(t_2d_line **line_arr, t_2d_line **dst_line,
	size_t start, size_t stop)
{
	size_t		i;
	size_t		j;
	size_t		mid;

	mid = (stop + start) / 2;
	i = 0;
	j = 0;
	while (i <= mid - start && j <= stop - mid - 1)
	{
		if (line_arr[i + start]->left->x > line_arr[j]->left->x)
			if (msortl_mid_n_loop(line_arr, dst_line,
					&i, i + start) == NULL)
				return (line_arr);
		else
			if (msortl_mid_n_loop(line_arr, dst_line,
					&j, j + mid + 1) == NULL)
				return (line_arr);
	}
	if (msortl_post_n_loop(line_arr, dst_line + start, i, mid - start) == NULL)
		return (line_arr);
	if (msortl_post_n_loop(line_arr, dst_line + mid, j, stop - mid - 1) == NULL)
		return (line_arr);
	replace_2d_points(dst_line, line_arr + start, stop - start);
	return (line_arr);
}

// time : O(n log(n))
// space: O(n)
t_2d_line	**msortl_x(t_2d_line **line_arr, size_t start, size_t stop)
{
	size_t		mid;
	t_2d_line	**dst_line;
	size_t		i;
	size_t		j;

	if (stop - start <= 1)
	{
		if (line_arr[start]->left->x > line_arr[stop]->left->x)
		{
			swap_point(line_arr[start]->left, line_arr[stop]->left, 1);
			swap_point(line_arr[start]->right, line_arr[stop]->right, 0);
		}
		return (NULL);
	}
	mid = (stop + start) / 2;
	msortl_x(line_arr, start, mid);
	msortl_x(line_arr, mid + 1, stop);
	dst_line = (t_2d_line **)malloc(sizeof(t_2d_line *) * (stop - start));
	if (dst_line == NULL)
		return (line_arr);
	msortl_n_loop(line_arr, dst_line, start, stop);
	free_line_arr(dst_line, stop - start);
	return (line_arr);
}
