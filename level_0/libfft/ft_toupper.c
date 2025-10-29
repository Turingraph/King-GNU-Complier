/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:25:12 by phsottat          #+#    #+#             */
/*   Updated: 2025/08/30 14:56:16 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

/*
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
		x = ft_toupper(*(*(ac + 1) + i));
		write(1, &x, 1);
		i += 1;
	}
	write(1, "\n", 1);
	return (0);
}
*/
