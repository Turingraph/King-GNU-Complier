/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 22:08:05 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 10:59:33 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//------------------------------------------------
// *** TESTING FUNCTION ***
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*y;
	size_t	i;

	if (start > f_strlen(s))
		return (NULL);
	y = (char *)malloc(len + 1);
	if (y == NULL)
		return (y);
	i = 0;
	while (i < len && *(s + start + i) != '\0')
	{
		*(y + i) = *(s + start + i);
		i += 1;
	}
	*(y + i) = '\0';
	return (y);
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

size_t	len_substr(char const *s, unsigned int start, size_t len)
{
	size_t	y;

	y = 0;
	while (y < len && *(s + start + y) != '\0')
		y += 1;
	return (y);
}

/*
// Return "\0" instead of NULL if possible to do so,
// because "\0" is string, but NULL is not string.
if (start >= f_strlen(s))
{
	y = (char *)malloc(sizeof(char) * 1);
	if (y == NULL)
		return (y);
	*y = '\0';
	return (y);
}
...
// Use `len_substr` instead of `len` to avoid using memory than
// it needed, for example
// ft_substr("Nujabes", 3, 20) = "abes" which use 5 bytes instead of 20 bytes.
y = (char *)malloc(sizeof(char) * (len_substr(s, start, len) + 1))
...
// Loop len_substr(s, start, len) chars instead of strlen(s) - start chars.
while (i < len_substr(s, start, len))
...
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*y;
	size_t	i;

	if (start >= f_strlen(s))
	{
		y = (char *)malloc(sizeof(char) * 1);
		if (y == NULL)
			return (y);
		*y = '\0';
		return (y);
	}
	y = (char *)malloc(sizeof(char) * (len_substr(s, start, len) + 1));
	if (y == NULL)
		return (y);
	i = 0;
	while (i < len_substr(s, start, len))
	{
		*(y + i) = *(s + start + i);
		i += 1;
	}
	*(y + i) = '\0';
	return (y);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(int av, char **ac)
{
	char	*y;

	if (av < 2)
		return (0);
	y = ft_substr(*(ac + 1), 5, 10);
	if (y == NULL)
	{
		write(1, "NULL\n", 5);
		return (0);
	}
	write(1, y, f_strlen(y));
	write(1, "\n", 1);
	free(y);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char	*bullshit;
	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;

	if (!(strsub = ft_substr(str, 400, 20)))
		write(1, "NULL\n", 5);
	else
	{
		bullshit = (char *)&strsub[30];
		bullshit = "FULL BULLSHIT";
		if (strsub)
			write(1, strsub, strlen(strsub));
		else
			write(1, "rip\n", 4);
	}
	if (str == strsub)
		write(1, "\nA new string was not returned\n", 32);
	(void)bullshit;
	return (0);
}
*/

//------------------------------------------------
// *** LIB TESTER TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	main(int av, char **ac)
{
	int		arg;
	char	*s;
	char	*str;

	if (av == 1)
		return (0);
	arg = atoi(ac[1]);
	if (arg == 2)
	{
		s = ft_substr("tripouille", 0, 42000);
		write(1, "STATUS:\t", 8);
		if (strlen(s) + 1 == strlen("tripouille") + 1)
			write(1, "OK", 2);
		else
			write(1, "NO", 2);
		write(1, "\n", 1);
		display_int_sign(1, strlen(s));
		write(1, "\n", 1);
	}
	if (arg == 5)
	{
		s = ft_substr("tripouille", 100, 1);
		write(1, "STATUS:\t", 8);
		if (strcmp(s, "") == 0)
			write(1, "OK", 2);
		else
			write(1, "NO", 2);
		write(1, "\n", 1);
		write(1, s, strlen(s));
		write(1, "\n", 1);
	}
	if (arg == 6)
	{
		s = ft_substr("tripouille", 100, 1);
		write(1, "STATUS:\t", 8);
		if (strlen(s) + 1 == 1)
			write(1, "OK", 2);
		else
			write(1, "NO", 2);
		write(1, "\n", 1);
		display_int_sign(1, strlen(s));
		write(1, "\n", 1);
	}
	if (arg == 8)
	{
		str = strdup("1");
		s = ft_substr(str, 42, 42000000);
		write(1, "STATUS:\t", 8);
		if (strlen(s) + 1 == 1)
			write(1, "OK", 2);
		else
			write(1, "NO", 2);
		free(str);
		write(1, "\n", 1);
		display_int_sign(1, strlen(s));
		write(1, "\n", 1);
	}
	if (arg == 10)
	{
		str = strdup("0123456789");
		s = ft_substr(str, 9, 10);
		write(1, "STATUS:\t", 8);
		if (strlen(s) + 1 == 2)
			write(1, "OK", 2);
		else
			write(1, "NO", 2);
		free(str);
		write(1, "\n", 1);
		display_int_sign(1, strlen(s));
		write(1, "\n", 1);
	}
	free(s);
	return (0);
}
*/
