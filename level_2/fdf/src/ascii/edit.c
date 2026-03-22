# include "ascii.h"

void			replace_ascii_char(t_ascii_canvas *canvas, char old_color, char new_color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < canvas->h)
	{
		j = 0;
		while (j < canvas->w)
		{
			if (canvas->canvas[i][j] == old_color)
				canvas->canvas[i][j] = new_color;
			j += 1;
		}
		i += 1;
	}
}

t_ascii_canvas	*add_ascii_column(t_ascii_canvas *canvas, char is_left)
{
	t_ascii_canvas	*new_canvas;
	size_t			i;

	if((new_canvas = ascii_create_canvas(canvas->w + 1, canvas->h)) == NULL)
	{
		ascii_delete_canvas(canvas, canvas->h);
		return (NULL);
	}
	i = 0;
	while (i < canvas->h)
	{
		if (is_left == 1)
		{
			ft_strlcpy(new_canvas->canvas[i], canvas->canvas[i], canvas->w);
			*(new_canvas->canvas[i] + canvas->w) = ' ';
		}
		else
			ft_strlcpy(new_canvas->canvas[i] + 1, canvas->canvas[i], canvas->w);
		i += 1;
	}
	ascii_delete_canvas(canvas, canvas->h);
	return (new_canvas);
}

t_ascii_canvas	*add_ascii_row(t_ascii_canvas *canvas, char is_down)
{
	t_ascii_canvas	*new_canvas;
	size_t			i;
	size_t			j;

	if((new_canvas = ascii_create_canvas(canvas->w, canvas->h + 1)) == NULL)
	{
		ascii_delete_canvas(canvas, canvas->h);
		return (NULL);
	}
	j = 1;
	if (is_down == 1)
		j = 0;
	i = 0;
	while (i < canvas->h)
	{
		ft_strlcpy(new_canvas->canvas[i + j], canvas->canvas[i], canvas->w);
		i += 1;
	}
	ascii_delete_canvas(canvas, canvas->h);
	return (new_canvas);
}
