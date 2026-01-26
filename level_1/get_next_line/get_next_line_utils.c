/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:26:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/01/26 09:24:28 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// time : O(n)
// space: O(n)
char	*ace_of_coin(char *src, size_t length, size_t capacity)
{
	char	*dst;
	size_t	i;

	if (capacity == 0 || capacity < length)
		return (NULL);
	dst = malloc(sizeof(char) * (capacity + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < length && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i += 1;
	}
	while (i <= capacity)
	{
		*(dst + i) = '\0';
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_temperance	*ace_of_cup(size_t capacity, char create_arr)
{
	t_temperance	*cup;

	if (capacity == 0)
		return (NULL);
	cup = malloc(sizeof(t_temperance));
	if (cup == NULL)
		return (NULL);
	cup->capacity = capacity;
	cup->length = 0;
	cup->arr = NULL;
	if (create_arr == 0)
		return (cup);
	cup->arr = ace_of_coin("\0", 0, capacity);
	if (cup->arr == NULL)
	{
		free(cup);
		return (NULL);
	}
	return (cup);
}

// time : O(1)
// space: O(1)
// worse time : O(n)
// worse space: O(n)
static inline t_temperance	*two_of_cups(t_temperance **left_cup, char c)
{
	t_temperance	*right_cup;

	if ((*left_cup)->length < (*left_cup)->capacity)
	{
		*((*left_cup)->arr + (*left_cup)->length) = c;
		(*left_cup)->length += 1;
		return (*left_cup);
	}
	right_cup = ace_of_cup((*left_cup)->capacity * 2, 0);
	if (right_cup == NULL)
		return (NULL);
	right_cup->arr = ace_of_coin(
			(*left_cup)->arr, (*left_cup)->length,
			(*left_cup)->capacity * 2);
	if (right_cup->arr == NULL)
	{
		free(right_cup);
		return (NULL);
	}
	right_cup->length = (*left_cup)->length;
	free((*left_cup)->arr);
	free((*left_cup));
	*left_cup = right_cup;
	return (two_of_cups(left_cup, c));
}

// time : O(n)
// space: O(n)
t_temperance	**three_of_cups(t_temperance **group, char *friends)
{
	size_t	i;

	i = 0;
	while (*(friends + i) != '\0')
	{
		if (two_of_cups(group, *(friends + i)) == NULL)
		{
			free(friends);
			free((*group)->arr);
			free((*group));
			*group = NULL;
			return (NULL);
		}
		i += 1;
	}
	return (group);
}
