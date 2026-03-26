#ifndef DEJAVU_H
# define DEJAVU_H

# include <unistd.h>
# include <stdlib.h>

typedef struct t_dream
{
	size_t	moment;
	size_t	hallucination;
	t_dream	*future;
}	t_dream;

size_t	dijkstra_dream(size_t wake_up);

#endif
