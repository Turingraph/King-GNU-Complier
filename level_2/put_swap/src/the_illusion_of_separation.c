#include "push_swap.h"

void	wtc_prelude_in_c_minor(t_yin_yang *story, char secret)
{
	size_t	i;

	i = 0;
	while (story->me->n_chapters > 1)
	{
		if (story->me->first->moment > story->me->first->future->moment && i % 2 == 0)
			arc_prioritize(story, 0, secret);
		if (story->me->first->moment < story->me->first->future->moment && i % 2 == 1)
			arc_prioritize(story, 0, secret);
		arc_dialog(story, 1, secret);
		arc_dialog(story, 1, secret);
		i += 1;
	}
	arc_dialog(story, 1, secret);
	story->tree_of_life = 4;
	if (story->them->n_chapters % 2 == 1)
		arc_outside_box(story, 1, secret);
}

void	silk_road(t_yin_yang *story, char secret)
{}

void	the_illusion_of_separation(t_yin_yang *story, char secret)
{
	size_t	ending;

	wtc_prelude_in_c_minor(story, secret);
	ending = story->them->n_chapters;
	while (story->tree_of_life <= ending)
	{
		silk_road(story, secret);
		if (story->me->n_chapters > story->them->n_chapters)
			ending = story->me->n_chapters;
		else
			ending = story->them->n_chapters;
	}
}

/*
a: 4 2 35 5 131 3 77
b:

a: 2 4 35 5 131 3 77
b:

a: 35 5 131 3 77
b: 4 2
*/

///////////////////////////////////////////////////////////////////////////

/*
a: 4 2 35 5 131 3 77
b:

a: 2 4 35 5 131 3 77
b:

a: 35 5 131 3 77
b: 4 2

a: 131 3 77
b: 5 35 4 2

a: 3 131 77
b: 5 35 4 2

a: 77
b: 131 3 5 35 4 2

a:
b: 77 131 3 5 35 4 2

a:
b: 131 3 5 35 4 2 77
*/

/*
a:
b: 131 3 5 35 (4 2 77)

a: 3 131
b: 5 35 (4 2 77)

a: 3 131
b: 35 (4 2 77) 5

a: 131
b: 3 35 (4 2 77) 5

a: 131
b: 35 (4 2 77) 5 3

a: 131
b: (4 2 77) 5 3 35

a: 
b: 131 (4 2 77) 5 3 35

a: 
b: (4 2 77) 5 3 35 131
*/

/*
a:
b: 4 2 77 (5 3 35 131)

a: 4
b: 2 77 (5 3 35 131)

a: 4
b: 77 (5 3 35 131) 2

a: 
b: 4 77 (5 3 35 131) 2

a: 
b: 77 (5 3 35 131) 2 4

a: 
b: (5 3 35 131) 2 4 77
*/

/*
a: 
b: 5 3 35 131 2 4 77

a: 5
b: 3 35 131 2 4 77

a: 3 5
b: 35 131 2 4 77

a: 35 3 5
b: 131 2 4 77

a: 131 35 3 5
b: 2 4 77

a: 131 35 3 5
b: 2 4 77
*/

///////////////////////////////////////////////////////////////////////////
/*
a: 4 3 1 2 ...
b: 

a: 1 2 ...
b: 3 4

a: 2 ... 1
b: 3 4

a: ... 1 2
b: 3 4

a: 3 ... 1 2
b: 4

a: ... 1 2 3
b: 4

a: 4 ... 1 2 3
b: 

a: ... 1 2 3 4
b: 
*/
