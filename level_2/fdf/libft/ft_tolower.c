/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:33:44 by phsottat          #+#    #+#             */
/*   Updated: 2025/08/30 14:56:07 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 'a');
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
		x = ft_tolower(*(*(ac + 1) + i));
		write(1, &x, 1);
		i += 1;
	}
	write(1, "\n", 1);
	return (0);
}
*/

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

int	main()//int av, char **acc)
{
	char	x;
	int		len;
	int		i;
	char	ac[15] = "\t\t\nfgAABd43\tCCD";
	// if (av < 2)
	// 	return (0);
	i = 0;
	len = f_strlen(ac);
	while (i < len)
	{
		x = ft_tolower(*(ac + i));
		write(1, &x, 1);
		i += 1;
	}
	write(1, "\n", 1);
	i = 0;
	while (i < len)
	{
		x = tolower(*(ac + i));
		write(1, &x, 1);
		i += 1;
	}
	write(1, "\n", 1);
	return (0);
}
*/
