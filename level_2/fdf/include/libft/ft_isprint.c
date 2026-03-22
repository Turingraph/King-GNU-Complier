/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:41:55 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:06:50 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.ascii-code.com/
// https://stackoverflow.com/questions/14647979/
// is-it-possible-to-print-non-printing-characters-with-a-c-specifier

//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

/*
int	ft_isprint(int c)
{
	if (32 <= c && c <= 127)
		return (16384);
	return (0);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

/*
127 is not printable char.
*/

int	ft_isprint(int c)
{
	if (32 <= c && c < 127)
		return (16384);
	return (0);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

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
	if (len < 5)
		return (0);
	*(*(ac + 1) + 1) = '\v';
	*(*(ac + 1) + 2) = '\n';
	*(*(ac + 1) + 3) = '\t';
	*(*(ac + 1) + 4) = '\r';
	while (i <= len)
	{
		x = *(*(ac + 1) + i);
		display_int(isprint(x));
		write(1, " = ", 3);
		display_int(ft_isprint(x));
		write(1, "\n", 1);
		i += 1;
	}
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------
