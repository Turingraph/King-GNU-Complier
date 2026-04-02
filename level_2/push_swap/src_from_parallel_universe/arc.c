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
void	say_story(char arc, char mc, char secret)
{
	if (secret != 1)
	{
		if (arc == 's' && mc == 'a')
			write(1, "sa\n", 3);
		if (arc == 'p' && mc == 'a')
			write(1, "pa\n", 3);
		if (arc == 'r' && mc == 'a')
			write(1, "ra\n", 3);
		if (arc == 's' && mc == 'b')
			write(1, "sb\n", 3);
		if (arc == 'p' && mc == 'b')
			write(1, "pb\n", 3);
		if (arc == 'r' && mc == 'b')
			write(1, "rb\n", 3);
		if (arc == 's' && mc == 'c')
			write(1, "ss\n", 3);
		if (arc == 'r' && mc == 'c')
			write(1, "rr\n", 3);
	}
}

// time : O(1)
// space: O(1)
void	arc_prioritize(t_chapter *now, t_chapter *later, char whoami)
{
	int	prioritize;

	if (now != NULL && later != NULL)
	{
		prioritize = now->moment;
		now->moment = later->moment;
		later->moment = prioritize;
		if (whoami == 'a' || whoami == 'b')
			say_story('s', whoami, 0);
	}
}

// time : O(1)
// space: O(1)
void	arc_dialog(t_vision **listener, t_vision **speaker, char whoami)
{
	t_chapter	*diary;

	if ((*speaker) != NULL && (*speaker)->first != NULL)
	{
		diary = (*listener)->first;
		(*listener)->first = (*speaker)->first;
		(*speaker)->first = (*speaker)->first->future;
		(*listener)->first->future = diary;
		(*listener)->time += 1;
		(*speaker)->time -= 1;
		if (whoami == 'a' || whoami == 'b')
			say_story('p', whoami, 0);
	}
}

// time : O(1)
// space: O(1)
void	arc_conversation(t_vision **listener, t_vision **speaker, char whoami)
{
	t_chapter	*diary;

	if ((*speaker) != NULL && (*speaker)->first != NULL)
	{
		if ((*listener) == NULL)
		{
			(*listener) = study_me(1, NULL);
			if ((*listener) != NULL)
				arc_conversation(listener, speaker, whoami);
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
			if (whoami == 'a' || whoami == 'b')
				say_story('p', whoami, 0);
		}
		else if ((*listener) != NULL && (*listener)->first != NULL)
			arc_dialog(listener, speaker, whoami);
	}
}

// time : O(1)
// space: O(1)
void	arc_reflection(t_vision **perspective, char whoami)
{
	t_chapter	*the_hanged_man;

	if ((*perspective)->first != NULL && (whoami == 'a' || whoami == 'b'))
		say_story('r', whoami, 0);
	(*perspective)->last->future = (*perspective)->first;
	the_hanged_man = (*perspective)->first;
	(*perspective)->first = (*perspective)->first->future;
	(*perspective)->last = the_hanged_man;
	(*perspective)->last->future = NULL;
}
