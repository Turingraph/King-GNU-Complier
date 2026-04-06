#include "appendix.h"

// time : O(1)
// space: O(1)
void	arc_prioritize(t_yin_yang *story, char secret)
{
	char	me;
	char	them;

	me = 0;
	them = 0;
	if (story->me->first != NULL && story->me->first->future != NULL
		&& story->me->first->moment < story->me->first->future->moment)
		me = 1;
	if (story->them->first != NULL && story->them->first->future != NULL
		&& story->them->first->moment < story->them->first->future->moment)
		them = 1;
	if (me == 1 && them == 1)
	{
		say_prioritize(story->me->first, story->me->first->future, 'A');
		say_prioritize(story->me->first, story->me->first->future, 'B');
		if (secret != 1)
			say_story('s', 's', 0);
	}
	if (me == 1 && them == 0)
		say_prioritize(story->me->first, story->me->first->future, 'a' - secret * ('a' - 'A'));
	if (me == 0 && them == 1)
		say_prioritize(story->me->first, story->me->first->future, 'b' - secret * ('b' - 'B'));
}

// time : O(1)
// space: O(1)
void	arc_first_to_be_continue(t_yin_yang *story, char whoami, size_t time)
{
	if (time % 4 >= 2
		&& story->me->first != NULL && story->me->first->future != NULL
		&& story->me->first->moment > story->me->first->future)
	{
		say_prioritize(story->me->first, story->me->first->future, whoami - 1);
		say_conversation(&story->them, &story->me, whoami);
		say_conversation(&story->them, &story->me, whoami);
		observer_effect(story, whoami, 2, story->me->time);
	}
	if (time % 4 == 1)
	{
		say_conversation(&story->them, &story->me, whoami);
		say_reflection(&story->them, whoami);
	}
}

// time : O(n)
// space: O(1)
void	arc_to_be_continue(t_yin_yang *story, char whoami, size_t time)
{
	if (time % 4 >= 2
		&& story->me->first != NULL && story->me->first->future != NULL
		&& story->me->first->moment > story->me->first->future)
	{
		say_prioritize(story->me->first, story->me->first->future, whoami - 1);
		say_conversation(&story->them, &story->me, whoami);
		say_conversation(&story->them, &story->me, whoami);
		observer_effect(story, whoami, 2, story->me->time);
	}
	if (time % 4 == 1)
	{
		say_conversation(&story->them, &story->me, whoami);
		say_reflection(&story->them, whoami);
	}
}
