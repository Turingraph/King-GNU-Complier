/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dejavu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:29:18 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/27 18:31:48 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

void	lost_time_memory(t_chapter **dejavu, size_t eclipse)
{
	size_t	i;

	i = 0;
	while (i < eclipse)
	{
		burning_memory(dejavu[i]);
		i += 1;
	}
	free(dejavu);
}

t_chapter	**rumination(size_t eclipse)
{
	size_t		day;
	size_t		inevitable_ending;
	t_chapter	**dejavu;

	inevitable_ending = wait_next_eclipse(eclipse + 1);
	dejavu = (t_chapter **)malloc(sizeof(t_chapter *) * (inevitable_ending));
	if (dejavu == NULL)
		return (NULL);
	day = 0;
	while (day < inevitable_ending)
	{
		dejavu[day] = NULL;
		day += 1;
	}
	return (dejavu);
}

void	*subliminal_stimuli(t_chapter **dejavu, int event, size_t eclipse)
{
	size_t		day;
	t_chapter	*rabbit_hole;

	day = the_wheel_of_fortune(event, eclipse);
	if (dejavu[day] == NULL)
	{
		dejavu[day] = write_a_chapter(event);
		if (dejavu[day] == NULL)
			lost_time_memory(dejavu, eclipse);
		return (NULL);
	}
	rabbit_hole = dejavu[day];
	while (rabbit_hole->future != NULL)
		rabbit_hole = rabbit_hole->future;
	rabbit_hole->future = write_a_chapter(event);
	if (rabbit_hole->future == NULL)
		lost_time_memory(dejavu, eclipse);
	return (NULL);
}

char	have_i_seen_this_before(t_chapter **dejavu, int event, size_t eclipse)
{
	size_t		day;
	t_chapter	*rabbit_hole;

	day = the_wheel_of_fortune(event, eclipse);
	rabbit_hole = dejavu[day];
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

// or history_repeat_itself
char	kagerou_day(int *events, size_t time)
{
	size_t		i;
	char		is_dejavu;
	t_chapter	**memory;
	size_t		eclipse;

	is_dejavu = 0;
	eclipse = wait_next_eclipse(time);
	memory = rumination(time);
	if (memory == NULL)
		return (0);
	i = 0;
	while (i < time && is_dejavu == 0)
	{
		if (have_i_seen_this_before(memory, events[i], eclipse) == 1)
			is_dejavu = 1;
		subliminal_stimuli(memory, events[i], eclipse);
		i += 1;
	}
	lost_time_memory(memory, eclipse);
	return (is_dejavu);
}

/*
int	main(int ac, char **arr)
{
	size_t		i;
	int			*events;
	char		is_dejavu;
	char		e;
	t_chapter	**dejavu;
	size_t		eclipse;

	is_dejavu = 0;
	if (ac < 2)
		return (0);
	e = 'K';
	events = write_biography(ac - 1, arr + 1, &e);
	if (e == 'E' || events == NULL)
		return (0);
	eclipse = wait_next_eclipse(ac);
	dejavu = rumination(ac);
	if (dejavu == NULL)
	{
		free(events);
		return (0);
	}
	i = 0;
	while (i < ac - 1)
	{
		if (have_i_seen_this_before(dejavu, events[i], eclipse) == 1)
		{
			i = ac;
			is_dejavu = 1;
		}
		subliminal_stimuli(dejavu, events[i], eclipse);
		i += 1;
	}
	free(events);
	lost_time_memory(dejavu, eclipse);
	if (is_dejavu == 1)
		write(1, "Duplication\n", 12);
	else
		write(1, "Unique\n", 7);
	return (0);
}
*/
