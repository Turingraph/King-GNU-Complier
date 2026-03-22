/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:11:56 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 11:01:32 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*y;
	size_t	i;

	y = (char *)malloc(f_strlen(s) + 1);
	if (y == NULL)
		return (y);
	i = 0;
	while (i < f_strlen(s))
	{
		*(y + i) = f((unsigned int) i, *(s + i));
		i += 1;
	}
	*(y + i) = '\0';
	return (y);
}

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	display_int(int x)
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
		write(1, &coef, 1);
		x = x % d;
		d /= 10;
	}
}

void	display_int_sign(int x)
{
	if (x == 0)
	{
		write(1, "0", 1);
	}
	else if (x > 0)
	{
		display_int(x);
	}
	else if (x == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		write(1, "-", 1);
		display_int((-1) * x);
	}
}

char	f_toupper(unsigned int j, char c)
{
	write(1, "j = ", 4);
	display_int_sign((int) j);
	write(1, "\n", 1);
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

// https://stackoverflow.com/questions/9410/
// how-do-you-pass-a-function-as-a-parameter-in-c

int	main(int av, char **ac)
{
	char	*y;

	if (av < 2)
		return (0);
	y = ft_strmapi(*(ac + 1), f_toupper);
	if (y == NULL)
	{
		write(1, "NULL\n", 1);
		return (0);
	}
	write(1, y, f_strlen(*(ac + 1)));
	write(1, "\n", 1);
	return (0);
}
*/
