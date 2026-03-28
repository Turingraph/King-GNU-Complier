/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biography.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:29:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/27 17:18:28 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "appendix.h"

// time : O(1)
// space: O(1)
long int	first_draft(char *src, char *err, size_t *digit, size_t sign)
{
	long int	y;

	y = 0;
	while (src[*digit] != '\0' && *digit < 11 + sign && *err != 'E')
	{
		if (digit == sign && src[*digit] == '0')
			*err = 'E';
		else if (src[*digit] >= '0' && src[*digit] <= '9')
			y += (long int)(src[*digit] - '0');
		else
			*err = 'E';
		*digit += 1;
		y *= 10;
	}
	y /= 10;
	return (y);
}

// time : O(1)
// space: O(1)
int	edited_draft(char *src, char *err)
{
	long int	y;
	size_t		digit;
	size_t		sign;

	digit = 0;
	sign = 0;
	if (src[digit] == '-')
		sign = 1;
	digit = sign;
	y = first_draft(src, err, &digit, sign);
	if (sign == 1)
		y *= -1;
	if (src[digit] != '\0' && digit >= 11 + sign)
	{
		*err = 'E';
		return (-1);
	}
	if (y < -2147483648 || y > 2147483647)
	{
		*err = 'E';
		return (-1);
	}
	return ((int) y);
}

// time : O(n)
// space: O(n)
int	*write_biography(size_t n_chapters, char **imagine, char *err)
{
	int		*record;
	size_t	i;

	record = (int *)malloc(sizeof(int) * (n_chapters));
	if (record == NULL)
		return (NULL);
	i = 0;
	while (i < n_chapters)
	{
		record[i] = edited_draft(imagine, err);
		if (*err == 'E')
		{
			free(record);
			return (NULL);
		}
		i += 1;
	}
	return (record);
}

// time : O(n)
// space: O(1)
void	memento_mori(t_chapter *memory)
{
	t_chapter		*time;

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

// time : O(1)
// space: O(1)
t_chapter	*write_a_chapter(int moment)
{
	t_chapter	*record;

	record = (t_chapter *)malloc(sizeof(t_chapter));
	if (record == NULL)
		return (NULL);
	record->future = NULL;
	record->moment = moment;
	return (record);
}
