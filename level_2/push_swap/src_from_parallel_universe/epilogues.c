/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epilogues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:57:47 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/27 18:58:55 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(n)
// space: O(1)
char	the_weir_egg_realization(t_yin_yang *story)
{
	t_chapter	*memory;

	if (story == NULL)
		return (0);
	if (story->them != NULL || story->me == NULL)
		return (0);
	memory = story->me;
	while (memory->future != NULL)
	{
		if (memory->moment > memory->future->moment)
			return (0);
		memory = memory->future;
	}
	return (1);
}

// time : O(n log(log(n)))
// space: O(n)
t_yin_yang	*seven_years(size_t time, char **memory)
{
	int			*biography;
	int			err;
	t_yin_yang	*story;

	err = 'K';
	biography = write_biography(time, memory, &err);
	if (biography == NULL)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	if (err == 'E' || kagerou_day(biography, time) == 1)
	{
		free(biography);
		write(1, "Error\n", 6);
		return (NULL);
	}
	story = write_backstory(time, biography);
	free(biography);
	if (story == NULL)
		write(1, "Error\n", 6);
	return (story);
}

// time : O(n log(n))
// space: O(n)
int	main(int time, char **memory)
{
	t_yin_yang	*story;

	if (time < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	story = seven_years(time - 1, memory + 1);
	if (story == NULL)
		return (0);
	the_illusion_of_separation(story, 0);
	if (the_weir_egg_realization(story) == 1)
		write(1, "Sort Correctly\n", 15);
	else
		write(1, "Sort Incorrectly\n", 17);
	memento_mori(story->me);
	memento_mori(story->them);
	free(story);
	return (0);
}
