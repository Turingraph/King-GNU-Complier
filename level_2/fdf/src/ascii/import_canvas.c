/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:12:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/23 11:16:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

// time : O(n^2)
// space: O(n)
t_2d_dim	*ascii_get_import_canvas_dim(int fd)
{
	char			*line;
	t_2d_dim		*dim;

	if ((dim = (t_2d_dim *)malloc(sizeof(t_2d_dim))) == NULL)
		return (NULL);
	(dim)->x = 0;
	(dim)->y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if ((dim)->x < knight_of_coin(line, '\n'))
			(dim)->x = knight_of_coin(line, '\n');
		free(line);
		line = get_next_line(fd);
		(dim)->y += 1;
	}
	return (dim);
}

// time : O(n^2)
// space: O(n)
t_2d_dim	*ascii_get_import_canvas_dim_handle(int fd)
{
	t_ascii_canvas	*y;
	t_2d_dim		*dim;

	dim = ascii_get_import_canvas_dim(fd);
	if (dim == NULL)
		return (NULL);
	y = ascii_define_canvas(dim->x, dim->y);
	if (y == NULL)
	{
		free(dim);
		return (NULL);
	}
	free(dim);
	return (y);
}

// time : O(n^2)
// space: O(n^2)
t_ascii_canvas	*ascii_get_import_canvas_text(int fd_dim, int fd_copy)
{
	t_ascii_canvas	*y;
	char			*line;
	size_t			i;

	y = ascii_get_import_canvas_dim_handle(fd_dim);
	if (y == NULL)
		return (NULL);
	i = 0;
	line = get_next_line(fd_copy);
	while (line != NULL || i < y->h)
	{
		if (line == NULL)
			*(y->canvas + i) = NULL;
		else
		{
			*(y->canvas + i) = ace_of_coin(line,
					knight_of_coin(line, '\0'), y->w);
			free(line);
		}
		line = get_next_line(fd_copy);
		i += 1;
	}
	return (y);
}

// time : O(n^2)
// space: O(n^2)
t_ascii_canvas	*ascii_import_canvas(char *file_name)
{
	int				fd_dim;
	int				fd_copy;

	fd_dim = open(file_name, 'r');
	fd_copy = open(file_name, 'r');
	if (fd_dim < 0 || fd_copy < 0)
		return (NULL);
	return (ascii_get_import_canvas_text(fd_dim, fd_copy));
}
