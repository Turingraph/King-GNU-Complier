#include "push_swap.h"

void	arc_prioritize(t_yin_yang *story, char mode, char secret)
{
	if (story->me != NULL && (mode == 0 || mode == 2))
		act_prioritize(story->me->first, story->me->first->future);
	if (story->them != NULL && (mode == 1 || mode == 2))
		act_prioritize(story->them->first, story->them->first->future);
	if (mode == 0 && secret != 1 &&
		story->me->first != NULL &&
		story->me->first->future != NULL)
		write(1, "sa\n", 3);
	if (mode == 1 && secret != 1 &&
		story->them->first != NULL &&
		story->them->first->future != NULL)
		write(1, "sb\n", 3);
	if (mode == 2 && secret != 1 &&
		story->me->first != NULL &&
		story->me->first->future != NULL &&
		story->them->first != NULL &&
		story->them->first->future != NULL)
		write(1, "ss\n", 3);
}

void	arc_dialog(t_yin_yang *story, char mode, char secret)
{
	if (story->them != NULL && mode == 0)
	{
		story->me->n_chapters += 1;
		story->them->n_chapters -= 1;
		act_dialog(&(story->me->first), &(story->them->first));
		if (secret != 1)
			write(1, "pa\n", 3);
	}
	if (story->me != NULL && mode == 1)
	{
		story->me->n_chapters -= 1;
		story->them->n_chapters += 1;
		act_dialog(&(story->them->first), &(story->me->first));
		if (mode == 1 && secret != 1)
			write(1, "pb\n", 3);
	}
	if (mode == 2)
		write(1, "**INVALID**", 11);
}

void	arc_outside_box(t_yin_yang *story, char mode, char secret)
{
	if (story->them != NULL && (mode == 0 || mode == 2))
		act_outside_box(&(story->me));
	if (story->me != NULL && (mode == 1 || mode == 2))
		act_outside_box(&(story->them));
	if (mode == 0 && secret != 1)
		write(1, "ra\n", 3);
	if (mode == 1 && secret != 1)
		write(1, "rb\n", 3);
	if (mode == 2 && secret != 1)
		write(1, "rr\n", 3);
}
