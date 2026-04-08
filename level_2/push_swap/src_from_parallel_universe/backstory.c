/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backstory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:29:40 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/08 11:47:15 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(n)
// space: O(1)
void	memento_mori(t_chapter *memory)
{
	t_chapter		*time;

	if (memory != NULL)
	{
		while (memory->future != NULL)
		{
			time = memory->future;
			free(memory);
			memory = time;
		}
		free(memory);
	}
}

// time : O(1)
// space: O(1)
t_chapter	*write_a_chapter(int moment)
{
	t_chapter	*chapter;

	chapter = (t_chapter *)malloc(sizeof(t_chapter));
	if (chapter == NULL)
		return (NULL);
	chapter->future = NULL;
	chapter->flashback = NULL;
	chapter->moment = moment;
	return (chapter);
}

// time : O(n)
// space: O(n)
t_chapter	*write_fiction(size_t time, int *biography, t_chapter *prologue)
{
	t_chapter	*chapter;
	t_chapter	*flashback;
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
		flashback = chapter;
		chapter = chapter->future;
		chapter->flashback = flashback;
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
	story->them = study_me(0, NULL);
	if (story->them == NULL)
	{
		memento_mori(story->me->first);
		free(story->me);
		free(story);
		return (NULL);
	}
	story->life_tree = 2;
	return (story);
}
