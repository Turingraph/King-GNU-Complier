/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:00:28 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/17 15:16:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int av, char **ac)
{
	char	*y;
	int		len_y;

	if (av < 3)
		return (0);
	y = ft_strtrim(*(ac + 1), *(ac + 2));
	if (y == NULL)
	{
		write(1, "NULL\n", 5);
		return (0);
	}
	write(1, "len(y) = ", 9);
	len_y = (int) ft_strlen(y);
	ft_putnbr_fd(len_y, 1);
	write(1, "\n", 1);
	write(1, y, ft_strlen(y));
	write(1, "\n", 1);
	free(y);
	return (0);
}

/*
cc -Wall -Wextra -Werror -o prog main.c libft.a
*/
