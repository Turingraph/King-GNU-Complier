/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 22:08:38 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 10:56:39 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*y;

	i = f_strlen(s);
	while (i > 0)
	{
		y = (char *)(s + i);
		if (*(s + i) == c)
			return (y);
		i -= 1;
	}
	return (0);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

/*
// The f_strlen(s)-th char of s is '\0'
i = f_strlen(s) - 1;
...
// This is used in case where c >= 256
if (c >= 256)
	c = c % 256;
...
// If c == '\0' return the last char of y.
if (c == '\0')
	return ((char *)(s + i + 1));
...
// We can to reaverse s from last to first 0-th char.
while (i >= 0)
...
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*y;

	i = f_strlen(s) - 1;
	if (c >= 256)
		c = c % 256;
	if (c == '\0')
		return ((char *)(s + i + 1));
	while (i >= 0)
	{
		y = (char *)(s + i);
		if (*(s + i) == c)
			return (y);
		i -= 1;
	}
	return (0);
}

/*
	write(1, "*** Test ***\n", 13);
	while (i >= 0)
	{
		write(1, (s + i), 1);
		write(1, "\n", 1);
		y = (char *)(s + i);
		if (*(s + i) == c)
			return (y);
		i -= 1;
	}
	write(1, "-------\n", 8);
*/

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <string.h>
#include <unistd.h>
*/

/*

int	main(int av, char **ac)
{
	char	*my_y;
	char	*th_y;

	if (av < 3)
		return (0);
	my_y = ft_strrchr(*(ac + 1), **(ac + 2));
	th_y = strrchr(*(ac + 1), **(ac + 2));
	if (my_y == NULL || th_y == NULL)
	{
		if (my_y == NULL)
			write(1, "my_y == NULL\n", 13);
		if (th_y == NULL)
			write(1, "th_y == NULL\n", 13);
		return (0);
	}
	write(1, my_y, f_strlen(my_y));
	write(1, "\n", 1);
	write(1, th_y, f_strlen(th_y));
	write(1, "\n", 1);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
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

int	main(void)
{
	char		*str;
	char		str2[] = "bonjour";

	// if (!(str = ft_strrchr(str2, '\0')))
	// if (!(str = ft_strrchr(str2, 'b')))
	// if (!(str = ft_strrchr(str2, 'o')))
	if (!(str = ft_strrchr(str2, '\0')))
		write(1, "NULL\n", 5);
	else
	{
		write(1, str, strlen(str));
		write(1, "\n", 1);
		if (str != str2 + 7)
			write(1, "Return value is false\n", 23);
	}
	return (0);
}
*/
