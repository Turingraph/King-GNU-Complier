/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tale.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:45:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/29 13:31:01 by phsottat         ###   ########.fr       */
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
void	show_story(char *me, char *them, char *secret, char tale)
{
	*me = 'a';
	*them = 'b';
	*secret = 1;
	if (tale == 'a')
		*secret = 0;
	if (tale == 'b')
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
	if (mc == 'a' && my_tale == 1)
		say_story('s', mc, secret);
	if (mc == 'b' && their_tale == 1)
		say_story('s', mc, secret);
	if (mc == 'c' && my_tale == 1 && their_tale == 1)
		write(1, "ss\n", 3);
}

// time : O(1)
// space: O(1)
void	say_dialog(t_yin_yang *story, char mc, char secret)
{
	if (story->them != NULL && mc == 'a')
	{
		arc_dialog(&(story->me->first), &(story->them->first));
		if (story->them != NULL)
			story->them->time -= 1;
		if (story->me != NULL)
			story->me->time += 1;
		say_story('p', mc, secret);
	}
	if (story->me != NULL && mc == 'b')
	{
		arc_dialog(&(story->them->first), &(story->me->first));
		if (story->them != NULL)
			story->them->time += 1;
		if (story->me != NULL)
			story->me->time -= 1;
		say_story('p', mc, secret);
	}
	if (mc == 'c')
		write(1, "**INVALID**", 11);
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

/*----------------------------------------------------------

int	main(int time, char **memory)
{
	return (0);
}
*/