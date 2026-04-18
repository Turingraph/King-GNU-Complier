/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   will.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:43:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/18 19:05:10 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "appendix.h"
#include <unistd.h>
#include <stdlib.h>

// time : O(1)
// space: O(1)
long int	first_draft(char *src, char *err, size_t *digit, size_t sign)
{
	long int	y;

	y = 0;
	while (src[*digit] != '\0' && *digit < 11 + sign && *err != 'E')
	{
		if (*digit == sign && src[*digit] == '0')
			*err = 'E';
		else if (src[*digit] >= '0' && src[*digit] <= '9')
			y += (long int)(src[*digit] - '0');
		else
			*err = 'E';
		*digit += 1;
		y *= 10;
	}
	y /= 10;
	return (y);
}

// time : O(1)
// space: O(1)
int	edited_draft(char *src, char *err)
{
	long int	y;
	size_t		digit;
	size_t		sign;

	if (src[0] == '0' && src[1] == '\0')
		return (0);
	digit = 0;
	sign = 0;
	if (src[digit] == '-')
		sign = 1;
	digit = sign;
	y = first_draft(src, err, &digit, sign);
	if (sign == 1)
		y *= -1;
	if (src[digit] != '\0' && digit >= 11 + sign)
	{
		*err = 'E';
		return (-1);
	}
	if (y < -2147483648 || y > 2147483647)
	{
		*err = 'E';
		return (-1);
	}
	return ((int) y);
}

// time : O(n)
// space: O(1)
size_t	morse_code(char *listener, char *speaker, size_t moment)
{
	size_t	second;

	second = 0;
	while (second < moment && *speaker != '\0')
	{
		*listener = *speaker;
		listener += 1;
		speaker += 1;
		second += 1;
	}
	return (second);
}

// time : O(n log(n))
// space: O(n)
char	*sieve_of_marston_morse(size_t today, char *sieve)
{
	char	*ssieve;
	size_t	day;

	if (today <= 1)
		return (sieve);
	sieve_of_marston_morse(today / 2, sieve);
	ssieve = (char *)malloc(sizeof(char) * (today + 1));
	if (ssieve == NULL)
		return (NULL);
	ssieve[today] = '\0';
	day = 0;
	while (day < today / 2)
	{
		ssieve[2 * day] = '1' - (sieve[day] - '0') % 2;
		ssieve[2 * day + 1] = sieve[day];
		day += 1;
	}
	if (today % 2 == 1)
		ssieve[2 * day] = '1' - (sieve[0] - '0') % 2;
	morse_code(sieve, ssieve, today);
	free(ssieve);
	return (sieve);
}

	// write(1, "::: ", 4);
	// write(1, ssieve, today);
	// write(1, "\n", 1);

int	main(int time, char **memory)
{
	char	*sieve;
	char	err;
	size_t	today;
	size_t	day;

	if (time < 2)
		return (0);
	err = 'K';
	today = edited_draft(memory[1], &err);
	if (err == 'E')
		return (0);
	sieve = (char *)malloc(sizeof(char) * (today + 1));
	if (sieve == NULL)
		return (0);
	sieve[today] = '\0';
	day = 0;
	while (day < today)
	{
		sieve[day] = '#';
		day += 1;
	}
	sieve[0] = '1';
	sieve_of_marston_morse(today, sieve);
	write(1, sieve, today);
	write(1, "\n", 1);
	free(sieve);
	return (0);
}

/*
gcc -Wall -Wextra -Werror will.c
valgrind --leak-check=full ./a.out 17
*/
