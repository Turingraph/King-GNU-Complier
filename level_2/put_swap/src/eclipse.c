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

#include "push_swap.h"

char	is_eclipse(size_t sun)
{
	size_t	i;

	i = 2;
	while (i * i <= sun)
	{
		if (sun % i == 0)
			return (0);
		i += 1;
	}
	return (1);
}

size_t	wait_next_eclipse(size_t today)
{
	char	telescope;

	telescope = is_eclipse(today);
	while (telescope == 0)
	{
		today += 1;
		telescope = is_eclipse(today);
	}
	return (today);
}

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
