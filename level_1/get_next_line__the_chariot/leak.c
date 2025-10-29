/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:44:49 by phsottat          #+#    #+#             */
/*   Updated: 2025/10/18 14:15:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

int	main(int av, char **ar)
{
	char	*buff;
	size_t	i;

	if (av <= 1)
		return (0);
	// write(1, *(ar + 1), ft_strlen(*(ar + 1)));
	buff = (char *)malloc(ft_strlen(*(ar + 1)) * sizeof(char));
	if (buff == NULL)
		return (0);
	i = 0;
	// write(1, "\n", 1);
	while (i < ft_strlen(*(ar + 1)))
	{
		// write(1, (*(ar + 1) + i), 1);
		*(buff + i) = *(*(ar + 1) + i);
		i += 1;
	}
	// write(1, "\n", 1);
	write(1, buff, ft_strlen(buff));
	free(buff);
	return (0);
}

/*
cc -Wall -Wextra -Werror leak.c
valgrind --show-leak-kinds=all --leak-check=full ./a.out MMMM
*/
