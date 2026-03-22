/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:44:30 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 10:57:37 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*y;
	size_t	i;
	size_t	len;

	len = f_strlen(s);
	y = (char *)malloc(len + 1);
	if (y == NULL)
		return (y);
	i = 0;
	while (i < len)
	{
		*(y + i) = *(s + i);
		i += 1;
	}
	*(y + i) = '\0';
	return (y);
}

// https://stackoverflow.com/questions/37132549/
// implementation-of-strdup-in-c-programming
// WARNING: ALWAYS USE `malloc(len + 1)` 
// AND APPEND `'\0'` AT THE END OF `dest`. WHEN COPY STRING.

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(int av, char **ac)
{
	char	*eiganv;

	if (av < 2)
		return (0);
	eiganv = *(ac + 1);
	// printf("%s\n", ft_strdup(eiganv));
	write(1, ft_strdup(eiganv), f_strlen(ft_strdup(eiganv)));
	write(1, "\n", 1);
	write(1, strdup(eiganv), f_strlen(eiganv));
	write(1, "\n", 1);
	return (0);
}
*/
