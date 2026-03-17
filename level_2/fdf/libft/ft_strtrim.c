/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:17:43 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/17 15:09:51 by phsottat         ###   ########.fr       */
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
// size_t	f_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*(s + i) != '\0')
// 		i += 1;
// 	return (i);
// }

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

// i = j = 0
size_t	trim_strlen(char const *s1, char const *set, size_t i, size_t j)
{
	size_t	trim;
	size_t	y;

	trim = 0;
	y = 0;
	while (*(s1 + i + trim) != '\0')
	{
		if ((i == 0 || i + trim == f_strlen(s1) - f_strlen(set))
			&& *(s1 + i + trim) == *(set + j) && f_strlen(set) <= f_strlen(s1))
		{
			while (*(set + j) != '\0' && *(s1 + i + trim + j) == *(set + j))
				j += 1;
			if (j == f_strlen(set))
				trim += j;
		}
		else
		{
			y += 1;
			i += 1;
		}
	}
	return (y);
}

void	ft_strtrim_loop(char const *s1, char const *set, char *y)
{
	size_t	i;
	size_t	j;
	size_t	trim;

	i = 0;
	trim = 0;
	while (*(s1 + i + trim) != '\0')
	{
		j = 0;
		if ((i == 0 || i + trim == f_strlen(s1) - f_strlen(set))
			&& *(s1 + i + trim) == *(set + j) && f_strlen(set) <= f_strlen(s1))
		{
			while (*(set + j) != '\0' && *(s1 + i + trim + j) == *(set + j))
				j += 1;
			if (j == f_strlen(set))
				trim += j;
		}
		else
		{
			*(y + i) = *(s1 + i + trim);
			i += 1;
		}
	}
	*(y + i + trim) = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*y;

	y = (char *)malloc(trim_strlen(s1, set, 0, 0) + 1);
	if (y == NULL)
		return (y);
	ft_strtrim_loop(s1, set, y);
	return (y);
}
*/

//------------------------------------------------
// *** 2DN WRONG VERSION ***
//------------------------------------------------

/*
size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i += 1;
	}
	return (i);
}

size_t	trim_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	y;

	y = 0;
	i = 0;
	while (*(s1 + i) != '\0')
	{
		j = 0;
		if (*(s1 + i) == *(set + j))
		{
			while (*(s1 + i + j) == *(set + j) && *(set + j) != '\0')
				j += 1;
		}
		if ((*(set + j) == '\0' && i == 0)
			|| (*(set + j) == '\0' && *(s1 + i + j) == '\0' && i != 0))
			i += j;
		else
		{
			i += 1;
			y += 1;
		}
	}
	return (y);
}

// i = 0;
void	trim_loop(char const *s1, char const *set, char *yy, size_t i)
{
	size_t	j;
	size_t	y;

	y = 0;
	while (*(s1 + i) != '\0')
	{
		j = 0;
		if (*(s1 + i) == *(set + j))
		{
			while (*(s1 + i + j) == *(set + j) && *(set + j) != '\0')
				j += 1;
		}
		if ((*(set + j) == '\0' && i == 0)
			|| (*(set + j) == '\0' && *(s1 + i + j) == '\0' && i != 0))
			i += j;
		else
		{
			*(yy + y) = *(s1 + i);
			i += 1;
			y += 1;
		}
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*y;

	y = (char *)malloc(trim_len(s1, set) + 1);
	if (y == NULL)
		return (y);
	trim_loop(s1, set, y, 0);
	return (y);
}
*/

//------------------------------------------------
// *** 3RD WRONG VERSION ***
//------------------------------------------------

/*
size_t	trim_loop(char const *s1, char const *set, char *yy, char act)
{
	size_t	y;
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	y = 0;
	while (*(s1 + i) != '\0')
	{
		c = 0;
		j = 0;
		while (*(set + j) != '\0' && c == 0)
		{
			if (*(s1 + i) == *(set + j))
				c = 1;
			j += 1;
		}
		if (c == 0)
		{
			if (act == 1)
				*(yy + y) = *(s1 + i);
			y += 1;
		}
		i += 1;
	}
	return (y);
}
*/

