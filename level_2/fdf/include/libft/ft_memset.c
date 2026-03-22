/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:57:45 by phsottat          #+#    #+#             */
/*   Updated: 2025/08/30 18:36:47 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// https://stackoverflow.com/questions/16016920/
// type-casting-integer-to-void

// https://stackoverflow.com/questions/18851835/
// create-my-own-memset-function-in-c

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*y;

	if (s == NULL)
		return (s);
	y = s;
	i = 0;
	while (i < n)
	{
		*(y + i) = c;
		i += 1;
	}
	return (s);
}

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*f_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i += 1;
	}
	*(dst + i) = '\0';
	return (dst);
}

int	f_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

int	main(int av, char **ac)
{
	char	*vu;
	int		len;

	if (av < 2)
		return (0);
	len = f_strlen(*(ac + 1));
	vu = (char *)malloc(len + 1);
	f_strncpy(vu, *(ac + 1), len);
	ft_memset(vu, 'A', 5);
	memset(*(ac + 1), 'A', 5);
	write(1, "My Result:\t", 11);
	write(1, vu, f_strlen(vu));
	write(1, "\n", 1);
	write(1, "True Result:\t", 13);
	write(1, *(ac + 1), f_strlen(*(ac + 1)));
	write(1, "\n", 1);

	free(vu);
	return (0);
}
*/
