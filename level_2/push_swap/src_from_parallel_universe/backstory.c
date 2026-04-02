/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backstory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:29:40 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/31 12:38:29 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(n)
// space: O(n)
t_chapter	*write_fiction(size_t time, int *biography, t_chapter *prologue)
{
	t_chapter	*chapter;
	size_t		day;

	chapter = prologue;
	day = 1;
	while (day < time)
	{
		chapter->future = write_a_chapter(biography[day]);
		if (chapter->future == NULL)
		{
			memento_mori(prologue);
			return (NULL);
		}
		chapter = chapter->future;
		day += 1;
	}
	return (chapter);
}

// time : O(n)
// space: O(n)
t_vision	*study_me(size_t time, int *biography)
{
	t_vision	*me;

	me = (t_vision *)malloc(sizeof(t_vision));
	if (me == NULL)
		return (NULL);
	me->first = NULL;
	if (biography != NULL)
		me->first = write_a_chapter(biography[0]);
	if (me->first == NULL && biography != NULL)
	{
		free(me);
		return (NULL);
	}
	me->time = time;
	me->last = NULL;
	if (biography != NULL)
		me->last = write_fiction(time, biography, me->first);
	if (me->last == NULL && biography != NULL)
	{
		free(me);
		return (NULL);
	}
	return (me);
}

// time : O(n)
// space: O(n)
t_yin_yang	*introduction(size_t time, int *biography)
{
	t_yin_yang	*story;

	story = (t_yin_yang *)malloc(sizeof(t_yin_yang));
	if (story == NULL)
		return (NULL);
	story->me = study_me(time, biography);
	if (story->me == NULL)
	{
		free(story);
		return (NULL);
	}
	story->them = NULL;
	story->tree_of_life = 2;
	story->seasons = 0;
	return (story);
}

// time : O(1)
// space: O(1)
size_t	reincarnation(t_vision **original_time,
	t_vision **parallel_time, t_yin_yang *story, char *whoami)
{
	size_t	life_energy;

	*original_time = story->me;
	*parallel_time = story->them;
	life_energy = 0;
	story->seasons = 0;
	if (story->me != NULL)
		life_energy = story->me->time;
	if (*whoami == 'b')
	{
		*original_time = story->them;
		*parallel_time = story->me;
		*whoami = 'a';
		if (story->them != NULL)
			life_energy = story->them->time;
	}
	else
		*whoami = 'b';
	return (life_energy);
}
