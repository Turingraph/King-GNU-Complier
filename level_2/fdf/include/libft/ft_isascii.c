/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:40:58 by phsottat          #+#    #+#             */
/*   Updated: 2025/08/25 17:47:04 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
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

int	ft_strlen(char *str)
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
	len = ft_strlen(*(ac + 1));
	while (i < len)
	{
		x = *(*(ac + 1) + i);
		write(1, &x, 1);
		write(1, ": ", 2);
		display_int(isascii(x));
		// write(1, " = ", 3);
		// display_int(ft_isalpha(x));
		write(1, "\n", 1);
		i += 1;
	}
	return (0);
}
*/
