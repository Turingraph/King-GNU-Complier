/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:26:16 by phsottat          #+#    #+#             */
/*   Updated: 2025/08/30 21:43:21 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (2048);
	return (0);
}

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
	while (i < len)
	{
		x = *(*(ac + 1) + i);
		write(1, &x, 1);
		write(1, ": ", 2);
		display_int(isdigit(x));
		write(1, " = ", 3);
		display_int(ft_isdigit(x));
		write(1, "\n", 1);
		i += 1;
	}
	return (0);
}
*/
