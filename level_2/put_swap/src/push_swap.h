#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
To Do List
1.	implementing push_hash_table
2.	implementing prime finding algorithm
3.	implementing is_in_hash_table
4.	arc_prelude
5.	implementing linked list merge sort.
*/

# include <unistd.h>
# include <stdlib.h>

typedef struct t_chapter
{
	int			moment;
	t_chapter	*future;
}	t_chapter;

typedef struct t_vision
{
	t_chapter	*first;
	t_chapter	*last;
	size_t		n_chapters;
}	t_vision;

typedef struct t_yin_yang
{
	t_vision	*me;
	t_vision	*them;
	size_t		tree_of_life;
	size_t		seasons;
}	t_yin_yang;

// mode = 0 -> me
// mode = 1 -> them
// mode = 2 -> us

// act.c
void		act_prioritize(t_chapter *now, t_chapter *later);
void		act_dialog(t_chapter **listener, t_chapter **speaker);
void		act_outside_box(t_vision **perspective);

// arc.c
void		arc_prioritize(t_yin_yang *story, char mode, char is_tell);
void		arc_dialog(t_yin_yang *story, char mode, char is_tell);
void		arc_outside_box(t_yin_yang *story, char mode, char is_tell);

// backstory.c
t_yin_yang	*write_backstory(size_t n_chapters, char **imagine, char *err);

// biography.c
int			*write_biography(size_t n_chapters, char **imagine, char *err);
void		burning_memory(t_chapter *memory);
t_chapter	*write_a_chapter(int moment);

// dejavu.c
char		kagerou_day(int *events, size_t time);

// eclipse.c
char		is_eclipse(size_t sun);
size_t		get_next_eclipse(size_t today);
size_t		the_wheel_of_fortune(int event, size_t eclipse);

// the_illusion_of_separation.c

#endif
