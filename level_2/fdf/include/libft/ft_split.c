/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:12:17 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:18:28 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdlib.h>
//------------------------------------------------
// *** SUPPORTING FUNCTION ***
//------------------------------------------------
/*
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

size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}
*/
//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

/*
size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}
*/

/*
size_t	split_len(char const *s, char c)
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

void	split_append(char const *s, char c, char **y, size_t *i)
{
	size_t	k;
	size_t	k1;

	k = *i;
	k1 = k;
	while (*(s + *i) != c && *(s + *i) != '\0')
		*i += 1;
	*y = (char *)malloc(sizeof(char) * (*i - k1 + 1));
	while (*(s + k) != c && *(s + k) != '\0')
	{
		*(*y + k - k1) = *(s + k);
		k += 1;
	}
	*(*y + k - k1) = '\0';
}

void	split_loop(char const *s, char c, char **y, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			while (*(s + i) == c)
				i += 1;
		}
		else if (j < len)
		{
			split_append(s, c, (y + j), &i);
			j += 1;
		}
		else
			i += 1;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**y;
	size_t	len;

	len = split_len(s, c);
	y = (char **)malloc(len * sizeof(char *));
	if (y == NULL)
		return (y);
	split_loop(s, c, y, len);
	return (y);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

size_t	split_len(char const *s, char c)
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

void	split_append(char const *s, char c, char **y, size_t *i)
{
	size_t	k;
	size_t	k1;

	k = *i;
	k1 = k;
	while (*(s + *i) != c && *(s + *i) != '\0')
		*i += 1;
	*y = (char *)malloc(sizeof(char) * (*i - k1 + 1));
	while (*(s + k) != c && *(s + k) != '\0')
	{
		*(*y + k - k1) = *(s + k);
		k += 1;
	}
	*(*y + k - k1) = '\0';
}

void	split_loop(char const *s, char c, char **y, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			while (*(s + i) == c)
				i += 1;
		}
		else if (j < len)
		{
			split_append(s, c, (y + j), &i);
			j += 1;
		}
		else
			i += 1;
	}
}

/*
y = (char **)malloc((len + 1) * sizeof(char *));
because the last item of y should be NULL.

"""
Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter. The array must
end with a NULL pointer.
""" by 42.
*/

char	**ft_split(char const *s, char c)
{
	char	**y;
	size_t	len;

	len = split_len(s, c);
	y = (char **)malloc((len + 1) * sizeof(char *));
	if (y == NULL)
		return (y);
	split_loop(s, c, y, len);
	*(y + len) = NULL;
	return (y);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------
/*
#include <stdio.h>

int	main(int av, char **ac)
{
	size_t	len;
	size_t	i;
	char	**y;

	if (av < 3)
		return (0);
	len = split_len(*(ac + 1), **(ac + 2));
	write(1, "len = ", 6);
	display_int_sign(1, len);
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
		write(1, *(y + i), f_strlen(*(y + i)));
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
//-----------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
#include <unistd.h>

int	main(void)
{
	char	**tabstr;

	if (!(tabstr = ft_split("", 'z')))
		write(1, "NULL\n", 5);
	else
	{
		if (!tabstr[0])
			write(1, "ok\n", 3);
		else
			write(1, "NO\n", 3);
	}
	return (0);
}
*/

//------------------------------------------------
// *** LIBFT TESTER TEST ***
//------------------------------------------------

/*
int	main(void)
{
	return (0);
}
*/
