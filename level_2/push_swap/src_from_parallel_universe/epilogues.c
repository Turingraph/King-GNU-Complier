/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epilogues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:26:09 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/31 16:00:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

void	translate(int fd, int x)
{
	long	d;
	char	coef;

	d = 1;
	while (d < x)
		d *= 10;
	if (d > x)
		d /= 10;
	while (d > 0)
	{
		coef = x / d + '0';
		write(fd, &coef, 1);
		x = x % d;
		d /= 10;
	}
}

void	translation(int fd, int x)
{
	if (x == 0)
	{
		write(fd, "0", 1);
	}
	else if (x > 0)
	{
		translate(fd, x);
	}
	else if (x == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		write(fd, "-", 1);
		translate(fd, (-1) * x);
	}
}

void	fortune_telling(t_chapter *diary)
{
	while (diary != NULL)
	{
		translation(1, diary->moment);
		write(1, "\n", 1);
		diary = diary->future;
	}
}

void	telepathy(t_chapter *diary)
{
	if (diary == NULL)
		write(1, "NULL\n", 5);
	while (diary != NULL)
	{
		translation(1, diary->moment);
		if (diary->future != NULL)
			write(1, " -> ", 4);
		else
			write(1, "\n", 1);
		diary = diary->future;
	}
}

// time : O(n)
// space: O(1)
void	*the_most_important_thing_in_the_world(t_yin_yang *story)
{
	if (story == NULL)
		return (NULL);
	if (story->me != NULL && story->me->first != NULL)
		memento_mori(story->me->first);
	if (story->me != NULL)
		free(story->me);
	if (story->them != NULL && story->them->first != NULL)
		memento_mori(story->them->first);
	if (story->them != NULL)
		free(story->them);
	free(story);
	return (NULL);
}

/*
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
*/

//----------------------------------------------------------

// *** biography.c ***

/*
//  *   write_biography
//  *   edited_draft
//  *   first_draft
int	main(int time, char **memory)
{
	int		*biography;
	size_t	i;
	char	err;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 12);
		return (0);
	}
	i = 0;
	while (i < (size_t) time - 1)
	{
		translation(1, biography[i]);
		write(1, "\n", 1);
		i += 1;
	}
	free(biography);
	return (0);
}
*/

/*
//	*	memento_mori
//	*	write_a_chapter
int	main(int time, char **memory)
{
	int		    *biography;
	char	    err;
    t_chapter   *first_chapter;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 12);
		return (0);
	}
	first_chapter = write_a_chapter(biography[0]);
    free(biography);
    if (first_chapter == NULL)
    {
		write(1, "Malloc Fail\n", 12);
		return (0);
    }
    translation(1, first_chapter->moment);
    write(1, "\n", 1);
    memento_mori(first_chapter);
	return (0);
}
*/

//----------------------------------------------------------

// *** backstory.c ***
/*
//	*	write_fiction
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_vision	*me;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	me = (t_vision *)malloc(sizeof(t_vision));
	if (me == NULL)
		return (0);
	me->first = write_a_chapter(biography[0]);
	if (me->first == NULL)
	{
		free(me);
		return (0);
	}
	me->time = time - 1;
	me->last = write_fiction(time - 1, biography, me->first);
	if (me->last == NULL)
	{
		free(me);
		return (0);
	}
	write(1, "My Story (", 10);
	translation(1, (int) me->time);
	write(1, ")\n", 2);
	write(1, "Spoiler: ", 9);
	fortune_telling(me->last);
	fortune_telling(me->first);
	memento_mori(me->first);
	free(me);
	free(biography);
	return (0);
}
*/

/*
//	*	study_me
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_vision	*me;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	me = study_me(time - 1, biography);
	if (me == NULL || me->last == NULL)
	{
		free(me);
		return (0);
	}
	write(1, "My Story (", 10);
	translation(1, (int) me->time);
	write(1, ")\n", 2);
	write(1, "Spoiler: ", 9);
	fortune_telling(me->last);
	fortune_telling(me->first);
	memento_mori(me->first);
	free(me);
	free(biography);
	return (0);
}
*/

