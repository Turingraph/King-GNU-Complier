/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 22:27:47 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 19:31:38 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//------------------------------------------------
// *** TESTING FUNCTION ***
//------------------------------------------------
/*
#include <unistd.h>
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

// Use `while (i < n - 1)` instead of `while (i < n)`
// because it compares only the first (at most) n bytes of s1 and s2.
// we already compare the last byte of s1 and s2 in the last line.

/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i += 1;
	}
	return (*(s1 + i) - *(s2 + i));
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && *(s1 + i) == *(s2 + i))
		i += 1;
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
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
	if (av < 3)
		return (0);
	if (f_strlen(*(ac + 1)) < 5 || f_strlen(*(ac + 2)) < 5)
		return (0);
	display_int_sign(ft_strncmp(*(ac + 1), *(ac + 2), 5));
	write(1, "\n", 1);
	display_int_sign(strncmp(*(ac + 1), *(ac + 2), 5));
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
	display_int_sign(1, ft_strncmp("test\200", "test\0", 6));
	write(1, "\n", 1);
	display_int_sign(1, strncmp("test\200", "test\0", 6));
	write(1, "\n", 1);

	// display_int_sign(1, ft_strncmp("test\41", "test\50", 6));
	// write(1, "\n", 1);
	// display_int_sign(1, strncmp("test\41", "test\50", 6));
	// write(1, "\n", 1);
	return (0);
}
*/
