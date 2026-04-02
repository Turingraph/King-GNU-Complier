/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_illusion_of_separation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:57:34 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/31 17:59:12 by phsottat         ###   ########.fr       */
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
void	reverse_time_line(t_vision **original_time,
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

/*
// time : O(n)
// space: O(1)
size_t	hero_journey(t_yin_yang *story, char *whoami)
{
	t_vision	*original_time;
	t_vision	*parallel_time;
	size_t		day;
	size_t		life_energy;
	size_t		to_be_continued;

	life_energy = reincarnation(&original_time, &parallel_time, story, whoami);
	day = 1;
	while (story->tree_of_life * day <= life_energy)
	{
		reverse_time_line(&original_time, &parallel_time, *whoami, story->tree_of_life / 2);
		observer_effect(original_time, parallel_time, *whoami, story->tree_of_life / 2);
		day += 1;
	}
	to_be_continued = story->tree_of_life * day % life_energy;
	if (to_be_continued > 0)
	{
		reverse_time_line(&original_time, &parallel_time, *whoami, to_be_continued - 1);
		if (original_time->first->moment <= parallel_time->first->moment)
		{
			arc_conversation(&parallel_time, &original_time);
			say_story('p', *whoami, 0);
		}
		while (parallel_time->first != NULL)
		{
			if (parallel_time->first->moment <= original_time->first->moment)
			{
				arc_conversation(&original_time, &parallel_time);
				say_story('p', me, secret);
			}
			arc_reflection(&original_time);
			say_story('r', me, secret);
		}
		arc_reflection(&original_time);
		say_story('r', me, secret);
	}
	story->tree_of_life *= 2;
	return (life_energy);
}
*/

// time : O(n log(n))
// space: O(1)
/*
void	the_illusion_of_separation(t_yin_yang *story, char secret)
{
	char	whoami;
	size_t	life_engery;

	existential_crisis(story, secret);
	whoami = 'b';
	if (secret == 1)
		whoami = 'B';
	life_engery = story->them->time;
	while (story->tree_of_life < life_engery)
		hero_journey(story, whoami);
}
*/
















/*
size_t	hero_journey(t_yin_yang *story, char *whoami)
{
	t_vision	*original_time;
	t_vision	*parallel_time;
	size_t		time;
	size_t		tree;

	time = reincarnation(&original_time, &parallel_time, story, whoami);
	tree = story->tree_of_life;
	while (tree * (story->seasons + 1) <= time)
	{
		reverse_time_line(original_time, parallel_time, *whoami, tree / 2);
		observer_effect(original_time, parallel_time, *whoami, tree);
		story->seasons += 1;
	}
	if (tree * (story->seasons + 1) > time)
	{
		reverse_time_line(original_time, parallel_time, *whoami, tree / 2);
		observer_effect(original_time, parallel_time, *whoami,
			original_time->time % (tree * (story->seasons + 1)));
	}
	story->tree_of_life *= 2;
	return (time);
}
*/

// time : O(n log(n))
// space: O(1)
/*
void	the_illusion_of_separation(t_yin_yang *story, char secret)
{
	char	whoami;
	size_t	time;

	time = story->me->time;
	whoami = 'b';
	existential_crisis(story, secret);
	while (story->tree_of_life <= time)
		time = hero_journey(story, &whoami);
}
*/
