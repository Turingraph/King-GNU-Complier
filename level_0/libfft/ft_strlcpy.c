/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:38:19 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 19:30:23 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strlcpy() function copies up to size - 1 characters
from the NUL-terminated string src to dst, NUL-terminating the result.

// man strlcpy

strlcpy writes a null character into the last byte of the destination.

// https://stackoverflow.com/questions/76539577/
// what-is-the-purpose-of-strlcpy-and
// -what-was-in-the-first-version-of-its-manual-p

Some functions that you must reimplement, such as strlcpy, strlcat,
and bzero, are not included by default in the GNU C Library (glibc).
To test them against the system standard, you may need to include
<bsd/string.h> and compile with the -lbsd flag.

// Use -lbsd frag.

cc -Wall -Wextra -Werror -lbsd ft_strlcpy.c

// https://c-for-dummies.com/blog/?p=3886

*/

#include <stdlib.h>

//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

/*
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i += 1;
	}
	if (i == size)
		i -= 1;
	*(dst + i) = '\0';
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

/*
// Copy at most size char, including '\0'
if (i == size && i > 0)
	i -= 1;
// This prevent case where *(dst - 1) = '\0'.
if (size > 0)
	*(dst + i) = '\0';
// Return the length of src.
while (*(src + i) != '\0')
	i += 1;
return (i);
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i += 1;
	}
	if (i == size && i > 0)
		i -= 1;
	if (size > 0)
		*(dst + i) = '\0';
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}

/*
	if (i == size)
		i -= 1;
	if (i < 0)
		return (1);
*/

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

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

/*
int	main(int av, char **array)
{
	char	*my_dest;
	int		my_len;
	char	*th_dest;
	int		th_len;
	int		len;

	if (av < 2)
		return (0);
	len = f_strlen(*(array + 1));
	my_dest = (char *)malloc(len);
	th_dest = (char *)malloc(len);
	my_len = ft_strlcpy(my_dest, *(array + 1), len);
	th_len = strlcpy(th_dest, *(array + 1), len);
	write(1, "Input :\t", 8);
	write(1, *(array + 1), len);
	write(1, "\n", 1);
	write(1, "My Result:\t", 11);
	write(1, my_dest, len);
	write(1, "\n", 1);
	write(1, "True Result:\t", 13);
	write(1, th_dest, len);
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
int	main(void)
{
	char	*dest;
	size_t	y;

	dest = (char *)malloc(sizeof(char *) * 15);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	y = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
	display_int(y);
	write(1, "\n", 1);
	write(1, dest, 15);
	write(1, "\n", 1);
	return (0);
}
*/

/*
int	main(void)
{
	char	*dest;
	size_t	y;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	y = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
	write(1, dest, strlen(dest));
	write(1, "\n", 1);
	write(1, "y = ", 4);
	display_int_sign(1, y);
	write(1, "\n", 1);
	return (0);
}
*/

//------------------------------------------------
// *** LIBFT TESTER TEST ***
//------------------------------------------------

/*
int	main(void)
{
	char	*dest;
	size_t	y;

	dest = (char *)malloc(sizeof(char *) * 10);
	memset(dest, 'A', 9);
	*(dest + 9) = '\0';
	y = ft_strlcpy(dest, "1", 0);
	display_int(y);
	write(1, "\n", 1);
	write(1, dest, 10);
	write(1, "\n", 1);
	return (0);
}
*/
