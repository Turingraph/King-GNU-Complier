/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dejavu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:29:18 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/29 15:04:00 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(n)
// space: O(1)
void	burning_memory(t_chapter **memory, size_t eclipse)
{
	size_t	i;

	i = 0;
	while (i < eclipse)
	{
		memento_mori(memory[i]);
		i += 1;
	}
	free(memory);
}

// time : O(n)
// space: O(n)
t_chapter	**rumination(size_t eclipse)
{
	size_t		day;
	t_chapter	**memory;

	memory = (t_chapter **)malloc(sizeof(t_chapter *) * (eclipse));
	if (memory == NULL)
		return (NULL);
	day = 0;
	while (day < eclipse)
	{
		memory[day] = NULL;
		day += 1;
	}
	return (memory);
}

// time : O(1)
// space: O(1)
char	subliminal_stimuli(t_chapter **memory, int event, size_t eclipse)
{
	size_t		day;
	t_chapter	*rabbit_hole;

	day = the_wheel_of_fortune(event, eclipse);
	if (memory[day] == NULL)
	{
		memory[day] = write_a_chapter(event);
		if (memory[day] == NULL)
		{
			burning_memory(memory, eclipse);
			return (0);
		}
		return (1);
	}
	rabbit_hole = memory[day];
	while (rabbit_hole->future != NULL)
		rabbit_hole = rabbit_hole->future;
	rabbit_hole->future = write_a_chapter(event);
	if (rabbit_hole->future == NULL)
	{
		burning_memory(memory, eclipse);
		return (0);
	}
	return (1);
}

// time : O(1)
// space: O(1)
char	have_i_seen_this_before(t_chapter **memory, int event, size_t eclipse)
{
	size_t		day;
	t_chapter	*rabbit_hole;

	day = the_wheel_of_fortune(event, eclipse);
	rabbit_hole = memory[day];
	if (rabbit_hole == NULL)
		return (0);
	if (rabbit_hole->moment == event)
		return (1);
	while (rabbit_hole->future != NULL)
	{
		if (rabbit_hole->moment == event)
			return (1);
		rabbit_hole = rabbit_hole->future;
	}
	return (0);
}

// time : O(n log(log(n)))
// space: O(n)
char	kagerou_day(int *events, size_t time)
{
	size_t		i;
	char		dejavu;
	t_chapter	**memory;
	size_t		eclipse;

	dejavu = 0;
	eclipse = wait_next_eclipse(time);
	if (eclipse == 0)
		return (1);
	memory = rumination(eclipse);
	if (memory == NULL)
		return (1);
	i = 0;
	while (i < time && dejavu == 0)
	{
		if (have_i_seen_this_before(memory, events[i], eclipse) == 1)
			dejavu = 1;
		if (subliminal_stimuli(memory, events[i], eclipse) == 0)
			return (dejavu);
		i += 1;
	}
	burning_memory(memory, eclipse);
	return (dejavu);
}
