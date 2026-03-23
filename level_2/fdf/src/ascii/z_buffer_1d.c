/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_buffer_1d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:54:23 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/23 15:47:02 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

size_t	get_right_most_x(t_2d_line **line_arr, size_t arr_len)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	while (i < arr_len)
	{
		if (last < line_arr[i]->right->x)
			last = line_arr[i]->right->x;
		i += 1;
	}
	return (last);
}

// time : O(n)
// space: O(n)
void	z_buffer_1d(char *dst, size_t dst_len, t_2d_line **src, size_t src_len)
{
	size_t	i;
	size_t	src_i;

	src_i = 0;
	i = 0;
	while (i < dst_len)
	{
		if (i == src_i)
			write(1, "L", 1);
		i += 1;
	}
}

// time : O(n log(n))
// space: O(n)
char	*get_mirror_of_array_of_lines(t_2d_line **line_arr, size_t arr_len,
	char is_sort)
{
	size_t	i;
	size_t	line_id;
	size_t	last;
	char	*output;

	if (is_sort == 1)
		msortl_x(line_arr, 0, arr_len);
	last = get_right_most_x(line_arr, arr_len);
	output = create_duplicate_char(last, ' ');
	if (output == NULL)
		return (NULL);
	z_buffer_1d(output, last, line_arr, arr_len);
	return (output);
}
