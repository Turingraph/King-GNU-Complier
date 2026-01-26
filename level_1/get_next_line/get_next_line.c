/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:26:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/01/26 09:24:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// time : O(n)
// space: O(1)
size_t	knight_of_coin(char *str, char stop)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0' && *(str + i) != stop)
		i += 1;
	return (i);
}

// time : O(n)
// space: O(n)
char	the_chariot(int fd, t_temperance **angel, char *ambition)
{
	char	*coin;
	char	knight;

	if (*ambition == '0')
		return (0);
	knight = 'g';
	while (knight == 'g')
	{
		coin = ace_of_coin("\0", 0, BUFFER_SIZE);
		if (coin == NULL)
			return (1);
		read(fd, coin, BUFFER_SIZE);
		if (three_of_cups(angel, coin) == NULL)
			return (1);
		if (knight_of_coin(coin, '\0') < BUFFER_SIZE)
			*ambition = '0';
		if (knight_of_coin(coin, '\n') < BUFFER_SIZE)
			knight = 'r';
		free(coin);
	}
	return (0);
}

// time : O(n)
// space: O(n)
static inline char	*king_gnl(int fd)
{
	t_temperance	*angel;
	char			*knight;
	size_t			length;
	static char		*coin = NULL;
	static char		ambition = '1';

	angel = ace_of_cup(1, 1);
	if (coin != NULL && angel != NULL)
		three_of_cups(&angel, coin);
	if (coin != NULL)
		free(coin);
	if (angel == NULL)
		return (NULL);
	if (the_chariot(fd, &angel, &ambition) == 1)
		return (NULL);
	length = knight_of_coin(angel->arr, '\n');
	if (*(angel->arr + length) != '\0')
		length += 1;
	knight = ace_of_coin(angel->arr, length, length);
	coin = ace_of_coin(angel->arr + length, angel->length - length,
			angel->length - length);
	free(angel->arr);
	free(angel);
	return (knight);
}

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE == 0)
		return (NULL);
	return (king_gnl(fd));
}
