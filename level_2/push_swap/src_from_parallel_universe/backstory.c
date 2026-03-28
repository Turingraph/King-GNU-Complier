/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backstory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:29:40 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/27 18:45:30 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"appendix.h"

// time : O(n)
// space: O(n)
t_chapter	*write_diary(size_t n_chapters, int *record, t_chapter *grimoire)
{
	t_chapter	*diary;
	size_t		i;

	diary = grimoire;
	i = 1;
	while (i < n_chapters)
	{
		diary->future = write_a_chapter(record[i]);
		if (diary->future == NULL)
		{
			memento_mori(grimoire);
			return (NULL);
		}
		diary = diary->future;
		i += 1;
	}
	return (diary);
}

// time : O(n)
// space: O(n)
t_vision	*study_me(size_t n_chapters, int *record)
{
	t_chapter	*chapter;
	t_vision	*me;
	size_t		i;

	me = (t_vision *)malloc(sizeof(t_vision));
	if (me == NULL)
		return (NULL);
	me->first = write_a_chapter(record[0]);
	if (me->first == NULL)
	{
		free(me);
		return (NULL);
	}
	me->n_chapters = n_chapters;
	me->last = write_diary(n_chapters, record, me->first);
	if (me->last == NULL)
	{
		free(me);
		return (NULL);
	}
	return (me);
}

// time : O(n)
// space: O(n)
t_yin_yang	*write_backstory(size_t n_chapters, int *record)
{
	t_yin_yang	*story;
	int			*record;

	story = (t_yin_yang *)malloc(sizeof(t_yin_yang));
	if (story == NULL)
		return (NULL);
	story->me = study_me(n_chapters, record);
	if (story->me == NULL)
	{
		free(story);
		free(record);
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
		life_energy = story->me->n_chapters;
	if (*whoami == 'b')
	{
		*original_time = story->them;
		*parallel_time = story->me;
		*whoami = 'a';
		if (story->them != NULL)
			life_energy = story->them->n_chapters;
	}
	else
		*whoami = 'b';
	return (life_energy);
}
