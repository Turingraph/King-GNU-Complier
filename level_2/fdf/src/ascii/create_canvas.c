/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:02:39 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/23 12:33:12 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

// time : O(n^2)
// space: O(1)
void	free_nested_arr(void **target, size_t length)
{
	while (length > 0)
	{
		if (target[length] != NULL)
			free(target[length]);
		length -= 1;
	}
	free(target[length]);
	free(target);
}

// time : O(n)
// space: O(n)
char	*create_duplicate_char(size_t length, char space)
{
	size_t	i;
	char	*text;

	text = malloc(sizeof(char) * (length + 1));
	if (text == NULL)
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

	canvas = (t_ascii_canvas *)malloc(sizeof(t_ascii_canvas));
	if (canvas == NULL)
		return (NULL);
	canvas->w = w;
	canvas->h = h;
	canvas->canvas = (char **)malloc(sizeof(char *) * (h));
	if (canvas->canvas == NULL)
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
	free_nested_arr(canvas->canvas, height);
	free(canvas);
}

// time : O(n^2)
// space: O(n^2)
t_ascii_canvas	*ascii_create_canvas(size_t w, size_t h)
{
	t_ascii_canvas	*canvas;
	size_t			i;
	size_t			j;

	canvas = ascii_define_canvas(w, h);
	if (canvas == NULL)
		return (NULL);
	i = 0;
	while (i < canvas->h)
	{
		canvas->canvas[i] = create_duplicate_char(canvas->w, ' ');
		if (canvas->canvas[i] == NULL)
		{
			ascii_delete_canvas(canvas->canvas, i - 1);
			return (NULL);
		}
		i += 1;
	}
	return (canvas);
}
