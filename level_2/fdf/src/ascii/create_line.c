# include "ascii.h"

// time : O(1)
// space: O(1)
void			swap_point(t_2d_dim *start, t_2d_dim *stop, char is_sort)
{
	size_t	temp;

	if ((start->x > stop->x && is_sort == 1) || is_sort == 0)
	{
		temp = start->x;
		start->x = stop->x;
		stop->x = temp;
		temp = start->y;
		start->y = stop->y;
		stop->y = temp;
	}
}

t_2d_dim		*copy_2d_point(t_2d_dim *src)
{
	t_2d_dim	*dst;

	if ((dst = (t_2d_dim *)malloc(sizeof(t_2d_dim))) == NULL)
		return (NULL);
	dst->x = src->x;
	dst->y = src->y;
	return (dst);
}

t_2d_dim		*replace_2d_points(t_2d_dim **src, t_2d_dim **dst, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		(dst[i])->x = (src[i])->x;
		(dst[i])->y = (src[i])->y;
		i += 1;
	}
	return (dst);
}

void			free_line(t_2d_line *line)
{
	if (line != NULL)
	{
		if (line->left != NULL)
			free(line->left);
		if (line->right != NULL)
			free(line->right);
		free(line);
	}
}

t_2d_line			*copy_line(t_2d_line *src)
{
	t_2d_line	*dst;

	if ((dst = (t_2d_line *)malloc(sizeof(t_2d_line))) == NULL)
		return (NULL);
	dst->right = NULL;
	if ((dst->left = copy_2d_point(src->left)) == NULL)
	{
		free_line(dst);
		return (NULL);
	}
	if ((dst->right = copy_2d_point(src->right)) == NULL)
	{
		free_line(dst);
		return (NULL);
	}
	swap_point(dst->left, dst->right, 1);
	return (dst);
}

