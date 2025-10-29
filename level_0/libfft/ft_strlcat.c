/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:09:05 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 19:25:39 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
cc -Wall -Wextra -Werror -lbsd ft_strlcat.c 
*/

// https://www.quora.com/
// How-does-the-C-function-strlcat-behave
// -I-read-the-manual-but-couldnt-really-understand-it

#include <stdlib.h>

//------------------------------------------------
// *** SUPPORTING FUNCTION ***
//------------------------------------------------

size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <unistd.h>

void	display_int(int fd, int x)
{
	long	d;
	char	coef;

	d = 1;
	while (d < x)
		d *= 10;
	if (d > x)
		d /= 10;
	while (d > 0)
	{
		coef = x / d + '0';
		write(fd, &coef, 1);
		x = x % d;
		d /= 10;
	}
}

void	display_int_sign(int fd, int x)
{
	if (x == 0)
	{
		write(fd, "0", 1);
	}
	else if (x > 0)
	{
		display_int(fd, x);
	}
	else if (x == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		write(fd, "-", 1);
		display_int(fd, (-1) * x);
	}
}
*/

//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

/*
size = the total output number of dst with new appened string.
The strlcat() function appends the NUL-terminated string src to the end of dst.
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
*/

/*
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = f_strlen(dst);
	len_src = f_strlen(src);
	i = 0;
	while (i + len_dst < size - 1 && *(src + i) != '\0')
	{
		*(dst + len_dst + i) = *(src + i);
		i += 1;
	}
	*(dst + len_dst + i) = '\0';
	return (len_dst + len_src);
}
*/

/*
// Wrong version from website 
// https://c-for-dummies.com/blog/?p=3908
size_t	ft_strlcat(char *dst, char *src, int n)
{
	int	i;
	int	j;
	int	d_len;
	int	dst_len;
	int	s_len;

	i = 0;
	j = 0;
	d_len = f_strlen(dst);
	dst_len = d_len;
	s_len = f_strlen(src);
	while (*(src + i) != '\0' && j != -1)
	{
		*(dst + d_len) = *(src + i);
		i += 1;
		d_len += 1;
		if (d_len == n - 1)
			j = -1;
	}
	*(dst + d_len) = '\0';
	return (dst_len + s_len);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

/*
DESCRIPTION

strlcat() functions concatenate strings.
strlcat() is designed to be safer than strncat(3).

Unlike strncat(), strlcat take the full size of the buffer
(not just the length) and gurantee to NUL-terminate the
result, as long as the size is larger than 0, or 
as long as there is at least 1 byte free in dst.

Note that a byte for the NUL should be included in size.

The strlcat() function appends the NUL-terminated string src to the end of dst.
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.

RETURN VALUES

strlcat() return the initial length of dst plus the length of src
to make truncation detection simple.

Note, however, that if strlcat() traverses size characters without finding a NUL,
the length of the string is considered to be size 
and the destination string will not be NUL-terminated 
(since there was no space for the NUL).  

This keeps strlcat() from running off the end of a string.
In practice this should not happen (as it means that either size is incorrect or
that dst is not a proper “C” string).

The check exists to prevent potential security problems in incorrect code.
*/

/*
// Prevent the case that user set size < 0.
if ((int) size < 0)
	size = len_dst + len_src + 1;

// size = 0 means do not append anythings.
if (size == 0)
	return (len_src);

// It will append at most size - strlen(dst) - 1 bytes
if (len_dst > size)
	return (len_src + size);
return (len_dst + len_src);
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = f_strlen(dst);
	len_src = f_strlen(src);
	i = 0;
	if ((int) size < 0)
		size = len_dst + len_src + 1;
	if (size == 0)
		return (len_src);
	while ((int)(i + len_dst) < (int)((int) size - 1) && *(src + i) != '\0')
	{
		*(dst + len_dst + i) = *(src + i);
		i += 1;
	}
	*(dst + len_dst + i) = '\0';
	if (len_dst > size)
		return (len_src + size);
	return (len_dst + len_src);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*

size_t	f_strlcpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i += 1;
	}
	if (i == n)
		i -= 1;
	*(dst + i) = '\0';
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}

int	main(int av, char **array)
{
	char	*my_dest;
	size_t	my_len;
	char	*th_dest;
	size_t	th_len;
	int		len;
	int		len2;

	if (av < 3)
		return (0);
	len = f_strlen(*(array + 1));
	len2 = f_strlen(*(array + 2));
	my_dest = (char *)malloc(len + len2);
	th_dest = (char *)malloc(len + len2);
	f_strlcpy(my_dest, *(array + 1), len);
	strlcpy(th_dest, *(array + 1), len);
	my_len = ft_strlcat(my_dest, *(array + 2), len2);// + len2);
	th_len = strlcat(th_dest, *(array + 2), len2);// + len2);
	write(1, "Input :\t", 8);
	write(1, *(array + 1), len);
	write(1, "\n", 1);
	write(1, "My Result:\t", 11);
	write(1, my_dest, len + len2);
	write(1, "\n", 1);
	write(1, "True Result:\t", 13);
	write(1, th_dest, len + len2);
	write(1, "\n", 1);
	free(my_dest);
	free(th_dest);
	display_int(my_len);
	write(1, "\n", 1);
	display_int(th_len);
	write(1, "\n", 1);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
int	main(int av, char **ac)
{
	char	*dest;
	char	*fest = (char *)malloc(sizeof(*fest) * 15);
	int		arg;
	size_t	y;
	size_t	x;

	alarm(5);
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || av == 1 || fest == NULL)
		return (0);
	memset(dest, 0, 15);
	memset(fest, 0, 15);
	memset(dest, 'r', 15);
	memset(fest, 'r', 15);
	if ((arg = atoi(ac[1])) == 11)
	{
		y = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
		write(1, dest, strlen(dest));
		write(1, "\n", 1);
		display_int_sign(1, y);
		y = strlen(dest);
		write(1, "\n", 1);
		display_int_sign(1, y);
		write(1, "\n", 1);
	}
	// else if (arg == 12)
	// {
	// 	dest[10] = 'a';
	// 	y = ft_strlcat(dest, "lorem ipsum dolor sit amet", 1);
	// 	write(1, dest, strlen(dest));
	// 	write(1, "\n", 1);
	// 	display_int_sign(1, y);
	// }
	// else if (arg == 13)
	// {
	// 	memset(dest, 'r', 15);
	// 	y = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
	// 	write(1, dest, strlen(dest));
	// 	write(1, "\n", 1);
	// 	display_int_sign(1, y);
	// }
	else if (arg == 21)
	{
		y = strlcat(fest, "lorem ipsum dolor sit amet", 5);
		write(1, fest, strlen(fest));
		write(1, "\n", 1);
		display_int_sign(1, y);
		y = strlen(fest);
		write(1, "\n", 1);
		display_int_sign(1, y);
		write(1, "\n", 1);
	}
	else
	{
		y = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
		x = strlcat(fest, "lorem ipsum dolor sit amet", 5);
		if (strcmp(fest, dest) != 0)
			write(1, "Error Error Error\n", 18);
		else
			write(1, "Insane Debugging\n", 18);
		if (y == x)
			write(1, "Injective Function\n", 20);
		else
			write(1, "Singular Matrix\n", 17);
		write(1, dest, strlen(dest));
		write(1, "\t", 1);
		display_int_sign(1, y);
		write(1, "\n", 1);
		write(1, fest, strlen(fest));
		write(1, "\t", 1);
		display_int_sign(1, x);
		write(1, "\n", 1);
	}
	// else if (arg == 22)
	// {
	// 	dest[10] = 'a';
	// 	y = strlcat(dest, "lorem ipsum dolor sit amet", 1);
	// 	write(1, dest, strlen(dest));
	// 	write(1, "\n", 1);
	// 	display_int_sign(1, y);
	// }
	// else if (arg == 23)
	// {
	// 	memset(dest, 'r', 15);
	// 	y = strlcat(dest, "lorem ipsum dolor sit amet", 5);
	// 	write(1, dest, strlen(dest));
	// 	write(1, "\n", 1);
	// 	display_int_sign(1, y);
	// }
	return (0);
}
*/

