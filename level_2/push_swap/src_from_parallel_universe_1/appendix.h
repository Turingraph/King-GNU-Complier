/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendix.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:15:47 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/16 16:11:31 by phsottat         ###   ########.fr       */
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

// 2 * super_position - 1: {0, 1} -> {-1, 1}

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
	size_t		life_tree;
}	t_yin_yang;

// mc = a -> me
// mc = b -> them
// mc = c -> us

// arc.c
void		arc_story(char arc, char mc, char secret);
void		arc_prioritize(t_chapter *now, t_chapter *later, char whoiam);
size_t		arc_conversation(t_vision **listener, t_vision **speaker,
				char whoami, size_t time);
size_t		arc_reflection(t_vision **perspective, char whoami);
size_t		arc_noitcelfer(t_vision **perspective, char whoami);

// backstory.c
void		memento_mori(t_chapter *memory);
t_chapter	*write_a_chapter(int moment);
t_vision	*study_me(size_t time, int *biography);
t_yin_yang	*introduction(size_t time, int *biography);

// biography.c
int			edited_draft(char *src, char *err);
int			*write_biography(size_t time, char **imagine, char *err);

// dejavu.c
void		burning_memory(t_chapter **memory, size_t eclipse);
t_chapter	**rumination(size_t eclipse);
char		subliminal_stimuli(t_chapter **memory, int event, size_t eclipse);
char		have_i_seen_this_before(t_chapter **memory,
				int event, size_t eclipse);
char		kagerou_day(int *events, size_t time);

// eclipse.c
size_t		wait_next_eclipse(size_t today);
size_t		the_wheel_of_fortune(int event, size_t eclipse);

/*
// set_back.c
void		time_machine(t_vision **original_time,
				t_vision **parallel_time, char whoiam, size_t time);
void		observer_effect(t_yin_yang *story, char whoami, size_t shift,
				size_t tfihs);
void		entanglement(t_yin_yang *story, char secret);
void		existential_crisis(t_yin_yang *story, char secret);
void		hero_journey(t_yin_yang *story, char secret);
*/

// hero_journey.c
char		*determinism(size_t time);
void		entanglement(t_yin_yang *story, char secret, int s, char last);
void		observer_effect(t_yin_yang *story, int whoami, size_t shift,
				size_t tfihs);
void		existential_crisis(t_yin_yang *story, char secret, char *sieve);

#endif
