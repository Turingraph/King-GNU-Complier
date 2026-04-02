/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tale.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:45:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/31 18:02:01 by phsottat         ###   ########.fr       */
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
void	show_story(char *me, char *them, char *secret, char whoami)
{
	*me = 'a';
	*them = 'b';
	*secret = 1;
	if (whoami == 'a')
		*secret = 0;
	if (whoami == 'b')
	{
		*secret = 0;
		*me = 'b';
		*them = 'a';
	}
}

// time : O(1)
// space: O(1)
void	say_prioritize(t_yin_yang *story, char mc, char secret)
{
	char	my_tale;
	char	their_tale;

	my_tale = 0;
	if (story->me->first != NULL && story->me->first->future != NULL)
		my_tale = 1;
	their_tale = 0;
	if (story->them->first != NULL && story->them->first->future != NULL)
		their_tale = 1;
	if (my_tale == 1 && (mc == 'a' || mc == 'c'))
		arc_prioritize(story->me->first, story->me->first->future);
	if (their_tale == 1 && (mc == 'b' || mc == 'c'))
		arc_prioritize(story->them->first, story->them->first->future);
	if (my_tale == 1 && their_tale == 1 && secret != 1)
		write(1, "ss\n", 3);
	else if (my_tale == 1 && secret != 1)
		write(1, "sa\n", 3);
	else if (their_tale == 1 && secret != 1)
		write(1, "sb\n", 3);
}

// time : O(1)
// space: O(1)
void	say_conversation(t_yin_yang *story, char mc, char secret, size_t time)
{
	size_t	day;

	day = 0;
	while (day < time)
	{
		if (story->them != NULL && mc == 'a')
		{
			arc_conversation(&story->me, &story->them);
			say_story('p', mc, secret);
			if (story->them->first == NULL)
				day = time;
		}
		if (story->me != NULL && mc == 'b')
		{
			arc_conversation(&story->them, &story->me);
			say_story('p', mc, secret);
			if (story->me->first == NULL)
				day = time;
		}
		if (mc == 'c')
			write(1, "**INVALID**", 11);
		day += 1;
	}
}

// time : O(1)
// space: O(1)
void	say_reflection(t_yin_yang *story, char mc, char secret)
{
	if (story->them != NULL && (mc == 'a' || mc == 'c'))
		arc_reflection(&(story->me));
	if (story->me != NULL && (mc == 'b' || mc == 'c'))
		arc_reflection(&(story->them));
	say_story('r', mc, secret);
}
