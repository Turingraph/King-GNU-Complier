/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:40:33 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/01 12:40:59 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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
