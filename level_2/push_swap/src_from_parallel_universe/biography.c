/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biography.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:29:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/29 16:02:45 by phsottat         ###   ########.fr       */
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
		if (*digit == sign && src[*digit] == '0')
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

	if (src[0] == '0' && src[1] == '\0')
		return (0);
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
int	*write_biography(size_t time, char **imagine, char *err)
{
	int		*biography;
	size_t	day;

	biography = (int *)malloc(sizeof(int) * (time));
	if (biography == NULL)
		return (NULL);
	day = 0;
	while (day < time)
	{
		biography[day] = edited_draft(imagine[day], err);
		if (*err == 'E')
		{
			free(biography);
			return (NULL);
		}
		day += 1;
	}
	return (biography);
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
	t_chapter	*chapter;

	chapter = (t_chapter *)malloc(sizeof(t_chapter));
	if (chapter == NULL)
		return (NULL);
	chapter->future = NULL;
	chapter->moment = moment;
	return (chapter);
}
