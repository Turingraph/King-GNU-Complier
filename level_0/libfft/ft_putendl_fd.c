/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:53:14 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 11:03:24 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*
Add static to prevent 
multiple definition of `f_strlen'; 
ft_strlcat.o:ft_strlcat.c:(.text+0x0): first defined here error.
*/

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, f_strlen(s));
	write(fd, "\n", 1);
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
