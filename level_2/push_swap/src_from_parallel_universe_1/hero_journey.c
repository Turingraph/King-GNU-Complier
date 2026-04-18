/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_journey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:29:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/18 16:43:47 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"
// #include <stdlib.h>
// #include <unistd.h>

// char	*determinism(size_t start, size_t stop, char *sieve, char moment)
// {
// }

/*
// time : O(n)
// space: O(n)
char	*determinism(size_t time)
{
	char	*sieve;
	size_t	day;
	size_t	dejavu;

	sieve = (char *)malloc(sizeof(char) * (time + 1));
	if (sieve == NULL)
		return (NULL);
	sieve[0] = '1';
	sieve[time] = '\0';
	dejavu = 1;
	while (dejavu < time)
	{
		day = 0;
		while (day < dejavu && dejavu + day <= time)
		{
			sieve[dejavu + day] = '0' + (char)(1 - 1 * (int)(sieve[day] - '0'));
			day += 1;
		}
		if (dejavu + day >= time)
			dejavu = time;
		dejavu *= 2;
	}
	return (sieve);
}
*/

/*
int	main(void)
{
	char	*x;
	size_t	len;

	len = 13;
	x = determinism(len);
	write(1, x, len);
	write(1, "\n", 1);
	return (0);
}
*/

// time : O(1)
// space: O(1)
void	entanglement(t_yin_yang *story, char secret, int s, char last)
{
	char	whoami;

	whoami = 0;
	if (story->me->first != NULL && story->me->first->future != NULL
		&& story->me->first->moment * s < story->me->first->future->moment * s)
		whoami += 1;
	if (story->them->first != NULL && story->them->first->future != NULL
		&& story->them->first->moment * s
		< story->them->first->future->moment * s && last == 0)
		whoami += 2;
	if (whoami == 3)
	{
		arc_prioritize(story->me->first, story->me->first->future, 'A');
		arc_prioritize(story->them->first, story->them->first->future,
			'B');
		if (secret != 1)
			arc_story('s', 's', 0);
	}
	if (whoami == 1)
		arc_prioritize(story->me->first, story->me->first->future,
			'a' - secret * ('a' - 'A'));
	if (whoami == 2)
		arc_prioritize(story->them->first, story->them->first->future,
			'b' - secret * ('b' - 'B'));
}

// time : O(n)
// space: O(1)
void	observer_effect(t_yin_yang *story, int whoami, size_t shift,
	size_t tfihs)
{
	int	s;

	s = 1;
	if (whoami < 0)
		s = -1;
	while (story->me->first != NULL && shift > 0 && tfihs > 0)
	{
		if (story->me->first->moment * s >= story->them->first->moment * s)
			tfihs -= arc_conversation(&story->them,
					&story->me, (char)(s * whoami), 1);
		else
			shift -= 1;
		arc_reflection(&story->them, (char)(s * whoami));
	}
	while (shift > 0)
	{
		arc_reflection(&story->them, (char)(s * whoami));
		shift -= 1;
	}
	while (story->me->first != NULL && tfihs > 0)
	{
		arc_conversation(&story->them, &story->me, (char)(s * whoami), 1);
		arc_reflection(&story->them, (char)(s * whoami));
		tfihs -= 1;
	}
}

// time : O(n)
// space: O(n)
void	existential_crisis(t_yin_yang *story, char secret, char *sieve)
{
	int		whoami;
	size_t	time;
	size_t	day;
	size_t	end;

	whoami = 'b' - secret * ('b' - 'B');
	time = story->me->time;
	day = 0;
	while (day < time / 4)
	{
		arc_conversation(&story->them, &story->me, (char) whoami, 2);
		entanglement(story, secret, 2 * (sieve[day] - '0') - 1, 0);
		observer_effect(story, whoami * (2 * (sieve[day] - '0') - 1), 2, 2);
		day += 1;
	}
	end = 0;
	if (time % 4 >= 2)
	{
		entanglement(story, secret, 2 * (sieve[day] - '0') - 1, 1);
		end = arc_conversation(&story->them, &story->me, (char) whoami, 2);
	}
	if (time % 4 > 0)
		observer_effect(story, whoami * (2 * (sieve[day] - '0') - 1),
			end, story->me->time);
	story->life_tree = 4;
}

/*
// time : O(n)
// space: O(n)
void	existential_crisis(t_yin_yang *story, char secret, char *sieve)
{
	int		whoami;
	size_t	time;
	size_t	day;
	size_t	end;

	whoami = 'b' - secret * ('b' - 'B');
	time = story->me->time;
	day = 0;
	while (day < time / 4)
	{
		day += arc_conversation(&story->them, &story->me, (char) whoami, 2) / 2;
		entanglement(story, secret, 2 * (sieve[day - 1] - '0') - 1, 0);
		observer_effect(story, whoami * (2 * (sieve[day - 1] - '0') - 1), 2, 2);
	}
	end = 0;
	if (time % 4 >= 2)
	{
		entanglement(story, secret, arc_prioritize(NULL, NULL, 0,
				sieve + day), 1);
		end = arc_conversation(&story->them, &story->me, (char) whoami, 2);
	}
	if (time % 4 > 0)
		observer_effect(story, whoami * (2 * (sieve[day] - '0') - 1),
			end, story->me->time);
	story->life_tree = 4;
}
*/