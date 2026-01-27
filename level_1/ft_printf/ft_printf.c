/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:09:21 by phsottat          #+#    #+#             */
/*   Updated: 2026/01/27 16:13:36 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(int input)
{
	write(1, &input, 1);
	return (1);
}

int	print_string(char *input)
{
	if (input == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, input, ft_strlen(input));
	return (ft_strlen(input));
}

long int	get_unsign(int input)
{
	if (input > -1)
		return (input);
	return (4294967296 + input);
}

int	print_percent(char sign, va_list input)
{
	if (sign == '\0')
		return (0);
	if (sign == '%')
		return (write(1, "%%", 1));
	if (sign == 'c')
		return (print_character(va_arg(input, int)));
	if (sign == 's')
		return (print_string(va_arg(input, char *)));
	if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(input, int), "0123456789"));
	if (sign == 'u')
		return (ft_putnbr(va_arg(input, unsigned int), "0123456789"));
	if (sign == 'x')
		return (ft_putnbr(get_unsign(va_arg(input, int)), "0123456789abcdef"));
	if (sign == 'X')
		return (ft_putnbr(get_unsign(va_arg(input, int)), "0123456789ABCDEF"));
	if (sign == 'p')
		return (print_pointer(va_arg(input, long long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		y;
	int		i;
	va_list	input;

	va_start(input, str);
	y = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '%')
		{
			y += print_percent(*(str + i + 1), input);
			i += 1;
		}
		else
			y += write(1, str + i, 1);
		i += 1;
	}
	va_end(input);
	return (y);
}

/*
https://stackoverflow.com/questions/1562992/
best-way-to-store-a-va-list-for-later-use-in-c-c
*/
