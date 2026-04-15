#include "appendix.h"

// time : O(1)
// space: O(1)
void	entanglement(t_yin_yang *story, char secret, int light)
{
	char	me;
	char	them;

	me = 0;
	them = 0;
	if (story->me->first != NULL && story->me->first->future != NULL
		&& story->me->first->moment * light < story->me->first->future->moment * light)
		me = 1;
	if (story->them->first != NULL && story->them->first->future != NULL
		&& story->them->first->moment * light < story->them->first->future->moment * light)
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

void	circle_of_light(t_yin_yang *story)
{
	size_t	day;
	size_t	night;

	night = 1;
	day = 0;
	while (night < story->me->time)
	{
		night *= 2;
		day += 1;
	}
	if (night > story->me->time)
		night /= 2;
}

