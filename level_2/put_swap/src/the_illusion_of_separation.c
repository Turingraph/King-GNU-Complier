/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_illusion_of_separation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:57:34 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/27 18:51:28 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// time : O(n)
// space: O(1)
void	existential_crisis(t_yin_yang *story, char secret)
{
	size_t	i;

	i = 0;
	while (story->me->n_chapters > 1)
	{
		if ((story->me->first->moment > story->me->first->future->moment
				&& i % 2 == 0)
			|| (story->me->first->moment < story->me->first->future->moment
				&& i % 2 == 1))
			say_prioritize(story, 'a', secret);
		say_dialog(story, 'b', secret);
		say_dialog(story, 'b', secret);
		i += 1;
	}
	if (story->me != NULL)
	{
		say_dialog(story, 'b', secret);
		say_outside_box(story, 'b', secret);
	}
	story->tree_of_life = 4;
}

// time : O(n)
// space: O(1)
void	reverse_time_line(t_vision *original_time,
		t_vision *parallel_time, char tale, size_t time)
{
	char	me;
	char	them;
	char	secret;
	size_t	i;

	show_story(&me, &them, &secret, tale);
	i = 0;
	while (i < time && original_time != NULL)
	{
		arc_dialog(&parallel_time, &original_time);
		say_story('p', them, secret);
		if (parallel_time->n_chapters > 1 && time > 2)
		{
			arc_outside_box(&parallel_time);
			say_story('r', them, secret);
		}
		i += 1;
	}
}

// original_time->n_chapters > parallel_time->n_chapters
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
			arc_dialog(&original_time, &parallel_time);
			say_story('p', me, secret);
		}
		arc_outside_box(&original_time);
		say_story('r', me, secret);
		i += 1;
	}
	if (parallel_time != NULL)
	{
		arc_dialog(&original_time, &parallel_time);
		say_story('p', me, secret);
	}
	arc_outside_box(&original_time);
	say_story('r', me, secret);
}

// time : O(n)
// space: O(1)
void	hero_journey(t_yin_yang *story, char *whoami)
{
	t_vision	*original_time;
	t_vision	*parallel_time;
	size_t		time;
	size_t		tree;

	time = reincarnation(&original_time, &parallel_time, story, *whoami);
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
			original_time->n_chapters % (tree * (story->seasons + 1)));
	}
	story->tree_of_life *= 2;
}

// time : O(n log(n))
// space: O(1)
void	the_illusion_of_separation(t_yin_yang *story, char secret)
{
	char	whoami;
	size_t	time;

	time = story->me->n_chapters;
	whoami = 'b';
	existential_crisis(story, secret);
	while (story->tree_of_life <= time)
	{
		hero_journey(story, &whoami);
	}
}

/*
a: 1 2 3 4 5
b:

a: 2 3 4 5
b: 1

a: 3 4 5
b: 2 1

a: 3 4 5
b: 1 2

a: 4 5
b: 3 1 2

a: 4 5
b: 1 2 3

a: 5
b: 4 1 2 3

a: 5
b: 1 2 3 4

a: 
b: 5 1 2 3 4

a: 
b: 1 2 3 4 5
*/

///////////////////////////////////////////////////////////////////////////

/*
a: 4 2 35 5 131 3 77
b:

a: 2 4 35 5 131 3 77
b:

a: 35 5 131 3 77
b: 4 2

a: 131 3 77
b: 5 35 4 2

a: 3 131 77
b: 5 35 4 2

a: 77
b: 131 3 5 35 4 2

a:
b: 77 131 3 5 35 4 2

a:
b: 131 3 5 35 4 2 77
*/

/*
a:
b: 131 3 5 35 (4 2 77)

a: 3 131
b: 5 35 (4 2 77)

a: 3 131
b: 35 (4 2 77) 5

a: 131
b: 3 35 (4 2 77) 5

a: 131
b: 35 (4 2 77) 5 3

a: 131
b: (4 2 77) 5 3 35

a: 
b: 131 (4 2 77) 5 3 35

a: 
b: (4 2 77) 5 3 35 131
*/

/*
a:
b: 4 2 77 (5 3 35 131)

a: 4
b: 2 77 (5 3 35 131)

a: 4
b: 77 (5 3 35 131) 2

a: 
b: 4 77 (5 3 35 131) 2

a: 
b: 77 (5 3 35 131) 2 4

a: 
b: (5 3 35 131) 2 4 77
*/

/*
a: 
b: 5 3 35 131 2 4 77

a: 5
b: 3 35 131 2 4 77

a: 3 5
b: 35 131 2 4 77

a: 5 3
b: 35 131 2 4 77

a: 35 5 3
b: 131 2 4 77
*/

///////////////////////////////////////////////////////////////////////////
/*
a: 4 3 1 2 ...
b: 

a: 1 2 ...
b: 3 4

a: 2 ... 1
b: 3 4

a: ... 1 2
b: 3 4

a: 3 ... 1 2
b: 4

a: ... 1 2 3
b: 4

a: 4 ... 1 2 3
b: 

a: ... 1 2 3 4
b: 
*/
