# How am I doing this project ?

## How to use Library ?

1.  Creating `libft.a`
    1.  Git clone libft directory.
    2.  `cd libft`
    3.  `make`
    4.  Copy `libft/libft.a` as `libft.a` in root directory.
2.  Creating `libmlx42.a`
    1.  git clone [... url of Git repo of MLX42 ]
    2.  `cd MLX42`
    3.  `make`
    4.  Copy `MLX42/build/libmlx42.a` as `libmlx42.a` in root directory.
3.  Creating `include/` folder which contains the copy of `libft.h` and `MLX42.h`
4.  Creating `main.c` to test if library works as expected.

```
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "MLX42.h"
#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
static void	ft_error(void)
{
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void	ft_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	ft_putnbr_fd(mlx->width, 1);
	write(1, "\n", 1);
}

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
```
5.  Executing this command.
*   `cc -Wall -Wextra -Werror main.c -Iinclude libmlx42.a libft.a -ldl -lglfw -pthread -lm`

Meaning of each Bash command
1.  `-l` is the name of the library you want to link to.
2.  `-L` adds a directory to the list of places searched by the linker for a library named with the -l option.
3.  `-I` adds a directory to the list of places searched by the compiler for a file named on a #include line
4.  `-pthread`
*   thread = the smallest sequence of programmed instructions that can be managed independently by an operating system scheduler.
*   Pthreads or POSIX threads are one implementation of that concept used with C program on Unix.

Note that
*   MLX42 is better than minilibX.
*	It is much more common that people use dynamic link (for saving memory) before switch to static link only if there is the dependency (e.g. DLL Hell) and/or performance (e.g. faster load, environment don't support dynamic linked due to limited disk etc.) related issues. However, both MLX42 and Libft are small library, and Static linking is suitable for small coding project.

Resource
1.  MLX42
*   https://github.com/codam-coding-college/MLX42#download-and-build---mlx42
2.  `-I`, `-L`, and `-l` option for `cc` command
*   https://stackoverflow.com/questions/519342/what-is-the-difference-between-i-and-l-in-makefile
3.  Pthread
*   https://www.reddit.com/r/explainlikeimfive/comments/1jwix0w/eli5_what_are_threads_in_operating_system/
*   https://stackoverflow.com/questions/15127279/whats-a-pthread
4.  Static linking vs dynamic linking
*	https://stackoverflow.com/questions/1993390/static-linking-vs-dynamic-linking

## isometric projection

Resource
1.	.
*	.

## Quaternion Ring

Resource
1.	Visualizing the 4d numbers Quaternions
*	https://youtu.be/d4EgbgTm0Bg?si=4GJXwx9ZxE78nI8u

## Calculating Brightness of Light interacting with 3D Object

Resource
1.	.
*	.

## Text Color Synesthesia

My Text Color Synesthesia
*	A = red
*	B = blue
*	C = bright yellow
*	...

Resource
1.	.
*	.
