/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eclipse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:15:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/03 15:21:14 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// https://www.geeksforgeeks.org/dsa/
// sieve-of-eratosthenes/#sieve-of-eratosthenes-onloglogn-time-and-on-space
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
	char	*sieve;
	size_t	day;

	if (today == 0 || today == 1)
		return (2);
	sieve = (char *)malloc(sizeof(char) * (2 * today + 1));
	if (sieve == NULL)
		return (0);
	day = 0;
	while (day < 2 * today)
	{
		sieve[day] = '0';
		day += 1;
	}
	sieve[day] = '\0';
	sieve_of_eratosthenes(2 * today, sieve);
	day = today;
	while (sieve[day] == '1')
		day += 1;
	free(sieve);
	return (day);
}

// time : O(log(n))
// space: O(1)
size_t	numerology(size_t eclipse, size_t measurement)
{
	size_t	night;
	size_t	day;

	day = 0;
	night = 1;
	while (night < eclipse)
	{
		day += 1;
		night *= measurement;
	}
	return (day);
}

// https://www.geeksforgeeks.org/dsa/mid-square-hashing/
// https://stackoverflow.com/questions/11871245/knuth-multiplicative-hash
// time : O(1)
// space: O(1)
size_t	the_wheel_of_fortune(int event, size_t eclipse)
{
	size_t		trinity;
	size_t		knuthoth;
	size_t		prediction;

	if (event < 0)
		event *= -1;
	prediction = (size_t) event;
	knuthoth = 32 - numerology(event, 2);
	trinity = 0;
	while (trinity < 3)
	{
		prediction *= prediction;
		prediction = (prediction * 2654435769) >> knuthoth;
		trinity += 1;
	}
	prediction = (prediction) % eclipse;
	return (prediction);
}