//------------------------------------------------
// *** 4TH WRONG VERSION ***
//------------------------------------------------
/*
size_t	trim_len(char const *s1, char const *set)
{
	size_t	y;
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	y = 0;
	while (*(s1 + i) != '\0')
	{
		c = 0;
		j = 0;
		while (*(set + j) != '\0' && c == 0)
		{
			if (*(s1 + i) == *(set + j))
				c = 1;
			j += 1;
		}
		if (c == 0)
		{
			y += 1;
		}
		i += 1;
	}
	return (y);
}

size_t	trim_loop(char const *s1, char const *set, char *yy)
{
	size_t	y;
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	y = 0;
	while (*(s1 + i) != '\0')
	{
		c = 0;
		j = 0;
		while (*(set + j) != '\0' && c == 0)
		{
			if (*(s1 + i) == *(set + j))
				c = 1;
			j += 1;
		}
		if (c == 0)
		{
			*(yy + y) = *(s1 + i);
			y += 1;
		}
		i += 1;
	}
	return (y);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*y;

	y = NULL;
	y = (char *)malloc(trim_len(s1, set) + 1);
	if (y == NULL)
		return (y);
	*(y + trim_len(s1, set)) = '\n';
	trim_loop(s1, set, y);
	return (y);
}
*/
	// write(1, "len = ", 6);
	// display_int_sign(1, trim_len(s1, set));
	// write(1, "\n", 1);

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

/*
I understood the instruction incorrectly.
At first I thought I should do this.
>>> ft_strtrim("Zutomayorushika", "rushika") = "Zutomayo"
>>> ft_strtrim("Zutomayorushika", "Yorushika") = "Zutomayorushika"
>>> ft_strtrim("Zutomayorushika", "may") = "Zutomayorushika"

When using libft tester, I thought I should do this.
>>> ft_strtrim("Zutomayorushika", "rushika") = "Ztomyo"
>>> ft_strtrim("Zutomayorushika", "Yorushika") = "Ztmy"
>>> ft_strtrim("Zutomayorushika", "may") = "Zutoorushik"

It took me a while to figure out that I should do this.
>>> ft_strtrim("Zutomayorushika", "rushika") = "Zutomayo"
>>> ft_strtrim("Zutomayorushika", "Yorushika") = "Zutomay"
>>> ft_strtrim("Zutomayorushika", "may") = "Zutomayorushika"
*/

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

// find first occur index of consecutive char from set array, in s1
size_t	t_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	equal;

	i = 0;
	while (*(s1 + i) != '\0')
	{
		equal = 0;
		j = 0;
		while (*(set + j) != '\0' && equal == 0)
		{
			if (*(s1 + i) == *(set + j))
				equal = 1;
			j += 1;
		}
		if (equal == 0)
			return (i);
		i += 1;
	}
	return (i);
}

// find last occur index of consecutive char from set array, in s1
size_t	t_end(char const *s1, char const *set, int len)
{
	size_t	j;
	char	equal;
	char	stop;

	stop = 0;
	while (len >= 0)
	{
		equal = 0;
		j = 0;
		while (*(set + j) != '\0' && equal == 0 && stop == 0)
		{
			if (*(s1 + len) == *(set + j))
				equal = 1;
			j += 1;
		}
		if (equal == 0)
			return (len + 1);
		len -= 1;
	}
	return (len + 1);
}

