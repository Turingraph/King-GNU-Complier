/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:29:52 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/01 16:40:10 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ('a' <= c && c <= 'z')
		return (8);
	else if ('A' <= c && c <= 'Z')
		return (8);
	else if ('0' <= c && c <= '9')
		return (8);
	return (0);
}

/*

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	display_int(int x)
{
	int		d;
	char	coef;

	if (x == 0)
		write(1, "0", 1);
	else
	{
		d = 1;
		while (d < x)
			d *= 10;
		if (d > x)
			d /= 10;
		while (d > 0)
		{
			coef = x / d + '0';
			write(1, &coef, 1);
			x = x % d;
			d /= 10;
		}
	}
}

int	f_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i += 1;
	return (i);
}

int	main(int av, char **ac)
{
	char	x;
	int		len;
	int		i;

	if (av < 2)
		return (0);
	i = 0;
	len = f_strlen(*(ac + 1));
	while (i < len)
	{
		x = *(*(ac + 1) + i);
		write(1, &x, 1);
		write(1, ": ", 2);
		display_int(isalnum(x));
		write(1, " = ", 3);
		display_int(ft_isalnum(x));
		write(1, "\n", 1);
		i += 1;
	}
	return (0);
}
*/

//----------------------------------------------------------------------------

// 42 Coding School assignment, libft, page 9

/*
Some of the function prototypes you need to reimplement use the
’restrict’ qualifier.
*/

/*
// test.c

// Compile this, to test if library and file works as expected.
// >>>	cc -o test test.c libft.a
// >>>	./test Zutomayo_Yorushika_TopoligicalSpace_MetricSpace___VectorSpace _
#include "libft.h"

size_t	test_split_len(char const *s, char c)
{
	size_t	y;
	size_t	i;

	y = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			while (*(s + i) == c)
				i += 1;
			if (*(s + i) != '\0')
				y += 1;
		}
		else
		{
			if (y == 0)
				y += 1;
			while (*(s + i) != c && *(s + i) != '\0')
				i += 1;
		}
	}
	return (y);
}

int	main(int av, char **ac)
{
	size_t	len;
	size_t	i;
	char	**y;

	if (av < 3)
		return (0);
	len = test_split_len(*(ac + 1), **(ac + 2));
	ft_putnbr_fd(len, 1);
	write(1, "\n", 1);
	y = ft_split(*(ac + 1), **(ac + 2));
	if (y == NULL || len == 0)
	{
		write(1, "NULL\n", 5);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		write(1, *(y + i), ft_strlen(*(y + i)));
		write(1, "\n", 1);
		i += 1;
	}
	i = 0;
	while (i < len)
	{
		free(*(y + i));
		i += 1;
	}
	free(y);
	return (0);
}
*/
