#include"push_swap.h"

t_chapter	*write_diary(size_t n_chapters, int *record, t_vision **mc)
{
	t_chapter	*chapter;
	size_t		i;

	(*mc)->first = write_a_chapter(record[0]);
	if ((*mc)->first == NULL)
		return (NULL);
	chapter = (*mc)->first;
	i = 1;
	while (i < n_chapters)
	{
		chapter->future = write_a_chapter(record[i]);
		if (chapter->future == NULL)
		{
			burning_memory((*mc)->first);
			return (NULL);
		}
		chapter = chapter->future;
		i += 1;
	}
	(*mc)->n_chapters = n_chapters;
	(*mc)->last = chapter;
	return (chapter);
}

t_yin_yang	*study_me(size_t n_chapters, int *record, t_vision **mc)
{
	t_yin_yang	*story;
	size_t		i;
	t_chapter	*last;

	story = (t_yin_yang *)malloc(sizeof(t_yin_yang));
	if (story == NULL)
		return (NULL);
	last = write_diary(n_chapters, record, mc);
	if (last == NULL)
	{
		burning_memory((*mc)->first);
		free(*mc);
		free(story);
		return (NULL);
	}
	story->tree_of_life = 2;
	story->seasons = 0;
	story->me = *mc;
	story->them = NULL;
	return (story);
}

t_yin_yang	*write_backstory(size_t n_chapters, char **imagine, char *err)
{
	t_yin_yang	*story;
	int			*record;
	t_vision	*mc;

	mc = (t_vision *)malloc(sizeof(t_vision));
	if (mc == NULL)
	{
		free(story);
		return (NULL);
	}
	record = write_biography(n_chapters, imagine, err);
	if (record == NULL)
		return (NULL);
	if (*err == 'E')
		return (NULL);
	story = study_me(n_chapters, record, &mc);
	return (story);
}