/*
//	*	introduction
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_yin_yang	*story;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	story = introduction(time - 1, biography);
	free(biography);
	if (story == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	write(1, "My Story (", 10);
	translation(1, (int) story->me->time);
	write(1, ")\n", 2);
	write(1, "Spoiler: ", 9);
	fortune_telling(story->me->last);
	fortune_telling(story->me->first);
	write(1, "Their Story is ", 15);
	if (story->them == NULL)
		write(1, "is the Problem of Other Minds\n", 30);
	else
	{
		memento_mori(story->them->first);
		free(story->them);
		write(1, "is something I know because we have hive mind\n", 46);
	}
	memento_mori(story->me->first);
	free(story->me);
	free(story);
	return (0);
}
*/

/*
//	*	reincarnation
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_yin_yang	*story;
	t_vision	*me;
	t_vision	*them;
	char		ego;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	story = introduction(time - 1, biography);
	free(biography);
	if (story == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	ego = 'b';
	reincarnation(&me, &them, story, &ego);
	write(1, "My Story (", 10);
	translation(1, (int) them->time);
	write(1, ")\n", 2);
	write(1, "Spoiler: ", 9);
	fortune_telling(them->last);
	fortune_telling(them->first);
	write(1, "Their Story is ", 15);
	if (me == NULL)
		write(1, "is the Problem of Other Minds\n", 30);
	else
	{
		memento_mori(me->first);
		free(me);
		write(1, "is something I know because we have hive mind\n", 46);
	}
	write(1, "Plot Twist !\nWe swap our soul!\n", 31);
	memento_mori(them->first);
	free(them);
	free(story);
	return (0);
}
*/

//----------------------------------------------------------

// *** eclipse.c ***

/*
//	*	sieve_of_eratosthenes
//	*	wait_next_eclipse
int	main(int time, char **memory)
{
	char	err;
	size_t	eclipse;
	size_t	day;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	day = edited_draft(memory[1], &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	write(1, "Today is ", 9);
	translation(1, day);
	write(1, ".\n", 2);
	eclipse = wait_next_eclipse((size_t) day);
	translation(1, eclipse);
	write(1, " days later, something good will happened to you.\n", 50);
	return (0);
}
*/

//----------------------------------------------------------

// *** dejavu.c ***

/*
//	*	rumination
//	*	have_i_seen_this_before
//	*	subliminal_stimuli
//	*	burning_memory
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_chapter	**dejavu;
	size_t		i;
	size_t		eclipse;
	// t_chapter	*rabbit_hole;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	eclipse = wait_next_eclipse(time);
	if (eclipse == 0)
	{
		free(biography);
		write(1, "Malloc Fail\n", 12);
		return (0);
	}
	else
	{
		translation(1, (int) eclipse);
		write(1, " days left\n", 11);
	}
	dejavu = rumination(eclipse);
	i = 0;
	while (i < (size_t) time - 1)
	{
		subliminal_stimuli(dejavu, biography[i], eclipse);
		i += 1;
	}
	i = 0;
	while (i < eclipse)
	{
		write(1, ">>> ", 4);
		telepathy(dejavu[i]);
		i += 1;
	}
	// rabbit_hole = dejavu[the_wheel_of_fortune(47, eclipse)];
	// telepathy(rabbit_hole);
	if (have_i_seen_this_before(dejavu, 47, eclipse) == (char) 1)
		write(1, "I'm outside Plato Cave.\n", 24);
	else
		write(1, "Plato Cave isn't real.\n", 23);
	burning_memory(dejavu, eclipse);
	free(biography);
	return (0);
}
*/

/*
//	*	kagerou_day
int	main(int time, char **memory)
{
	int			*biography;
	char		err;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	if (kagerou_day(biography, time - 1) == 1)
		write(1, "It happened!\n", 13);
	else
		write(1, "Nope. It not.\n", 14);
	free(biography);
	return (0);
}
*/

//----------------------------------------------------------

// *** arc.c ***

/*
//	*	arc_prioritize
//	*	arc_dialog
//	*	arc_conversation
//	*	arc_reflection
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_yin_yang	*story;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	story = introduction(time - 1, biography);
	free(biography);
	if (story == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	if (story->me == NULL)
	{
		free(story);
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	telepathy(story->me->first);
	write(1, "Prioritize\n", 11);
	arc_prioritize(story->me->first, story->me->first->future);
	telepathy(story->me->first);
	write(1, "Dialog\n", 7);
	arc_conversation(&story->them, &story->me);
	write(1, "Them 1:", 7);
	telepathy(story->them->first);
	write(1, "Me 1:", 5);
	telepathy(story->me->first);

	arc_conversation(&story->them, &story->me);
	write(1, "Them 2:", 7);
	telepathy(story->them->first);
	write(1, "Me 2:", 5);
	telepathy(story->me->first);

	write(1, "Reflection\n", 11);
	arc_reflection(&story->me);
	telepathy(story->me->first);
	arc_reflection(&story->me);
	telepathy(story->me->first);
	if (story->them != NULL)
	{
		memento_mori(story->them->first);
		free(story->them);
	}
	memento_mori(story->me->first);
	free(story->me);
	free(story);
	return (0);
}
*/

