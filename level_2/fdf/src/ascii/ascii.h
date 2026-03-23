/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:18:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/23 12:23:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCII_H
# define ASCII_H

// "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'. "
// https://paulbourke.net/dataformats/asciiart/

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include <math.h>

// Global variables are forbidden in the assignment.
// #define TRUE (char) 1
// #define FALSE (char) 0

typedef struct t_ascii_canvas
{
	size_t	w;
	size_t	h;
	char	**canvas;
}	t_ascii_canvas;

typedef struct t_2d_dim
{
	size_t	x;
	size_t	y;
}	t_2d_dim;

typedef struct t_2d_triangle
{
	t_2d_dim	*u;
	t_2d_dim	*v;
	t_2d_dim	*w;
}	t_2d_triangle;

typedef struct t_2d_line
{
	t_2d_dim	*left;
	t_2d_dim	*right;
}	t_2d_line;

/*
// flood_fill.c

// I don't add this feature for saving time.

void	flood_fill(t_ascii_canvas *canvas, t_2d_dim *v, char color);

typedef struct t_noah_tree
{
	t_noah_tree	*left;
	t_noah_tree	*middle;
	t_noah_tree	*right;
} t_noah_tree;

typedef struct t_lamech_tree
{
	t_noah_tree	*left;
	t_noah_tree	*up;
	t_noah_tree	*right;
	t_noah_tree	*down;
	size_t		height;
	size_t		count;
} t_lamech_tree;
*/

// bresenham_line.c
char			bresenham_line(t_2d_dim *v1, t_2d_dim *v2,
					t_ascii_canvas *canvas, char mark);

// create_canvas.c
void			free_nested_arr(void **target, size_t length);
char			*create_duplicate_char(size_t length, char space);
t_ascii_canvas	*ascii_define_canvas(size_t w, size_t h);
void			ascii_delete_canvas(t_ascii_canvas *canvas, size_t height);
t_ascii_canvas	*ascii_create_canvas(size_t w, size_t h);

// create_line.c
void			free_line(t_2d_line *line);
t_2d_line		*create_line(size_t x_1, size_t y_1, size_t x_2, size_t y_2);
t_2d_line		*copy_line(t_2d_line *src);

// create_point.c
void			swap_point(t_2d_dim *start, t_2d_dim *stop, char is_sort);
t_2d_dim		*copy_2d_point(t_2d_dim *src);
t_2d_dim		*replace_2d_points(t_2d_dim **src, t_2d_dim **dst, size_t len);

// edit_canvas.c
void			replace_ascii_char(t_ascii_canvas *canvas, char old_color,
					char new_color);
t_ascii_canvas	*add_ascii_column(t_ascii_canvas *canvas, char is_left);
t_ascii_canvas	*add_ascii_row(t_ascii_canvas *canvas, char is_down);

// import_canvas.c
t_ascii_canvas	*ascii_import_canvas(char *file_name);

// rasterization.c
void			rasterization(t_2d_triangle *triangle, char color);

// sort_line.c
t_2d_line		**msortl_x(t_2d_line **line_arr, size_t start, size_t stop);

// z_buffer_1d.c
char			*z_buffer_1d(t_ascii_canvas *canvas, t_2d_line **line_arr,
					size_t arr_len);

#endif

/*
Algorithm List
1.	...

1D Z Buffer hints.
1.	time : O(n), space: O(n)
2.	It use O(n) space to track all the lines (a.k.a. pairs of 2D vectors).
3.	2D Z Buffer require Tesseration and Rasterization.

To Do List
1.	Implementing those algorithms
*	flood filling algorithm




1.	Implementing draw.c
2.	Write and executing test.c
3.	Generating alphabet/ using https://textarttools.com/Figletfontstool/?utm_source=chatgpt.com
4.	2D projection of 3D image
5.	quaternion and fdf.
6.	frag (prism vs standatd fdf)

Feature
1.	42 FdF (isomorphic and text file input)
2.	Quaternion
3.	Light (miniRL)
5.	Prism

Future Feature
1.	ASCII manipulation (used in Pixel Art tool and ASCII cleaning)
2.	3D Sweep Line (readability)
3.	2 Independent 2D ASCII pair for 4D Prism

Project
1.	GrASCIIti
*/
