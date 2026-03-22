# include "ascii.h"

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
	while ((line = get_next_line(fd)) != NULL)
	{
		if ((dim)->x < knight_of_coin(line, '\n'))
			(dim)->x = knight_of_coin(line, '\n');
		free(line);
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

	if((dim = ascii_get_import_canvas_dim(fd)) == NULL)
		return (NULL);
	if ((y = ascii_define_canvas(dim->x, dim->y)) == NULL)
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

	if ((y = ascii_get_import_canvas_dim_handle(fd_dim)) == NULL)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd_copy)) != NULL || i < y->h)
	{
		if (line == NULL)
			*(y->canvas + i) = NULL;
		else
		{
			*(y->canvas + i) = ace_of_coin(line, knight_of_coin(line, '\0'), y->w);
			free(line);
		}
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

	if ((fd_dim = open(file_name, 'r')) < 0 || (fd_copy = open(file_name, 'r')) < 0)
		return (NULL);
	return (ascii_get_import_canvas_text(fd_dim, fd_copy));
}
