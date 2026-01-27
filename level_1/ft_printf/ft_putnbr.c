/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:51:44 by phsottat          #+#    #+#             */
/*   Updated: 2026/01/27 16:13:39 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i += 1;
	return (i);
}

int	print_int(unsigned long num, char *base)
{
	unsigned long	d;
	int				y;
	char			coef;

	d = 1;
	while (d < num)
	{
		d *= ft_strlen(base);
	}
	if (d > num)
		d /= ft_strlen(base);
	y = 0;
	while (d > 0)
	{
		coef = *(base + (num / d));
		write(1, &coef, 1);
		num %= d;
		d /= ft_strlen(base);
		y += 1;
	}
	return (y);
}

int	ft_putnbr(long long num, char *base)
{
	if (num == 0)
	{
		write(1, base, 1);
		return (1);
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		return (1 + print_int((unsigned long)(num * (-1)), base));
	}
	else
		return (print_int(num, base));
}

int	print_large(long long input, char *base)
{
	unsigned long long	d;
	char				coef;
	int					i;
	char				first_0;

	first_0 = 0;
	d = 18446744073709551615u / 16 + 1;
	i = 0;
	while (d > 0)
	{
		coef = *(base + (input / d));
		if (first_0 != 0 || coef != '0')
		{
			write(1, &coef, 1);
			first_0 = 1;
			i += 1;
		}
		input %= d;
		d /= ft_strlen(base);
	}
	return (i);
}

int	print_pointer(long long input)
{
	if (input == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (print_large(input, "0123456789abcdef") + 2);
}
