# include "ascii.h"

// time : O(n^2)
// space: O(1)
void	free_nested_arr(void **target, size_t length)
{
	while (length > 0)
	{
		free(*(target + length));
		length -= 1;
	}
	free(*(target + length));
	free(target);
}

// time : O(n)
// space: O(n)
char	*create_duplicate_char(size_t length, char space)
{
	size_t	i;
	char	*text;

	if ((text = malloc(sizeof(char) * (length + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(text + i) = space;
		i += 1;
	}
	*(text + i) = '\0';
	return (text);
}

// time : O(n)
// space: O(n)
t_ascii_canvas	*ascii_define_canvas(size_t w, size_t h)
{
	t_ascii_canvas	*canvas;

	if ((canvas = (t_ascii_canvas *)malloc(sizeof(t_ascii_canvas))) == NULL)
		return (NULL);
	(*canvas).w = w;
	(*canvas).h = h;
	if (((*canvas).canvas = (char **)malloc(sizeof(char *) * (h))) == NULL)
	{
		free(canvas);
		return (NULL);
	}
	return (canvas);
}

// time : O(n^2)
// space: O(1)
void	ascii_delete_canvas(t_ascii_canvas *canvas, size_t height)
{
	free_nested_arr((*canvas).canvas, height);
	free((*canvas).canvas);
	free(canvas);
}

// time : O(n^2)
// space: O(n^2)
t_ascii_canvas	*ascii_create_canvas(size_t w, size_t h)
{
	t_ascii_canvas	*canvas;
	size_t			i;
	size_t			j;

	if ((canvas = ascii_define_canvas(w, h)) == NULL)
		return (NULL);
	i = 0;
	while (i < (*canvas).h)
	{
		if ((*((*canvas).canvas + i) = create_duplicate_char((*canvas).w, ' ')) == NULL)
		{
			ascii_delete_canvas((*canvas).canvas, i - 1);
			return (NULL);
		}
		i += 1;
	}
	return (canvas);
}
