#include "appendix.h"

// time : O(n)
// space: O(n)
char	*determinism(size_t time)
{
	size_t	day;
	size_t	circle_of_life;
	char	*sieve;

	if (time == 0)
		return (NULL);
	sieve = (char *)malloc(sizeof(char) * time);
	if (sieve == NULL)
		return (NULL);
	sieve[0] = 1;
	circle_of_life = 1;
	while (circle_of_life <= time)
	{
		day = 0;
		while (day < circle_of_life && circle_of_life + day < time)
		{
			sieve[circle_of_life + day] = (char)(((int) sieve[day]) * (-1) + 1);
			day += 1;
		}
		if (circle_of_life + day >= time)
			circle_of_life = time + 1;
		circle_of_life *= 2;
	}
	return (sieve);
}

/*
// time : O(n)
// space: O(n)
char	*god_dont_play_dice(t_yin_yang *story)
{
	char		*sieve;
	size_t		day;
	size_t		moment;
	t_chapter	*chapter;
	
	if (story->me->time < 1)
		return (0);
	sieve = (char *)malloc(sizeof(char) * (story->me->time / 4));
	if (sieve == NULL)
		return (NULL);
	determinism(sieve, story->me->time / 4);
	chapter = story->me->first;
	day = 0;
	while (day < story->me->time / 4)
	{
		moment = 0;
		while (4 * day + moment < 5 * day && 4 * day + moment < story->me->time && chapter != NULL)
		{
			chapter->super_position = sieve[day];
			chapter = chapter->future;
			moment += 1;
		}
		if (4 * day + moment >= story->me->time)
			day = story->me->time / 4;
		day += 1;
	}
	return (sieve);
}*/

// time : O(1)
// space: O(1)
void	entanglement(t_yin_yang *story, char secret, int circle, char last)
{
	char	me;
	char	them;

	me = 0;
	them = 0;
	if (story->me->first != NULL && story->me->first->future != NULL
		&& story->me->first->moment * circle < story->me->first->future->moment * circle)
		me = 1;
	if (story->them->first != NULL && story->them->first->future != NULL && last == 0
		&& story->them->first->moment * circle < story->them->first->future->moment * circle)
		them = 1;
	if (me == 1 && them == 1)
	{
		arc_prioritize(story->me->first, story->me->first->future, 'A');
		arc_prioritize(story->them->first, story->them->first->future, 'B');
		if (secret != 1)
			arc_story('s', 's', 0);
	}
	if (me == 1 && them == 0)
		arc_prioritize(story->me->first, story->me->first->future,
			'a' - secret * ('a' - 'A'));
	if (me == 0 && them == 1)
		arc_prioritize(story->them->first, story->them->first->future,
			'b' - secret * ('b' - 'B'));
}

// mode = 'b', 'B', 1, -1
// time : O(n)
// space: O(1)
void	observer_effect(t_yin_yang *story, int mode, size_t shift,
	size_t tfihs)
{
	while (story->me->first != NULL && shift > 0 && tfihs > 0)
	{
		if (story->me->first->moment >= story->them->first->moment)
			tfihs -= arc_conversation(&story->them,
					&story->me, whoami, 1);
		else
			shift -= 1;
		arc_reflection(&story->them, whoami);
	}
	while (shift > 0)
	{
		arc_reflection(&story->them, whoami);
		shift -= 1;
	}
	while (story->me->first != NULL && tfihs > 0)
	{
		arc_conversation(&story->them, &story->me, whoami, 1);
		arc_reflection(&story->them, whoami);
		tfihs -= 1;
	}
}

// time : O(n)
// space: O(n)
char	*existential_crisis(t_yin_yang *story, char secret)
{
	char	whoami;
	size_t	day;
	char	*sieve;
	size_t	time;

	time = story->me->time;
	sieve = determinism(time / 4 + 1);
	day = 0;
	whoami = 'b' + secret * ('a' - 'A');
	while (day < time / 4)
	{
		arc_conversation(&story->them, &story->me, whoami, 2);
		entanglement(story, secret, 2 * ((int) sieve[day]) - 1, 0);
		arc_conversation(&story->them, &story->me, whoami, 2);
		day += 1;
	}
	day = 0;
	if (time % 4 >= 2)
	{
		entanglement(story, secret, 2 * ((int) sieve[time / 4]) - 1, 1);
		day = arc_conversation(&story->them, &story->me, whoami, 2);
	}
	if (time % 4 > 0)
		observer_effect(story, whoami, day, story->me->time);
	story->life_tree = 4;
	return (sieve);
}

