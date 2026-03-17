/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:38:29 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:05:20 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//------------------------------------------------
// *** SUPPORTING FUNCTION ***
//------------------------------------------------
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*y;
	size_t	product;

	product = nmemb * size;
	if (product == 0 || product > 2147483647)
		return (NULL);
	y = (void *)malloc(product);
	return (y);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

/*
I have to use f_bezero to make every char 
in `y = (void *)malloc(product);` becomes '\0'.
*/

void	f_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*y;

	y = s;
	i = 0;
	while (i < n)
	{
		*(y + i) = '\0';
		i += 1;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*y;
	size_t	product;

	product = nmemb * size;
	if (nmemb == 0 || size == 0)
		product = 1;
	if ((nmemb > 2147483647 && size > 2147483647) || product > 2147483647
		|| product < 0)
		return (NULL);
	y = (void *)malloc(product);
	if (y == NULL)
		return (y);
	f_bzero(y, product);
	return (y);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

// https://stackoverflow.com/questions/37132549/
// implementation-of-strdup-in-c-programming
// https://www.reddit.com/r/C_Programming/comments/10avpa6/
// should_i_end_a_dynamically_allocated_array_with_a/
// WARNING: ALWAYS USE `malloc(len + 1)` 
// AND APPEND `'\0'` AT THE END OF `dest`. WHEN COPY STRING.

/*
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, const char *argv[])
{
	char	*str;

	alarm(5);
	if (argc == 1)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		str = (char *)ft_calloc(30, 1);
		if (!str)
			write(1, "NULL", 4);
		else
			write(1, str, 30);
	}
	return (0);
}
*/

/*

int	f_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

char	*my_strdup(const char *s)
{
	char	*y;
	size_t	i;
	size_t	len;

	len = f_strlen(s);
	y = (char *)ft_calloc(len + 1, 1);
	if (y == NULL)
		return (y);
	i = 0;
	while (i < len)
	{
		*(y + i) = *(s + i);
		i += 1;
	}
	*(y + i) = '\0';
	return (y);
}

char	*th_strdup(const char *s)
{
	char	*y;
	size_t	i;
	size_t	len;

	len = f_strlen(s);
	y = (char *)calloc(len + 1, 1);
	if (y == NULL)
		return (y);
	i = 0;
	while (i < len)
	{
		*(y + i) = *(s + i);
		i += 1;
	}
	*(y + i) = '\0';
	return (y);
}

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(int av, char **ac)
{
	char	*eiganv;

	if (av < 2)
		return (0);
	eiganv = *(ac + 1);
	write(1, my_strdup(eiganv), f_strlen(eiganv));
	write(1, "\n", 1);
	write(1, th_strdup(eiganv), f_strlen(eiganv));
	write(1, "\n", 1);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------
/*
#include <unistd.h>

int	main(void)
{
	void	*p;
	// void	*q;

	p = ft_calloc(-2147483647, 2147483647);
	// q = calloc(0, 0);
	if (p == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "NO\n", 3);
	return (0);
}
*/