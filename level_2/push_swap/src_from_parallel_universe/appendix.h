/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendix.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:15:47 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/29 16:29:47 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPENDIX_H
# define APPENDIX_H

# include <unistd.h>
# include <stdlib.h>

typedef struct t_chapter
{
	int					moment;
	struct t_chapter	*future;
}	t_chapter;

typedef struct t_vision
{
	t_chapter	*first;
	t_chapter	*last;
	size_t		time;
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
void		arc_reflection(t_vision **perspective);

// backstory.c
t_yin_yang	*introduction(size_t time, int *biography);
size_t		reincarnation(t_vision **original_time, t_vision **parallel_time,
				t_yin_yang *story, char *whoami);

// biography.c
int			edited_draft(char *src, char *err);
int			*write_biography(size_t time, char **imagine, char *err);
void		memento_mori(t_chapter *memory);
t_chapter	*write_a_chapter(int moment);

// dejavu.c
char		kagerou_day(int *events, size_t time);

// eclipse.c
size_t		wait_next_eclipse(size_t today);
size_t		the_wheel_of_fortune(int event, size_t eclipse);
size_t		numerology(size_t a, size_t b);

// tale.c
void		say_story(char arc, char mc, char secret);
void		show_story(char *me, char *them, char *secret, char tale);
void		say_prioritize(t_yin_yang *story, char mc, char secret);
void		say_dialog(t_yin_yang *story, char mc, char secret);
void		say_reflection(t_yin_yang *story, char mc, char secret);

// the_illusion_of_separation.c
// void		the_illusion_of_separation(t_yin_yang *story, char secret);

#endif
