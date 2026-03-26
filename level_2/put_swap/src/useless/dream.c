#include "dejavu.h"

void	losstime_memory(t_dream *memory)
{
	t_dream	*time;

	if (memory != NULL)
	{
		while (memory->future != NULL)
		{
			time = memory->future;
			free(memory);
			memory = time;
		}
		free(memory);
	}
}

t_dream	*dreaming(size_t view)
{
	t_dream	*qualia;

	qualia = (t_dream *)malloc(sizeof(t_dream));
	if (qualia == NULL)
		return (NULL);
	qualia->moment = view;
	qualia->hallucination = view * view;
	qualia->future = NULL;
	return (qualia);
}

// https://youtu.be/fwxjMKBMR7s?si=cyJSeCjAYWgC5Zuf
size_t	dijkstra_dream(size_t wake_up)
{
	t_dream	*ego_memory;
	t_dream	*id_memory;
	size_t	i;

	ego_memory = dreaming(3);
	if (ego_memory == NULL)
		return (0);
	id_memory = ego_memory;
	i = 5;
	while (i <= wake_up)
	{
		i += 1;
	}
	return (0);
}
