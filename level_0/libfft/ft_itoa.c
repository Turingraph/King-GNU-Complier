/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:50:08 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:13:37 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//------------------------------------------------
// *** TESTING FUNCTION ***
//------------------------------------------------
/*
#include <unistd.h>

size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

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
// must return (11);
size_t	append_strint_small(char *y, char active)
{
	if (active == 1)
	{
		*(y + 0) = '-';
		*(y + 1) = '2';
		*(y + 2) = '1';
		*(y + 3) = '4';
		*(y + 4) = '7';
		*(y + 5) = '4';
		*(y + 6) = '8';
		*(y + 7) = '3';
		*(y + 8) = '6';
		*(y + 9) = '4';
		*(y + 10) = '8';
		*(y + 11) = '\0';
	}
	return (10);
}

size_t	append_strint(int x, char *y, size_t sign, char active)
{
	long	d;
	long	xx;
	size_t	len;
	char	coef;

	xx = (long) x;
	len = 0;
	d = 1;
	while (d < xx)
		d *= 10;
	if (d > xx)
		d /= 10;
	while (d > 0)
	{
		coef = xx / d + (long) '0';
		if (active == 1)
			*(y + sign + len) = coef;
		xx = xx % d;
		d /= 10;
		len += 1;
	}
	if (active == 1)
		*(y + sign + len) = '\0';
	return (len);
}

// Return the size of string, exclude '\0'.

size_t	append_strint_sign(int x, char *y, char active)
{
	if (x == 0)
	{
		if (active == 1)
		{
			*y = '0';
			*(y + 1) = '\0';
		}
		return (1);
	}
	else if (x > 0)
		return (append_strint(x, y, 0, active));
	else if (x == -2147483648)
		return (append_strint_small(y, active));
	else
	{
		if (active == 1)
			*y = '-';
		return (1 + append_strint(x * (-1), y, 1, active));
	}
}

char	*ft_itoa(int n)
{
	char	*y;

	y = malloc((append_strint_sign(n, NULL, 0) + 1) * sizeof(char));
	if (y == NULL)
		return (y);
	append_strint_sign(n, y, 1);
	return (y);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

size_t	append_strint_small(char *y, char active)
{
	if (active == 1)
	{
		*(y + 0) = '-';
		*(y + 1) = '2';
		*(y + 2) = '1';
		*(y + 3) = '4';
		*(y + 4) = '7';
		*(y + 5) = '4';
		*(y + 6) = '8';
		*(y + 7) = '3';
		*(y + 8) = '6';
		*(y + 9) = '4';
		*(y + 10) = '8';
		*(y + 11) = '\0';
	}
	return (11);
}

size_t	append_strint(int x, char *y, size_t sign, char active)
{
	long	d;
	long	xx;
	size_t	len;
	char	coef;

	xx = (long) x;
	len = 0;
	d = 1;
	while (d < xx)
		d *= 10;
	if (d > xx)
		d /= 10;
	while (d > 0)
	{
		coef = xx / d + (long) '0';
		if (active == 1)
			*(y + sign + len) = coef;
		xx = xx % d;
		d /= 10;
		len += 1;
	}
	if (active == 1)
		*(y + sign + len) = '\0';
	return (len);
}

// Return the size of string, exclude '\0'.

size_t	append_strint_sign(int x, char *y, char active)
{
	if (x == 0)
	{
		if (active == 1)
		{
			*y = '0';
			*(y + 1) = '\0';
		}
		return (1);
	}
	else if (x > 0)
		return (append_strint(x, y, 0, active));
	else if (x == -2147483648)
		return (append_strint_small(y, active));
	else
	{
		if (active == 1)
			*y = '-';
		return (1 + append_strint(x * (-1), y, 1, active));
	}
}

char	*ft_itoa(int n)
{
	char	*y;

	y = malloc((append_strint_sign(n, NULL, 0) + 1) * sizeof(char));
	if (y == NULL)
		return (y);
	append_strint_sign(n, y, 1);
	return (y);
}

	// write(1, "len(y) = ", 9);
	// display_int_sign(1, (append_strint_sign(n, NULL, 0) + 1));
	// write(1, "\n", 1);

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

// 2147483647
/*
int	main(int av, char **ac)
{
	int		x;
	char	*y;

	if (av < 2)
		return (0);
	x = atoi(*(ac + 1));
	y = ft_itoa(x);
	write(1, y, f_strlen(y));
	write(1, "\n", 1);
	display_int_sign(1, x);
	write(1, "\n", 1);
	free(y);
	return (0);
}
*/
//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
int	main(void)
{
	char	*y;

	y = ft_itoa(-2147483648LL);
	write(1, y, f_strlen(y));
	write(1, "\n", 1);
	display_int_sign(1, -2147483648LL);
	write(1, "\n", 1);
	if (f_strlen(y) == 11)
		write(1, "Coffee\n", 7);
	free(y);
	return (0);
}
*/
