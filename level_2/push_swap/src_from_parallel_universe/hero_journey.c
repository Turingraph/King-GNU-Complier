/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_journey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:57:34 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/03 17:28:38 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(n)
// space: O(1)
void	existential_crisis(t_yin_yang *story, char secret)
{
	size_t	day;
	char	whoami;

	whoami = 'b';
	if (secret == 1)
		whoami = 'B';
	day = 0;
	while (story->me->time > 1)
	{
		if ((story->me->first->moment > story->me->first->future->moment
				&& day % 2 == 0)
			|| (story->me->first->moment < story->me->first->future->moment
				&& day % 2 == 1))
			arc_prioritize(story->me->first, story->me->first->future, whoami);
		arc_conversation(&story->them, &story->me, whoami);
		arc_conversation(&story->them, &story->me, whoami);
		day += 1;
	}
	if (story->me->first != NULL)
	{
		arc_conversation(&story->them, &story->me, whoami);
		arc_reflection(&story->them, whoami);
	}
	story->tree_of_life = 4;
}

// time : O(n)
// space: O(1)
void	time_machine(t_vision **original_time,
		t_vision **parallel_time, char whoami, size_t time)
{
	size_t	day;

	day = 0;
	while (day < time && original_time != NULL)
	{
		arc_conversation(parallel_time, original_time, whoami);
		if (*parallel_time != NULL && time > 2)
			arc_reflection(parallel_time, whoami);
		day += 1;
	}
}
// 6 5 4 3

// original_time->time > parallel_time->time, time = tree_of_life / 2
// time : O(n)
// space: O(1)
void	observer_effect(t_vision *original_time,
	t_vision *parallel_time, char whoami, size_t time)
{
	size_t	day;

	day = 0;
	while (day < time)
	{
		if (parallel_time->first != NULL
			&& parallel_time->first->moment <= original_time->first->moment)
			arc_conversation(&original_time, &parallel_time, whoami);
		else
			day += 1;
		arc_reflection(&original_time, whoami);
	}
	while (parallel_time->first != NULL)
	{
		arc_conversation(&original_time, &parallel_time, whoami);
		arc_reflection(&original_time, whoami);
	}
}

// time : O(n)
// space: O(1)
size_t	hero_journey(t_vision *original_time, t_vision *parallel_time,
	size_t tree_of_life, char whoami)
{
	size_t		day;
	size_t		life_energy;

	life_energy = original_time->time;
	day = 1;
	while (tree_of_life * day <= life_energy)
	{
		time_machine(&original_time, &parallel_time, whoami, tree_of_life / 2);
		observer_effect(original_time, parallel_time, whoami, tree_of_life / 2);
		day += 1;
	}
	if (tree_of_life * day % life_energy > 0)
	{
		time_machine(&original_time, &parallel_time, whoami,
			tree_of_life * day % life_energy - 1);
		if (original_time->first->moment <= parallel_time->first->moment)
			arc_conversation(&parallel_time, &original_time, whoami);
		while (parallel_time->first != NULL)
		{
			arc_conversation(&original_time, &parallel_time, whoami);
			arc_reflection(&original_time, whoami);
		}
	}
	return (life_energy);
}
// 4 * 3 % 10 = 2
/*
// time : O(n log(n))
// space: O(1)
t_vision	*the_illusion_of_separation(t_yin_yang *story, char secret)
{
	char		whoami;
	// size_t		time;
	t_vision	*original_time;
	t_vision	*parallel_time;

	// time = story->me->time;
	whoami = 'b' - secret * ('a' - 'A');
	existential_crisis(story, secret);
	reincarnation(&original_time, &parallel_time, story, &whoami);
	return (original_time);
	// time = 0;
	// while (time < 2)
	// // while (story->tree_of_life <= time)
	// {
	// 	reincarnation(&original_time, &parallel_time, story, &whoami);
	// 	hero_journey(original_time, parallel_time, story->tree_of_life, whoami);
	// 	story->tree_of_life *= 2;
	// 	time += 1;
	// }
	// if (story->tree_of_life % (time / 2) > 0)
	// {
	// 	reincarnation(&original_time, &parallel_time, story, &whoami);
	// 	time_machine(&original_time, &parallel_time, whoami,
	// 		story->tree_of_life / 2);
	// 	// observer_effect(original_time, parallel_time,
	// 	// 	story->tree_of_life / 2, whoami);
	// }
}
*/

void	the_illusion_of_separation(t_yin_yang *story, char secret)
{
	char		whoami;
	size_t		time;
	t_vision	*original_time;
	t_vision	*parallel_time;

	time = story->me->time;
	whoami = 'a' - secret * ('a' - 'A');
	existential_crisis(story, secret);
	while (story->tree_of_life <= time / 2)
	{
		reincarnation(&original_time, &parallel_time, story, &whoami);
		hero_journey(original_time, parallel_time, story->tree_of_life, whoami);
		story->tree_of_life *= 2;
	}
	// if (story->tree_of_life % (time / 2) > 0)
	// {
	// 	reincarnation(&original_time, &parallel_time, story, &whoami);
	// 	time_machine(&original_time, &parallel_time, whoami,
	// 		story->tree_of_life / 2);
	// 	// observer_effect(original_time, parallel_time,
	// 	// 	story->tree_of_life / 2, whoami);
	// }
}
