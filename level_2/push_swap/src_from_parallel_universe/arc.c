/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:42:31 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/08 13:36:26 by phsottat         ###   ########.fr       */
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
		if (arc == 'l' && mc == 'a')
			write(1, "rra\n", 4);
		if (arc == 's' && mc == 'b')
			write(1, "sb\n", 3);
		if (arc == 'p' && mc == 'b')
			write(1, "pb\n", 3);
		if (arc == 'r' && mc == 'b')
			write(1, "rb\n", 3);
		if (arc == 'l' && mc == 'b')
			write(1, "rrb\n", 4);
		if (arc == 's' && (mc == 's' || mc == 'c'))
			write(1, "ss\n", 3);
		if (arc == 'r' && (mc == 'r' || mc == 'c'))
			write(1, "rr\n", 3);
		if (arc == 'l' && (mc == 'r' || mc == 'c'))
			write(1, "rrr\n", 4);
	}
}

// time : O(1)
// space: O(1)
size_t	arc_prioritize(t_chapter *now, t_chapter *later, char whoami)
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
	return (1);
}

// time : O(n)
// space: O(n)
size_t	arc_conversation(t_vision **listener, t_vision **speaker, char whoami,
	size_t time)
{
	t_chapter	*diary;

	if (time == 0)
		return (0);
	if ((*speaker) != NULL && (*speaker)->first != NULL)
	{
		diary = (*listener)->first;
		(*listener)->first = (*speaker)->first;
		if (diary == NULL)
			(*listener)->last = (*listener)->first;
		if ((*speaker)->first->future == NULL)
			(*speaker)->last = NULL;
		(*speaker)->first = (*speaker)->first->future;
		if ((*speaker)->first != NULL)
			(*speaker)->first->flashback = NULL;
		if (diary != NULL)
			diary->flashback = (*listener)->first;
		(*listener)->first->future = diary;
		(*listener)->time += 1;
		(*speaker)->time -= 1;
		arc_story('p', whoami, 0);
	}
	return (arc_conversation(listener, speaker, whoami, time - 1) + 1);
}

// time : O(1)
// space: O(1)
size_t	arc_reflection(t_vision **perspective, char whoami)
{
	t_chapter	*diary;

	if ((*perspective)->first != NULL && (*perspective)->last != NULL
		&& (*perspective)->time > 1)
	{
		arc_story('r', whoami, 0);
		diary = (*perspective)->first;
		(*perspective)->first = (*perspective)->first->future;
		(*perspective)->first->flashback = NULL;
		(*perspective)->last->future = diary;
		diary->flashback = (*perspective)->last;
		(*perspective)->last = (*perspective)->last->future;
		(*perspective)->last->future = NULL;
	}
	return (1);
}

// time : O(1)
// space: O(1)
size_t	arc_noitcelfer(t_vision **perspective, char whoami)
{
	t_chapter	*diary;

	if ((*perspective)->first != NULL && (*perspective)->last != NULL
		&& (*perspective)->time > 1)
	{
		arc_story('l', whoami, 0);
		diary = (*perspective)->last;
		(*perspective)->last = (*perspective)->last->flashback;
		(*perspective)->last->future = NULL;
		diary->flashback = NULL;
		diary->future = (*perspective)->first;
		(*perspective)->first->flashback = diary;
		(*perspective)->first = diary;
	}
	return (1);
}
