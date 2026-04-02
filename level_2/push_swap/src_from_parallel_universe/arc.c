/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:42:31 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/31 17:25:51 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(1)
// space: O(1)
void	arc_prioritize(t_chapter *now, t_chapter *later)
{
	int	prioritize;

	if (now != NULL && later != NULL)
	{
		prioritize = now->moment;
		now->moment = later->moment;
		later->moment = prioritize;
	}
}

// time : O(1)
// space: O(1)
void	arc_dialog(t_chapter **listener, t_chapter **speaker,
			size_t *listener_time, size_t *speaker_time)
{
	t_chapter	*diary;

	if ((*speaker) != NULL)
	{
		diary = (*listener);
		(*listener) = (*speaker);
		(*speaker) = (*speaker)->future;
		(*listener)->future = diary;
		*listener_time += 1;
		*speaker_time -= 1;
	}
}

// time : O(1)
// space: O(1)
void	arc_conversation(t_vision **listener, t_vision **speaker)
{
	t_chapter	*diary;

	if ((*speaker) != NULL && (*speaker)->first != NULL)
	{
		if ((*listener) == NULL)
		{
			(*listener) = study_me(1, NULL);
			if ((*listener) != NULL)
				arc_conversation(listener, speaker);
			else
				free((*listener));
		}
		else if ((*listener) != NULL && (*listener)->first == NULL)
		{
			(*listener)->first = write_a_chapter((*speaker)->first->moment);
			(*listener)->last = (*listener)->first;
			diary = (*speaker)->first;
			(*speaker)->first = (*speaker)->first->future;
			free(diary);
			(*speaker)->time -= 1;
		}
		else if ((*listener) != NULL && (*listener)->first != NULL)
			arc_dialog(&(*listener)->first, &(*speaker)->first,
				&(*listener)->time, &(*speaker)->time);
	}
}

// time : O(1)
// space: O(1)
void	arc_reflection(t_vision **perspective)
{
	t_chapter	*the_hanged_man;

	(*perspective)->last->future = (*perspective)->first;
	the_hanged_man = (*perspective)->first;
	(*perspective)->first = (*perspective)->first->future;
	(*perspective)->last = the_hanged_man;
	(*perspective)->last->future = NULL;
}
