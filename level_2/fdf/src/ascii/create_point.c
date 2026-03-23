/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:11:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/23 12:19:10 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

// time : O(1)
// space: O(1)
void	swap_point(t_2d_dim *start, t_2d_dim *stop, char is_sort)
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

// time : O(1)
// space: O(1)
t_2d_dim	*copy_2d_point(t_2d_dim *src)
{
	t_2d_dim	*dst;

	dst = (t_2d_dim *)malloc(sizeof(t_2d_dim));
	if (dst == NULL)
		return (NULL);
	dst->x = src->x;
	dst->y = src->y;
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_dim	*replace_2d_points(t_2d_dim **src, t_2d_dim **dst, size_t len)
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
