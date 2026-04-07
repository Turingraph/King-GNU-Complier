/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:42:31 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/07 13:37:07 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(1)
// space: O(1)
void	arc_story(char arc, char mc, char secret)
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
		if (arc == 's' && mc == 's')
			write(1, "ss\n", 3);
		if (arc == 'r' && mc == 'r')
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
			arc_story('s', whoami, 0);
	}
}

// time : O(1)
// space: O(1)
size_t	arc_conversation(t_vision **listener, t_vision **speaker, char whoami,
			size_t time)
{
	size_t		reset_time;
	t_chapter	*diary;

	reset_time = time;
	while (time > 0)
	{
		if ((*speaker) != NULL && (*speaker)->first != NULL)
		{
			diary = (*listener)->first;
			(*listener)->first = (*speaker)->first;
			if (diary == NULL)
				(*listener)->last = (*listener)->first;
			if ((*speaker)->first->future == NULL)
				(*speaker)->last = NULL;
			(*speaker)->first = (*speaker)->first->future;
			(*listener)->first->future = diary;
			(*listener)->time += 1;
			(*speaker)->time -= 1;
			if (whoami == 'a' || whoami == 'b')
				arc_story('p', whoami, 0);
		}
		time -= 1;
	}
	return (reset_time);
}

// time : O(1)
// space: O(1)
void	arc_reflection(t_vision **perspective, char whoami)
{
	t_chapter	*diary;

	if ((*perspective)->first != NULL && (*perspective)->last != NULL
		&& (*perspective)->first != (*perspective)->last
		&& (whoami == 'a' || whoami == 'b'))
		arc_story('r', whoami, 0);
	diary = (*perspective)->first;
	if (diary != NULL && (*perspective)->time > 1)
	{
		(*perspective)->first = (*perspective)->first->future;
		(*perspective)->last->future = diary;
		(*perspective)->last = (*perspective)->last->future;
		(*perspective)->last->future = NULL;
	}
}
