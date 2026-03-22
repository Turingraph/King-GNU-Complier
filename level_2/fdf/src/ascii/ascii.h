
#ifndef ASCII_H
# define ASCII_H

// "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'. "
// https://paulbourke.net/dataformats/asciiart/

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include <math.h>

#define TRUE (char) 0
#define FALSE (char) 1

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

// create.c
void			free_nested_arr(void **target, size_t length);
char			*create_empty_line(size_t length, char space);
t_ascii_canvas	*ascii_define_canvas(size_t w, size_t h);
void			ascii_delete_canvas(t_ascii_canvas *canvas, size_t height);
t_ascii_canvas	*ascii_create_canvas(size_t w, size_t h);

// import.c
t_ascii_canvas	*ascii_import_canvas(char *file_name);
t_ascii_canvas	*ascii_export_canvas(char *file_name);

// bresenham_line.c
void	bresenham_line(t_2d_dim *v1, t_2d_dim *v2, t_ascii_canvas *canvas, char mark);

// flood_fill.c
void	flood_filling(t_ascii_canvas *canvas, t_2d_dim *v, char color);
void	ascii_replace(t_ascii_canvas *canvas, char old_color, char new_color);

// clean.c
t_ascii_canvas	*add_ascii_left_column(t_ascii_canvas *canvas);
t_ascii_canvas	*add_ascii_right_column(t_ascii_canvas *canvas);
t_ascii_canvas	*add_ascii_down_row(t_ascii_canvas *canvas);
t_ascii_canvas	*add_ascii_up_row(t_ascii_canvas *canvas);

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
