# include "ascii.h"
# include <unistd.h>

size_t	knight_of_coin(char *str, char stop)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0' && *(str + i) != stop)
		i += 1;
	return (i);
}

int	main(int len, char **arr)
{
	if (len < 2)
	{
		write(1, "No Input\n", 9);
		return (0);
	}
	write(1, arr[1], knight_of_coin(arr[1], '\0'));
	write(1, "\n", 1);
	return (0);
}
