/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:43:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/19 17:58:51 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "appendix.h"
#include <unistd.h>
#include <stdlib.h>

/*
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
*/

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

// time : O(n)
// space: O(1)
size_t	shift_morse(size_t moment, char *sieve)
{
	char	temp;
	char	next;
	int		second;

	temp = sieve[moment - 1];
	sieve[moment - 1] = sieve[0];
	second = moment - 2;
	while (second >= 0)
	{
		next = sieve[second];
		sieve[second] = temp;
		temp = next;
		second -= 1;
	}
	return (moment);
}

// time : O(n log(n))
// space: O(n)
char	*sieve_of_marston_morse(size_t moment, char *sieve)
{
	char	*ssieve;
	size_t	second;

	if (moment <= 1)
		return (sieve);
	sieve_of_marston_morse(moment / 2 + moment % 2, sieve);
	if (moment % 2 == 1)
		shift_morse(moment / 2 + moment % 2, sieve);
	ssieve = (char *)malloc(sizeof(char) * (moment + 1));
	if (ssieve == NULL)
		return (NULL);
	second = 0;
	while (second < moment / 2)
	{
		ssieve[2 * second] = '1' - (sieve[second] - '0') % 2;
		ssieve[2 * second + 1] = sieve[second];
		second += 1;
	}
	if (moment % 2 == 1)
		ssieve[2 * second] = sieve[second];
	ssieve[2 * second + moment % 2] = '\0';
	morse_code(sieve, ssieve, moment);
	free(ssieve);
	return (sieve);
}

/*
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
*/

/*
gcc -Wall -Wextra -Werror will.c
valgrind --leak-check=full ./a.out 17

1001011010010110011010010110100110010110011010011001011010010110011010011001011001101001011010011001


*/
