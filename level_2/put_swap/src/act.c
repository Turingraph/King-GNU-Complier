#include "push_swap.h"

// time : O(1)
// space: O(1)
void	act_prioritize(t_chapter *now, t_chapter *later)
{
	int	prioritize;

	if (now != NULL & later != NULL)
	{
		prioritize = now->moment;
		now->moment = later->moment;
		later->moment = prioritize;
	}
}

// time : O(1)
// space: O(1)
void	act_dialog(t_chapter **listener, t_chapter **speaker)
{
	t_chapter	*diary;

	if ((*speaker) != NULL)
	{
		diary = (*listener);
		(*listener) = (*speaker);
		(*speaker) = (*speaker)->future;
		(*listener)->future = diary;
	}
}

// time : O(1)
// space: O(1)
void	act_outside_box(t_vision **perspective)
{
	t_chapter	*the_hanged_man;

	(*perspective)->last->future = (*perspective)->first;
	the_hanged_man = (*perspective)->first;
	(*perspective)->first = (*perspective)->first->future;
	(*perspective)->last = the_hanged_man;
	(*perspective)->last->future = NULL;
}
