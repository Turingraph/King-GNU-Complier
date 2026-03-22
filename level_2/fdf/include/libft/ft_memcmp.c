/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:49:31 by phsottat          #+#    #+#             */
/*   Updated: 2025/08/31 16:57:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*g1;
	unsigned char	*g2;

	if (n == 0)
		return (0);
	i = 0;
	g1 = (unsigned char *)(s1 + 0);
	g2 = (unsigned char *)(s2 + 0);
	while (i < n)
	{
		g1 = (unsigned char *)(s1 + i);
		g2 = (unsigned char *)(s2 + i);
		if (*g1 != *g2)
			return (*g1 - *g2);
		i += 1;
	}
	return (*g1 - *g2);
}

/*
#include <unistd.h>
#include <string.h>

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

int	f_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

int	main(int av, char **ac)
{
	int	s;

	s = 5;
	if (av < 3)
		return (0);
	if (f_strlen(*(ac + 1)) < s || f_strlen(*(ac + 2)) < s)
		return (0);
	display_int_sign(ft_memcmp(*(ac + 1), *(ac + 2), s));
	write(1, "\n", 1);
	display_int_sign(memcmp(*(ac + 1), *(ac + 2), s));
	write(1, "\n", 1);
	return (0);
}
*/
