# include "ascii.h"

// time : O(1)
// space: O(1)
void			swap_line_x(t_2d_line **start, t_2d_line **stop)
{
	if ((*start)->left->x > (*stop)->left->x)
	{
		swap_point((*start)->left, (*stop)->left, 1);
		swap_point((*start)->right, (*stop)->right, 0);
	}
}

// time : O(n)
// space: O(n)
t_2d_line	**merge_sort_sub_linear_loop(t_2d_line **line_arr, t_2d_line **dst_arr, size_t i, size_t stop)
{
	while (i <= stop)
	{
		if ((dst_arr[i] = copy_line((line_arr)[i])) == NULL)
		{
			free_nested_arr(dst_arr, i - 1);
			dst_arr = NULL;
			i = stop;
		}
		i += 1;
	}
	return (dst_arr);
}

// time : O(n)
// space: O(n)
t_2d_line			**merge_sort_linear_loop(t_2d_line **line_arr, size_t start, size_t stop)
{
	t_2d_line	**temp_line;
	size_t	i;
	size_t	j;
	size_t	mid;

	if ((temp_line = (t_2d_line **)malloc(sizeof(t_2d_line *) * (stop - start))) == NULL)
		return (line_arr);
	mid = (stop + start) / 2;
	i = start;
	j = mid + 1;
	while (i <= mid && j <= stop)
	{
		i += 1;
		j += 1;
	}
	if (merge_sort_sub_linear_loop(line_arr, temp_line, i, mid) == NULL)
		return (line_arr);
	if (merge_sort_sub_linear_loop(line_arr, temp_line, j, stop) == NULL)
		return (line_arr);
	replace_2d_points(temp_line, line_arr + start, stop - start);
	free_nested_arr(temp_line, stop - start);
	return (line_arr);
}

// time : O(n log(n))
// space: O(n)
t_2d_line			**merge_sort_line_x(t_2d_line **line_arr, size_t start, size_t stop)
{
	size_t	mid;
	t_2d_line	**temp_line;
	size_t	i;
	size_t	j;

	if (stop - start <= 1)
	{
		swap_line_x(line_arr + start, line_arr + stop);
		return (NULL);
	}
	mid = (stop + start) / 2;
	merge_sort_line_x(line_arr, start, mid);
	merge_sort_line_x(line_arr, mid + 1, stop);
	if ((temp_line = (t_2d_line **)malloc(sizeof(t_2d_line *) * (stop - start))) == NULL)
		return (line_arr);
	i = start;
	j = mid + 1;
	while (i <= mid && j <= stop)
	{
		i += 1;
		j += 1;
	}
	while (i <= stop)
	{
		i += 1;
	}
	while (j <= stop)
	{
		j += 1;
	}
	return (line_arr);
}
