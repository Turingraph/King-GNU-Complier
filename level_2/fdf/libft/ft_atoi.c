/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:22:13 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:03:07 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

/*
int	f_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	y;
	char	s;
	char	i;

	i = 0;
	s = 1;
	y = 0;
	if (*(nptr + 0) == '-')
	{
		s *= -1;
		i += 1;
	}
	while (*(nptr + i) != '\0' && f_isdigit(*(nptr + i)) != 0)
	{
		y += *(nptr + i) - '0';
		if (i > 11)
			return (0);
		i += 1;
		y *= 10;
	}
	y /= 10;
	y *= (long) s;
	if (y > 2147483647 || y < -2147483648)
		return (0);
	return (y);
}
*/

// 2^{8 * 4 - 1} = 2147483648

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

#include <stdlib.h>

int	f_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	negative_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

long	calculate_y(const char *nptr, size_t i, char s)
{
	size_t	first_i;
	long	y;

	y = 0;
	first_i = i;
	while (*(nptr + i) != '\0' && f_isdigit(*(nptr + i)) != 0)
	{
		y += *(nptr + i) - '0';
		if (i - first_i > 11)
			return (0);
		i += 1;
		y *= 10;
	}
	y /= 10;
	y *= (long) s;
	if (y > 2147483647 || y < -2147483648)
		return (0);
	return (y);
}

char	f_isspace(char s)
{
	if (s == ' '
		|| s == '\t'
		|| s == '\n'
		|| s == '\v'
		|| s == '\f'
		|| s == '\r')
	{
		return (1);
	}
	return (0);
}

/*
I add
1.	f_isspace(*(nptr + i)) == 1
2.	if (*(nptr + i) == '-' || *(nptr + i) == '+')
*/

int	ft_atoi(const char *nptr)
{
	char	s;
	size_t	i;

	i = 0;
	s = 1;
	while (f_isspace(*(nptr + i)) == 1)
		i += 1;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		s *= negative_sign(*(nptr + i));
		i += 1;
	}
	return (calculate_y(nptr, i, s));
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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

/*
int	main(int av, char **ac)
{
	if (av < 2)
		return (0);
	// printf("%d\n",atoi(*(ac + 1)));
	display_int_sign(ft_atoi(*(ac + 1)));
	write(1, "\n", 1);
	display_int_sign(atoi(*(ac + 1)));
	write(1, "\n", 1);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
int main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc < 3)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if ((arg = atoi(argv[2])) == 1)
			display_int_sign(1, atoi("+548"));
		else
			display_int_sign(1, ft_atoi("+548"));
	}
	else if (arg == 2)
	{
		if ((arg = atoi(argv[2])) == 1)
			display_int_sign(1, atoi("+47+5"));
		else
			display_int_sign(1, ft_atoi("+47+5"));
	}
	else if (arg == 3)
	{
		if ((arg = atoi(argv[2])) == 1)
			display_int_sign(1, atoi("\t\n\r\v\f  469 \n"));
		else
			display_int_sign(1, ft_atoi("\t\n\r\v\f  469 \n"));
	}
	else if (arg == 4)
	{
		if ((arg = atoi(argv[2])) == 1)
			display_int_sign(1, atoi("\n\n\n  -46\b9 \n5d6"));
		else
			display_int_sign(1, ft_atoi("\n\n\n  -46\b9 \n5d6"));
	}
	return (0);
}
*/
