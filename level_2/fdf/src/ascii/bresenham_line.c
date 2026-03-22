# include "ascii.h"

// time : O(1)
// space: O(1)
void	swap_vector(t_2d_dim *v1, t_2d_dim *v2, char is_x)
{
	size_t	temp;

	if ((is_x == 1 && v1->x >= v2->x) || 
		(is_x == 0 && v1->y >= v2->y))
	{
		temp = v1->x;
		v1->x = v2->x;
		v2->x = temp;
		temp = v1->y;
		v1->y = v2->y;
		v2->y = temp;
	}
}

/*
Condition
*	l <= m <= r
*	y <= (d_y / d_x) + y <= y + 1
*	y d_x <= d_y + y d_x <= y d_x + d_x

Add 1 when
*	r - m <= m - l
*	0 <= m - l + m - r
*	0 <= 2 m - l - r
*	0 <= 2 d_y + 2 y d_x - y d_x - y d_x - d_x
*	0 <= 2 d_y + 2 y d_x - 2 y d_x - d_x
*	0 <= 2 d_y - d_x

Condition when y += j, where j <= i
*	y + j <= (d_y / d_x) i + y <= y + j + 1
*	y d_x + j d_x <= d_y i + y d_x <= y d_x + j d_x + d_x
*	0 <= 2 m - l - r
*	0 <= 2 d_y i + 2 y d_x - l - r
*	0 <= 2 d_y i + 2 y d_x - y d_x - j d_x - r
*	0 <= 2 d_y i + y d_x - j d_x - r
*	0 <= 2 d_y i + y d_x - j d_x - y d_x - j d_x - d_x
*	0 <= 2 d_y i + y d_x - 2 j d_x - y d_x - d_x
*	0 <= 2 d_y i - 2 j d_x - d_x
*/

// time : O(n)
// space: O(1)
char	bresenham_line_x(t_2d_dim *v1, t_2d_dim *v2, t_ascii_canvas *canvas, char mark)
{
	size_t	i;
	int		decision;
	int		sign;

	sign = 1;
	if ((int) v2->y - (int) v1->y < 0)
		sign -= 1;
	decision = 2 * abs(v2->y - v1->y) - abs(v2->x - v1->x);
	while (v1->x <= v2->x)
	{
		canvas->canvas[v1->y][v1->x] = mark;
		if (decision >= 0)
		{
			decision -= 2 * abs(v2->x - v1->x);
			v1->y += sign;
		}
		decision += 2 * abs(v2->y - v1->y);
		v1->x += 1;
	}
}

// time : O(n)
// space: O(1)
char	bresenham_line_y(t_2d_dim *v1, t_2d_dim *v2, t_ascii_canvas *canvas, char mark)
{
	size_t	i;
	int		decision;
	int		sign;

	sign = 1;
	if ((int) v2->x - (int) v1->x < 0)
		sign -= 1;
	decision = 2 * abs(v2->x - v1->x) - abs(v2->y - v1->y);
	while (v1->y <= v2->y)
	{
		canvas->canvas[v1->y][v1->x] = mark;
		if (decision >= 0)
		{
			decision -= 2 * abs(v2->y - v1->y);
			v1->x += sign;
		}
		decision += 2 * abs(v2->x - v1->x);
		v1->y += 1;
	}
}

// time : O(n)
// space: O(1)
void	bresenham_line(t_2d_dim *v1, t_2d_dim *v2, t_ascii_canvas *canvas, char mark)
{
	if (v1->x < 0 || v1->x >= canvas->w || v2->x < 0 || v2->x >= canvas->w ||
		v1->y < 0 || v1->y >= canvas->h || v2->y < 0 || v2->y >= canvas->h)
		return (0);
	if (abs(v1->x - v2->x) <= abs(v1->y - v2->y))
	{
		swap_vector(v1, v2, 0);
		bresenham_line_y(v1, v2, canvas, mark);
	}
	else
	{
		swap_vector(v1, v2, 1);
		bresenham_line_x(v1, v2, canvas, mark);
	}
}