// truncate first and last consecutive char from set array, of the string s1
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*y;
	size_t	i;
	size_t	j;
	size_t	max;

	y = NULL;
	i = t_start(s1, set);
	max = t_end(s1, set, f_strlen(s1) - 1);
	if (i >= max)
	{
		y = (char *)malloc(1);
		*y = '\0';
		return (y);
	}
	y = (char *)malloc(max - i + 1);
	if (y == NULL)
		return (y);
	j = 0;
	while (i + j < max)
	{
		*(y + j) = *(s1 + i + j);
		j += 1;
	}
	*(y + j) = '\0';
	return (y);
}

	// write(1, "max = ", 6);
	// display_int_sign(1, max);
	// write(1, "\n", 1);
	// write(1, "min = ", 6);
	// display_int_sign(1, t_start(s1, set));
	// write(1, "\n", 1);

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
// DEBUGGING
void	ft_strtrim_loop(char const *s1, char const *set, char *y)
{
	size_t	i;
	size_t	j;
	size_t	trim;

	i = 0;
	trim = 0;
	write(1, "*** Test ***\n", 13);
	while (*(s1 + i + trim) != '\0')
	{
		j = 0;
		if ((i == 0 || i + trim == f_strlen(s1) - f_strlen(set))
			&& *(s1 + i + trim) == *(set + j) && f_strlen(set) <= f_strlen(s1))
		{
			while (*(set + j) != '\0' && *(s1 + i + trim + j) == *(set + j))
				j += 1;
			if (j == f_strlen(set))
				trim += j;
		}
		else
		{
			write(1, (s1 + i + trim), 1);
			write(1, "\n", 1);
			*(y + i) = *(s1 + i + trim);
			i += 1;
		}
	}
	write(1, "-----\n", 6);
	write(1, "i = ", 4);
	display_int(i);
	write(1, "\n", 1);
	*(y + i + trim) = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*y;

	y = (char *)malloc(trim_strlen(s1, set, 0, 0) + 1);
	write(1, "len(y1) = ", 10);
	display_int(trim_strlen(s1, set, 0, 0));
	write(1, "\n", 1);
	if (y == NULL)
		return (y);
	ft_strtrim_loop(s1, set, y);
	return (y);
}
*/
/*
#include <stdio.h>

int	main(int av, char **ac)
{
	char	*y;

	if (av < 3)
		return (0);
	y = ft_strtrim(*(ac + 1), *(ac + 2));
	if (y == NULL)
	{
		write(1, "NULL\n", 5);
		return (0);
	}
	write(1, "len(y) = ", 9);
	display_int(1, f_strlen(y));
	write(1, "\n", 1);
	write(1, y, f_strlen(y));
	write(1, "\n", 1);
	free(y);
	return (0);
}
*/
/*
cc -Wall -Wextra -Werror ft_strtrim.c
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------
/*
int		main(int argc, const char *argv[])
{
	char	*strtrim;
	int		arg;

	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	strtrim = NULL;
	if (arg == 1)
	{
		char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
		if (!(strtrim = ft_strtrim(s1, " ")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 2)
	{
		char s1[] = "lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "te")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 3)
	{
		char s1[] = " lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "l ")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 4)
	{
		char s1[] = "lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "tel")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 5)
	{
		char s1[] = "   xax   xax";
		if (!(strtrim = ft_strtrim(s1, " xa")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 6)
	{
		char s1[] = "";
		if (!(strtrim = ft_strtrim(s1, "123")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 7)
	{
		char s1[] = "123";
		if (!(strtrim = ft_strtrim(s1, "")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 8)
	{
		char s1[] = "";
		if (!(strtrim = ft_strtrim(s1, "")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 9)
	{
		char s1[] = "abcdba";
		if (!(strtrim = ft_strtrim(s1, "acb")))
			write(1, "NULL", 4);
		else
			write(1, strtrim, strlen(strtrim));
		if (strtrim == s1)
			write(1, "\nA new string was not returned", 30);
	}
	// else if (arg == 5)
	// {
	// 	char s1[] = "          ";
	// 	if (!(strtrim = ft_strtrim(s1, " ")))
	// 		write(1, "NULL", 4);
	// 	else
	// 		write(1, strtrim, strlen(strtrim));
	// 	if (strtrim == s1)
	// 		write(1, "\nA new string was not returned", 30);
	// }
	free(strtrim);
	// write(1, "\n", 1);
	return (0);
}
*/