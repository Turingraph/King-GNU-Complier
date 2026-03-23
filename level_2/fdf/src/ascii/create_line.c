/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:05:07 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/23 12:21:44 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

// time : O(1)
// space: O(1)
void	free_line(t_2d_line *line)
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

// time : O(1)
// space: O(1)
t_2d_line	*create_line(size_t x_1, size_t y_1, size_t x_2, size_t y_2)
{
	t_2d_line	*output;

	output = (t_2d_line *)malloc(sizeof(t_2d_line));
	if (output == NULL)
		return (NULL);
	output->right = NULL;
	output->left = (t_2d_dim *)malloc(sizeof(t_2d_dim));
	if (output->left == NULL)
	{
		free_line(output);
		return (NULL);
	}
	output->left->x = x_1;
	output->left->y = y_1;
	output->right = (t_2d_dim *)malloc(sizeof(t_2d_dim));
	if (output->right == NULL)
	{
		free_line(output);
		return (NULL);
	}
	output->right->x = x_2;
	output->right->y = y_2;
	swap_point(output->left, output->right, 1);
	return (output);
}

// time : O(1)
// space: O(1)
t_2d_line	*copy_line(t_2d_line *src)
{
	t_2d_line	*dst;

	dst = create_line(src->left->x, src->left->y, src->right->x, src->right->y);
	return (dst);
}
