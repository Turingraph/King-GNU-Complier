/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:45:22 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 11:00:52 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, f_strlen(s));
}

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	write(1, "Hello World\n", 12);
	// printf("%s\n", "Hello World");
	return (0);
}
*/
