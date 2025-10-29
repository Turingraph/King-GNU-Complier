/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 21:10:25 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:15:15 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

#include <stdlib.h>

// https://www.geeksforgeeks.org/cpp/memcpy-in-cc/
// https://www.tutorialspoint.com/c_standard_library/c_function_memcpy.htm

/*
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned int	*id;
	unsigned int	*is;

	if (dest == NULL || src == NULL)
		return (dest);
	i = 0;
	while (i < n)
	{
		id = (unsigned int *)(dest + i);
		is = (unsigned int *)(src + i);
		*id = *is;
		i += 1;
	}
	return (dest);
}
*/

//------------------------------------------------
// *** SUPPORTING FUNCTION ***
//------------------------------------------------

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	display_int(int fd, int x)
{
	long	d;
	char	coef;

	d = 1;
	while (d < x)
		d *= 10;
	if (d > x)
		d /= 10;
	while (d > 0)
	{
		coef = x / d + '0';
		write(fd, &coef, 1);
		x = x % d;
		d /= 10;
	}
}

void	display_int_sign(int fd, int x)
{
	if (x == 0)
	{
		write(fd, "0", 1);
	}
	else if (x > 0)
	{
		display_int(fd, x);
	}
	else if (x == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		write(fd, "-", 1);
		display_int(fd, (-1) * x);
	}
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

// I must use unsigned char for id and is because 
// unsigned char use 1 byte.
// unsigned int use 4 bytes.

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*id;
	unsigned char	*is;

	if (dest == NULL || src == NULL)
		return (dest);
	i = 0;
	while (i < n)
	{
		id = (unsigned char *)(dest + i);
		is = (unsigned char *)(src + i);
		*id = *is;
		i += 1;
	}
	return (dest);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	f_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

int	main(int av, char **array)
{
	char	*my_dest;
	char	*th_dest;
	int		len;

	if (av < 3)
		return (0);
	len = f_strlen(*(array + 1));
	my_dest = (char *)malloc(len + 1);
	th_dest = (char *)malloc(len + 1);
	ft_memcpy(my_dest, *(array + 2), len);
	memcpy(th_dest, *(array + 2), len);
	*(my_dest + len) = '\0';
	*(th_dest + len) = '\0';
	write(1, "Input :\t", 8);
	write(1, *(array + 1), len);
	write(1, "\n", 1);
	write(1, "My Result:\t", 11);
	write(1, my_dest, len);
	write(1, "\n", 1);
	write(1, "True Result:\t", 13);
	write(1, th_dest, len);
	write(1, "\n", 1);
	free(my_dest);
	free(th_dest);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
int	main(void)
{
	void	*mem;

	mem = NULL;
	mem = malloc(sizeof(*mem) * 30);
	if (mem == NULL)
	{
		write(1, "NULL\n", 5);
		return (0);
	}
	memset(mem, 'j', 30);
	ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14);
	write(1, mem, 30);
	write(1, "\n", 1);
	memset(mem, 'j', 30);
	memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14);
	write(1, mem, 30);
	write(1, "\n", 1);
	write(1, "\n", 1);

	memset(mem, 'j', 30);
	ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11);
	write(1, mem, 30);
	write(1, "\n", 1);
	memset(mem, 'j', 30);
	memcpy(mem, "zy\0xw\0vu\0\0tsr", 11);
	write(1, mem, 30);
	write(1, "\n", 1);
	write(1, "\n", 1);
	free(mem);

	// memset(mem, 'j', 30);
	// if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
	// 	write(1, "dest's adress was not returned\n", 31);
	// else
	// 	write(1, "OK\n", 3);
	// write(1, mem, 30);
	// write(1, "\n", 1);
	// free(mem);
	// memset(mem, 'j', 30);
	// if (mem != ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
	// 	write(1, "dest's adress was not returned\n", 31);
	// else
	// 	write(1, "OK\n", 3);
	// write(1, mem, 30);
	// write(1, "\n", 1);
	// free(mem);

	// memset(mem, 'A', 100);
	// ft_memcpy(mem, "coucou", 0);
	// char src[] = {0, 0};
	// ft_memcpy(mem, src, 2);
	// int i = 0;
	// for (; i < 100 && mem[i] == 0; ++i)
	// 	;
	// if (i == 2 && mem[2] == 'A')
	// 	write(1, "OK\n", 3);
	// else
	// 	write(1, "NO\n", 3);
	return (0);
}
*/