//----------------------------------------------------------

// *** tale.c ***

/*
//	*	say_story
int	main(void)
{
	write(1, "sa\n", 3);
	say_story('s', 'a', 0);
	write(1, "\n", 1);
	write(1, "sb\n", 3);
	say_story('s', 'b', 0);
	write(1, "\n", 1);

	write(1, "pa\n", 3);
	say_story('p', 'a', 0);
	write(1, "\n", 1);
	write(1, "pb\n", 3);
	say_story('p', 'b', 0);
	write(1, "\n", 1);

	write(1, "ra\n", 3);
	say_story('r', 'a', 0);
	write(1, "\n", 1);
	write(1, "rb\n", 3);
	say_story('r', 'b', 0);
	write(1, "\n", 1);

	write(1, "ss\n", 3);
	say_story('s', 'c', 0);
	write(1, "\n", 1);
	write(1, "rr\n", 3);
	say_story('r', 'c', 0);
	write(1, "\n", 1);
	return (0);
}
*/

/*
//	*	say_conversation
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_yin_yang	*story;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	story = introduction(time - 1, biography);
	free(biography);
	if (story == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	if (story->me == NULL)
	{
		free(story);
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	telepathy(story->me->first);
	// write(1, "Prioritize\n", 11);
	// arc_prioritize(story->me->first, story->me->first->future);
	// telepathy(story->me->first);
	// write(1, "Dialog\n", 7);
	say_conversation(story, 'b', 0);
	write(1, "Them 1: ", 8);
	telepathy(story->them->first);
	write(1, "Me   1: ", 8);
	telepathy(story->me->first);

	say_conversation(story, 'b', 1);
	write(1, "Them 2: ", 8);
	telepathy(story->them->first);
	write(1, "Me   2: ", 8);
	telepathy(story->me->first);

	// write(1, "Reflection\n", 11);
	// arc_reflection(&story->me);
	// telepathy(story->me->first);
	// arc_reflection(&story->me);
	// telepathy(story->me->first);
	if (story->them != NULL)
	{
		memento_mori(story->them->first);
		free(story->them);
	}
	memento_mori(story->me->first);
	free(story->me);
	free(story);
	return (0);
}
*/

//----------------------------------------------------------

// *** the_illusion_of_separation.c ***

/*
//	*	existential_crisis
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_yin_yang	*story;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	story = introduction(time - 1, biography);
	free(biography);
	if (story == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	if (story->me == NULL)
	{
		free(story);
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	// write(1, "Them 1:", 7);
	// telepathy(story->them->first);
	write(1, "Me   : ", 7);
	telepathy(story->me->first);
	existential_crisis(story, 1);
	write(1, "Them : ", 7);
	telepathy(story->them->first);
	write(1, "Me   : ", 7);
	telepathy(story->me->first);
	memento_mori(story->them->first);
	free(story->me);
	free(story->them);
	free(story);
	return (0);
}
*/

//	*	reverse_time_line
int	main(int time, char **memory)
{
	int			*biography;
	char		err;
	t_yin_yang	*story;

	if (time < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	err = 'K';
	biography = write_biography(time - 1, memory + 1, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (0);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	story = introduction(time - 1, biography);
	free(biography);
	if (story == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	if (story->me == NULL)
	{
		free(story);
		write(1, "Malloc Fail\n", 6);
		return (0);
	}
	reverse_time_line(&story->me, &story->them, 'a', 4);
	write(1, "Me   : ", 7);
	telepathy(story->me->first);
	write(1, "Them : ", 7);
	telepathy(story->them->first);
	the_most_important_thing_in_the_world(story);
	return (0);
}

//----------------------------------------------------------

/*
cc -Wall -Wextra -Werror epilogues.c push_swap

valgrind --leak-check=full ./a.out 1 2 3 4 5 6 7 8 9 10 11
12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50

*/