/*
NOTE
According to libft-war-machine, 
ft_strlcat	✓✓✓✓✓✓✗✓✓	KO

I copy paste ft_strcat from this URL 
https://42-cursus.gitbook.io/guide/0-rank-00/
libft/libc-functions/ft_strlcat

and this yield the same KO results, which means that
libft-war-machine have ft_strlcat related error.
*/

//------------------------------------------------
// *** LIBFT TESTER TEST ***
//------------------------------------------------

/*
int	main(void)
{
	char dest[30]; memset(dest, 0, 30);
	char * src = (char *)"AAAAAAAAA"; // 9

	dest[0] = 'B';
	write(1, "*** T 01 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, src, 0));
	write(1, " = ", 3);
	display_int_sign(1, strlen(src));
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "B", 1);
	write(1, "\n\n", 2);

	dest[0] = 'B';
	write(1, "*** T 02 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, src, 1));
	write(1, " = ", 3);
	display_int_sign(1, 10);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "B", 1);
	write(1, "\n\n", 2);

	memset(dest, 'B', 4);
	write(1, "*** E 03 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, src, 3));
	write(1, " = ", 3);
	display_int_sign(1, strlen(src) + 3);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "BBBB", 4);
	write(1, "\n\n", 2);

	write(1, "*** T 04 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, src, 6));
	write(1, " = ", 3);
	display_int_sign(1, 13);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "BBBBA", 5);
	write(1, "\n\n", 2);

	memset(dest, 'C', 5);
	write(1, "*** F 05 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, src, -1));
	write(1, " = ", 3);
	display_int_sign(1, 14);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "CCCCCAAAAAAAAA", 15);
	write(1, "\n\n", 2);

	memset(dest, 'C', 15);
	write(1, "*** T 06 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, src, 17));
	write(1, " = ", 3);
	display_int_sign(1, 24);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "CCCCCCCCCCCCCCCA", 17);
	write(1, "\n\n", 2);

	memset(dest, 0, 30);
	memset(dest, '1', 10);
	write(1, "*** E 08 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, src, 5));
	write(1, " = ", 3);
	display_int_sign(1, strlen(src) + 5);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "1111111111", 11);
	write(1, "\n\n", 2);

	memset(dest, 0, 30);
	memset(dest, '1', 10);
	write(1, "*** E 09 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, src, 5));
	write(1, " = ", 3);
	display_int_sign(1, strlen(src) + 5);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "1111111111", 11);
	write(1, "\n\n", 2);

	memset(dest, 0, 30);
	write(1, "*** T 16 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, "123", 4));
	write(1, " = ", 3);
	display_int_sign(1, 3);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "123", 3);
	write(1, "\n\n", 2);

	memset(dest, 0, 30);
	write(1, "*** T 17 ***\n", 14);
	display_int_sign(1, ft_strlcat(dest, "123", 0));
	write(1, " = ", 3);
	display_int_sign(1, 3);
	write(1, "\n", 1);
	write(1, dest, strlen(dest));
	write(1, " = ", 3);
	write(1, "\n\n", 2);

	return (0);
}
*/

/*
cc -Wall -Wextra -Werror -lbsd ft_strlcat.c 
*/
