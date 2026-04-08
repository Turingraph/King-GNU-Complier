/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_journey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:08:35 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/08 19:08:06 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(n)
// space: O(1)
void	time_machine(t_vision **original_time,
	t_vision **parallel_time, char whoami, size_t time)
{
	size_t	day;

	day = 0;
	while (day < time && original_time != NULL)
	{
		arc_conversation(original_time, parallel_time, whoami, 1);
		if (day > 0)
			arc_reflection(original_time, whoami);
		day += 1;
	}
}

// 13 steps time machine.
// a:  26 25
// b:  27 28 (...)

// time : O(n)
// space: O(1)
void	observer_effect(t_yin_yang *story, char whoami, size_t shift,
	size_t tfihs)
{
	while (story->me->first != NULL && shift > 0 && tfihs > 0)
	{
		if (story->me->first->moment >= story->them->first->moment)
			tfihs -= arc_conversation(&story->them,
					&story->me, whoami, 1);
		else
			shift -= 1;
		arc_reflection(&story->them, whoami);
	}
	while (shift > 0)
	{
		arc_reflection(&story->them, whoami);
		shift -= 1;
	}
	while (story->me->first != NULL && tfihs > 0)
	{
		arc_conversation(&story->them, &story->me, whoami, 1);
		arc_reflection(&story->them, whoami);
		tfihs -= 1;
	}
}

// time : O(1)
// space: O(1)
void	entanglement(t_yin_yang *story, char secret)
{
	char	me;
	char	them;

	me = 0;
	them = 0;
	if (story->me->first != NULL && story->me->first->future != NULL
		&& story->me->first->moment < story->me->first->future->moment)
		me = 1;
	if (story->them->first != NULL && story->them->first->future != NULL
		&& story->them->first->moment < story->them->first->future->moment)
		them = 1;
	if (me == 1 && them == 1)
	{
		arc_prioritize(story->me->first, story->me->first->future, 'A');
		arc_prioritize(story->them->first, story->them->first->future, 'B');
		if (secret != 1)
			arc_story('s', 's', 0);
	}
	if (me == 1 && them == 0)
		arc_prioritize(story->me->first, story->me->first->future,
			'a' - secret * ('a' - 'A'));
	if (me == 0 && them == 1)
		arc_prioritize(story->them->first, story->them->first->future,
			'b' - secret * ('b' - 'B'));
}

// Make 8 Chunk.
// Avoid using time_machine.

// 4 3 2 1 5 6 7 8
// 9 10 11 12 16 15 14 13 24 23 22 21 25 26 27 28 29 30 31 32 36 35 34 33 44 43 42 41 45 46 47 48 49 50 51 52 56 55 54 53
// time : O(n)
// space: O(1)
void	existential_crisis(t_yin_yang *story, char secret)
{
	size_t	day;
	size_t	time;
	char	whoami;

	whoami = 'b' - secret * ('b' - 'B');
	day = 0;
	time = story->me->time;
	while (day < time / 4)
	{
		arc_conversation(&story->them, &story->me, whoami, 2);
		entanglement(story, secret);
		observer_effect(story, whoami, 2, 2);
		day += 1;
	}
	day = 0;
	if (time % 4 >= 2)
	{
		if (story->me->first->moment > story->me->first->future->moment)
			arc_prioritize(story->me->first, story->me->first->future,
				whoami - 1);
		day = arc_conversation(&story->them, &story->me, whoami, 2);
	}
	if (time % 4 > 0)
		observer_effect(story, whoami, day, story->me->time);
	story->life_tree = 4;
}

// time : O(n)
// space: O(1)
void	hero_journey(t_yin_yang *story, char secret)
{
	size_t		day;
	size_t		time;
	char		whoami;

	whoami = 'b' - secret * ('a' - 'A');
	day = 0;
	time = story->them->time;
	while (day < time / (story->life_tree * 2))
	{
		time_machine(&story->me, &story->them, whoami - 1, story->life_tree);
		observer_effect(story, whoami, story->life_tree, story->life_tree);
		day += 1;
	}
	day = 0;
	if (time % (story->life_tree * 2) >= story->life_tree)
	{
		time_machine(&story->me, &story->them, whoami - 1, story->life_tree);
		day = story->life_tree;
	}
	if (time % (story->life_tree * 2) > 0)
		observer_effect(story, whoami,
			time % (story->life_tree * 2) - day, day);
	story->life_tree *= 2;
}
