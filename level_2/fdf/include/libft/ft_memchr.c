/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 23:24:33 by phsottat          #+#    #+#             */
/*   Updated: 2025/08/30 14:53:12 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*y;
	unsigned char	un_c;

	i = 0;
	while (i < n)
	{
		un_c = (unsigned char) c;
		y = (unsigned char *)(s + i);
		if (*y == un_c)
			return ((void *)y);
		i += 1;
	}
	return (0);
}

/*
#include <string.h>
#include <unistd.h>

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
	char	*my_y;
	char	*th_y;

	if (av < 3)
		return (0);
	if (f_strlen(*(ac + 1)) < 5)
		return (0);
	my_y = ft_memchr(*(ac + 1), **(ac + 2), 5);
	th_y = memchr(*(ac + 1), **(ac + 2), 5);
	if (my_y == NULL || th_y == NULL)
	{
		if (my_y == NULL)
			write(1, "my_y == NULL\n", 13);
		if (th_y == NULL)
			write(1, "th_y == NULL\n", 13);
		return (0);
	}
	write(1, my_y, f_strlen(my_y));
	write(1, "\n", 1);
	write(1, th_y, f_strlen(th_y));
	write(1, "\n", 1);
	return (0);
}
*/
