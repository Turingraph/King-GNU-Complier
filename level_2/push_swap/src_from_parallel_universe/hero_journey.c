#include "appendix.h"

// time : O(n)
// space: O(1)
void	time_machine(t_vision **original_time,
		t_vision **parallel_time, char whoami, size_t time)
{
	size_t	day;

	day = 0;
	while (day < time && original_time != NULL)
	{
		say_conversation(parallel_time, original_time, whoami, 1);
		if ((*parallel_time)->first != NULL)
			say_reflection(parallel_time, whoami);
		day += 1;
	}
}

// time : O(n)
// space: O(1)
void	observer_effect(t_yin_yang *story, char whoami, size_t shift,
	size_t tfihs)
{
	t_vision	*original_time;
	t_vision	*parallel_time;

	whoami = reincarnation(&original_time, &parallel_time, story, &whoami);
	while (parallel_time->first != NULL && shift > 0 && tfihs > 0)
	{
		if (parallel_time->first->moment >= original_time->first->moment)
		{
			say_conversation(&original_time, &parallel_time, whoami, 1);
			tfihs -= 1;
		}
		else
			shift -= 1;
		say_reflection(&original_time, whoami);
	}
	while (shift > 0)
	{
		say_reflection(&original_time, whoami);
		shift -= 1;
	}
	while (parallel_time->first != NULL && tfihs > 0)
	{
		say_conversation(&original_time, &parallel_time, whoami, 1);
		say_reflection(&original_time, whoami);
		tfihs -= 1;
	}
}

// time : O(n)
// space: O(1)
void	existential_crisis(t_yin_yang *story, char secret)
{
	size_t	day;
	size_t	time;
	char	whoami;

	whoami = 'b' - secret * ('b' - 'B');
	day = 0;
	time = story->me->time;
	while (day < time / 4)
	{
		say_conversation(&story->them, &story->me, whoami, 2);
		arc_prioritize(story, secret);
		observer_effect(story, whoami, 2, 2);
		day += 1;
	}
	day = 0;
	if (time % 4 >= 2 && story->me->first->moment > story->me->first->future)
	{
		say_prioritize(story->me->first, story->me->first->future, whoami - 1);
		say_conversation(&story->them, &story->me, whoami, 2);
		day = 2;
	}
	if (time % 4 > 0)
		observer_effect(story, whoami, day, story->me->time);
	story->life_tree = 4;
}

// time : O(n)
// space: O(1)
void	hero_journey(t_yin_yang *story, char *whoami)
{
	size_t		day;
	size_t		time;
	t_vision	*original_time;
	t_vision	*parallel_time;
	char		whoiam;

	whoiam = reincarnation(&original_time, &parallel_time, story, whoami);
	day = 0;
	time = story->me->time;
	while (day < time / (story->life_tree * 2))
	{
		time_machine(&original_time, &parallel_time, *whoami, story->life_tree);
		observer_effect(story, whoiam, story->life_tree, story->life_tree);
		day += 1;
	}
	// something similar to existential_crisis.
	// 2 cases including
	//	a.	[time % (story->life_tree * 2) >= story->life_tree]
	//	b.	[0 < time % (story->life_tree * 2) < story->life_tree]
	// time_machine(&original_time, &parallel_time, *whoami, story->life_tree);
	// observer_effect(story, whoiam, story->life_tree, time % story->life_tree);
	story->life_tree *= 2;
}
