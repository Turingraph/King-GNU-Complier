/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:56:58 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/29 16:41:41 by phsottat         ###   ########.fr       */
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

void    reading_book(t_chapter *diary)
{
	while (diary != NULL)
	{
		translation(1, diary->moment);
		write(1, "\n", 1);
		diary = diary->future;
	}
}

/*
t_yin_yang	*seven_years(size_t time, char **memory)
{
	int			*biography;
	char		err;
	t_yin_yang	*story;

	err = 'K';
	biography = write_biography(time, memory, &err);
	if (err == 'E')
	{
		write(1, "Input is invalid\n", 17);
		return (NULL);
	}
	if (biography == NULL)
	{
		write(1, "Malloc Fail\n", 6);
		return (NULL);
	}
	story = introduction(time, biography);
	free(biography);
	if (story == NULL)
		write(1, "Error\n", 6);
	return (story);
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
	reading_book(me->last);
	reading_book(me->first);
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
	reading_book(me->last);
	reading_book(me->first);
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
	reading_book(story->me->last);
	reading_book(story->me->first);
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
	reading_book(them->last);
	reading_book(them->first);
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

//	*	sieve_of_eratosthenes
//	*	wait_next_eclipse
//	*	numerology
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
	// translation(1, day);
	// write(1, "^", 1);
	// translation(1, eclipse);
	// write(1, " = ", 3);
	// translation(1, numerology(day, eclipse));
	// write(1, "\n", 1);
	return (0);
}

//----------------------------------------------------------

/*
cc -Wall -Wextra -Werror main.c push_swap

valgrind --leak-check=full ./a.out 
*/
