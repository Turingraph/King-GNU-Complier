/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_illusion_of_separation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:57:34 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/31 15:59:39 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(n)
// space: O(1)
void	existential_crisis(t_yin_yang *story, char secret)
{
	size_t	i;

	i = 0;
	while (story->me->time > 1)
	{
		if ((story->me->first->moment > story->me->first->future->moment
				&& i % 2 == 0)
			|| (story->me->first->moment < story->me->first->future->moment
				&& i % 2 == 1))
			say_prioritize(story, 'a', secret);
		say_conversation(story, 'b', secret);
		say_conversation(story, 'b', secret);
		i += 1;
	}
	if (story->me->first != NULL)
		say_conversation(story, 'b', secret);
	story->tree_of_life = 4;
}

// time : O(n)
// space: O(1)
void	reverse_time_line(t_vision **original_time,
		t_vision **parallel_time, char tale, size_t time)
{
	char	me;
	char	them;
	char	secret;
	size_t	i;

	show_story(&me, &them, &secret, tale);
	i = 0;
	while (i < time && original_time != NULL)
	{
		arc_conversation(parallel_time, original_time);
		say_story('p', them, secret);
		if (*parallel_time != NULL && time > 2)
		{
			arc_reflection(parallel_time);
			say_story('r', them, secret);
		}
		i += 1;
	}
}

// original_time->time > parallel_time->time
// time : O(n)
// space: O(1)
void	observer_effect(t_vision *original_time,
	t_vision *parallel_time, char tale, size_t time)
{
	char	me;
	char	them;
	char	secret;
	size_t	i;

	show_story(&me, &them, &secret, tale);
	i = 0;
	while (i < time - 1)
	{
		if (parallel_time->first->moment <= original_time->first->moment)
		{
			arc_conversation(&original_time, &parallel_time);
			say_story('p', me, secret);
		}
		arc_reflection(&original_time);
		say_story('r', me, secret);
		i += 1;
	}
	// if (parallel_time->first != NULL)
	// {
	// 	arc_conversation(&original_time, &parallel_time);
	// 	say_story('p', me, secret);
	// }
	// arc_reflection(&original_time);
	// say_story('r', me, secret);
}

// time : O(n)
// space: O(1)
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
	{
		time = hero_journey(story, &whoami);
	}
}
*/

