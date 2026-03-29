/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:13:15 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/29 12:13:38 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

size_t	f_split_len(char *input, char separator)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != separator)
		{
			while (input[i] != separator && input[i] != '\0')
				i += 1;
			y += 1;
		}
		else
			i += 1;
	}
	return (y);
}

char	*f_create_copy_text(char *input, char stop)
{
	char	*dst;
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	while (input[dst_len] != '\0' && input[dst_len] != stop)
		dst_len += 1;
	dst = (char *)malloc(sizeof(char) * (dst_len + 1));
	if (dst == NULL)
		return (NULL);
	dst[dst_len] = '\0';
	i = 0;
	while (input[i] != '\0' && input[i] != stop)
	{
		dst[i] = input[i];
		i += 1;
	}
	return (dst);
}

void	f_free_nested_string(char **dst, size_t len, size_t i)
{
	i = 0;
	while (i < len)
	{
		free(dst[i]);
		i += 1;
	}
	free(dst);
}

char	**f_split_push(char *input, char separator, char **dst)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != separator)
		{
			dst[j] = f_create_copy_text(input + i, separator);
			if (dst[j] == NULL)
			{
				f_free_nested_string(dst, j, i);
				return (NULL);
			}
			while (input[i] != separator && input[i] != '\0')
				i += 1;
			j += 1;
		}
		else
			i += 1;
	}
	return (dst);
}

char	**f_split(char *input, char separator)
{
	char	**dst;
	size_t	dst_len;

	dst_len = f_split_len(input, separator);
	dst = (char **)malloc(sizeof(char *) * (dst_len + 1));
	if (dst == NULL)
		return (NULL);
	dst[dst_len] = NULL;
	return (f_split_push(input, separator, dst));
}

/*
size_t	f_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

int	main(int ac, char **arr)
{
	char	**dst;
	size_t	len;
	size_t	i;

	if (ac < 2)
		return (0);
	len = f_split_len(arr[1], ' ');
	dst = f_split(arr[1], ' ');
	if (dst == NULL)
	{
		write(1, "dst == NULL\n", 12);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		write(1, dst[i], f_strlen(dst[i]));
		write(1, "\n", 1);
		i += 1;
	}
	i = 0;
	while (i < len)
	{
		free(dst[i]);
		i += 1;
	}
	free(dst);
	return (0);
}
*/

/*
cc -Wall -Wextra -Werror split.c
valgrind --leak-check=full ./a.out " 
Yorushika Yoasobi   Zutomayo Yonezu  JOjo   "
*/
