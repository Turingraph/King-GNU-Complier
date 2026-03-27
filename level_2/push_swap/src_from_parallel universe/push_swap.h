/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:15:47 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/27 18:45:45 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

// mc = a -> me
// mc = b -> them
// mc = c -> us

// arc.c
void		arc_prioritize(t_chapter *now, t_chapter *later);
void		arc_dialog(t_chapter **listener, t_chapter **speaker);
void		arc_outside_box(t_vision **perspective);

// backstory.c
t_yin_yang	*write_backstory(size_t n_chapters, char **imagine, char *err);
size_t		reincarnation(t_vision **original_time, t_vision **parallel_time,
				t_yin_yang *story, char *whoami);

// biography.c
int			*write_biography(size_t n_chapters, char **imagine, char *err);
void		burning_memory(t_chapter *memory);
t_chapter	*write_a_chapter(int moment);

// dejavu.c
char		kagerou_day(int *events, size_t time);

// eclipse.c
char		is_eclipse(size_t sun);
size_t		wait_next_eclipse(size_t today);
size_t		the_wheel_of_fortune(int event, size_t eclipse);

// tale.c
void		say_story(char arc, char mc, char secret);
void		show_story(char *me, char *them, char *secret, char tale);
void		say_prioritize(t_yin_yang *story, char mc, char secret);
void		say_dialog(t_yin_yang *story, char mc, char secret);
void		say_outside_box(t_yin_yang *story, char mc, char secret);

// the_illusion_of_separation.c

#endif
