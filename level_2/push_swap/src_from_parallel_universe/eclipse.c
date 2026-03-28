/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclipse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:15:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/27 18:31:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// https://www.geeksforgeeks.org/dsa/sieve-of-eratosthenes/#sieve-of-eratosthenes-onloglogn-time-and-on-space
// time : O(n log(log(n)))
// space: O(1)
char	*sieve_of_eratosthenes(size_t today, char *sieve)
{
	size_t	day;
	size_t	sun;

	sieve[0] = '1';
	sieve[1] = '1';
	day = 2;
	while (day * day < today)
	{
		if (sieve[day] == '0')
		{
			sun = 2 * day;
			while (sun < today)
			{
				sieve[sun] = '1';
				sun += day;
			}
		}
		day += 1;
	}
	return (sieve);
}

// time : O(n log(log(n)))
// space: O(n)
size_t	wait_next_eclipse(size_t today)
{
	char	*seive;
	size_t	eclipse;

	*seive = (char *)malloc(sizeof(char) * (2 * today + 1));
	if (seive == NULL)
		return (0);
	seive[2 * today] = '\0';
	sieve_of_eratosthenes(2 * today, seive);
	eclipse = today;
	while (eclipse < 2 * today && seive[today] == '1')
		eclipse += 1;
	free(seive);
	return (eclipse);
}

// time : O(n)
// space: O(1)
size_t	numerology(size_t a, size_t b)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 1;
	while (i <= b)
	{
		y *= a;
		i += 1;
	}
	return (y);
}

// https://www.geeksforgeeks.org/dsa/mid-square-hashing/
// time : O(1)
// space: O(1)
size_t	the_wheel_of_fortune(int event, size_t eclipse)
{
	size_t		month;
	size_t		first_digits;
	size_t		last_digits;
	size_t		prediction;

	prediction = (size_t) event;
	first_digits = numerology(2, 8 + 1);
	last_digits = numerology(2, 2 * 8 + 1);
	month = 0;
	while (month < 12)
	{
		prediction *= prediction;
		prediction = prediction / first_digits;
		prediction = prediction % last_digits;
		month += 1;
	}
	prediction = prediction % eclipse;
	return (prediction);
}
