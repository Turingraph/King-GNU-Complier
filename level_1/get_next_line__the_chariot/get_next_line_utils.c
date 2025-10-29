/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:51:31 by phsottat          #+#    #+#             */
/*   Updated: 2025/10/19 16:44:58 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

// -------------------------------------------------------------------------
// *** WRONG SOLUTION ***
// -------------------------------------------------------------------------

/*
// https://www.geeksforgeeks.org/c/c-program-to-implement-singly-linked-list/

struct s_ll_char	**f_init_ll(struct s_ll_char **head, char *data)
{
	*head = (struct s_ll_char *)malloc(sizeof(struct s_ll_char));
	if (*head == NULL)
		return (NULL);
	(*head)->str = data;
	(*head)->next = NULL;
	return (head);
}

struct s_ll_char	**f_insert_ll_end(struct s_ll_char **head, char *data)
{
	struct s_ll_char	*new_node;
	struct s_ll_char	*temp;

	if (data == NULL)
		return (NULL);
	new_node = (struct s_ll_char *)malloc(sizeof(struct s_ll_char));
	new_node->str = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (head);
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	return (head);
}

char	*f_data(int fd, size_t mod)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (mod));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < mod - 1)
	{
		*(str + i) = '\0';
		i += 1;
	}
	*(str + i) = '\0';
	read(fd, str, mod);
	return (str);
}

size_t	f_strlen(char *str, char stop, size_t *init_y)
{
	while (*(str + *init_y) != '\0' && *(str + *init_y) != stop)
		*init_y += 1;
	if (stop != '\0' && *(str + *init_y) == stop)
		*init_y += 1;
	return (*init_y);
}

struct s_ll_char	*f_ll_char(int fd, size_t mod)
{
	struct s_ll_char	*y;
	struct s_ll_char	*first;
	char				*data;
	size_t				i;

	data = f_data(fd, mod);
	if (data == NULL)
		return (NULL);
	if (f_init_ll(&y, data) == NULL)
	{
		free(data);
		return (NULL);
	}
	first = y;
	i = 0;
	while (f_strlen(data, &i) == mod && data != NULL)
	{
		data = f_data(fd, mod);
		if (data != NULL)
			f_insert_ll_end(&y, data);
		i = 0;
	}
	data = f_data(fd, mod);
	f_insert_ll_end(&y, data);
	return (first);
}
*/

/*
// *** DEBUGGING MODE ***
size_t	f_strlen(char *str, char stop, size_t *init_y)
{
	while (*(str + *init_y) != '\0' && *(str + *init_y) != stop)
	{
		// if (stop == '\n')
			// write(1, (str + *init_y), 1);
		*init_y += 1;
	}
	if (stop != '\0' && *(str + *init_y) == stop)
	{
		// if (stop == '\n')
			// write(1, (str + *init_y), 1);
		*init_y += 1;
	}
	return (*init_y);
}
*/

// -------------------------------------------------------------------------
// *** CORRECT SOLUTION ***
// -------------------------------------------------------------------------

// https://www.geeksforgeeks.org/c/c-program-to-implement-singly-linked-list/

struct s_ll_char	**f_init_ll(struct s_ll_char **head, char *data)
{
	*head = (struct s_ll_char *)malloc(sizeof(struct s_ll_char));
	if (*head == NULL)
		return (NULL);
	(*head)->str = data;
	(*head)->next = NULL;
	return (head);
}

struct s_ll_char	**f_insert_ll_end(struct s_ll_char **head, char *data)
{
	struct s_ll_char	*new_node;
	struct s_ll_char	*temp;

	if (data == NULL)
		return (NULL);
	new_node = (struct s_ll_char *)malloc(sizeof(struct s_ll_char));
	if (new_node == NULL)
		return (NULL);
	new_node->str = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (head);
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	return (head);
}

//	Stop Lv. 0 = last_char
//	Stop Lv. 1 = '\n'
//	Stop Lv. 2 = \0
//	Stop Lv. 3 = NULL

/*
I forgot adding '\0' at the end of string.
So I must add `(sizeof(char) * (mod + 1))` instead of `(sizeof(char) * (mod))`
and I must add `while (i <= mod)` instead of `while (i < mod)`
*/

/*
The leak is happened because I use malloc more than I needed in previous f_data.
*/

char	f_data(int fd, char **dst, size_t mod)
{
	char	proto_dst[mod + 1];
	size_t	i;

	read(fd, *proto_dst, mod);
	i = 0;
	while (i < mod && *(proto_dst + i) != '\n' && *(proto_dst + i) != '\0')
		i += 1;
	*dst = (char *)malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
	{
		free(proto_dst);
		return (3);
	}
	i = 0;
	while (i < mod && *(proto_dst + i) != '\n' && *(proto_dst + i) != '\0')
	{
		*(dst + i) = *(proto_dst + i);
		i += 1;
	}
	*(dst + i) = '\0';
	free(proto_dst);
	if (*(proto_dst + i) == '\n')
		return (1);
	return (dst);
}

/*
char	f_data(int fd, char **dst, size_t mod)
{
	size_t	i;

	*dst = (char *)malloc(sizeof(char) * (mod + 1));
	if (*dst == NULL)
		return (3);
	i = 0;
	while (i <= mod)
	{
		*(*dst + i) = '\0';
		i += 1;
	}
	read(fd, *dst, mod);
	// write(1, *dst, ft_strlen(*dst));
	i = 0;
	while (i < mod)
	{
		if (*(*dst + i) == '\0')
			return (2);
		if (*(*dst + i) == '\n')
			return (1);
		i += 1;
	}
	return (0);
}*/

size_t	f_strlen(char *str, char stop, size_t *init_y, char nine_cups)
{
	while (*(str + *init_y) != '\0' && *(str + *init_y) != stop)
		*init_y += 1;
	if (stop != '\0' && *(str + *init_y) == stop)
		*init_y += 1;
	if (nine_cups == 0)
		*init_y = 0;
	return (*init_y);
}

struct s_ll_char	*f_ll_char(int fd, size_t mod)
{
	struct s_ll_char	*y;
	struct s_ll_char	*first;
	char				*data;
	char				stop_lv;

	stop_lv = f_data(fd, &data, mod);
	if (stop_lv == 3)
		return (NULL);
	if (f_init_ll(&y, data) == NULL)
	{
		free(data);
		return (NULL);
	}
	first = y;
	stop_lv = f_data(fd, &data, mod);
	while (stop_lv == 0
		&& data != NULL)
	{
		f_insert_ll_end(&y, data);
		stop_lv = f_data(fd, &data, mod);
	}
	if (stop_lv == 1 || stop_lv == 2)
		f_insert_ll_end(&y, data);
	return (first);
}

	// write(1, "stop_lv = ", 10);
	// ft_putnbr_fd(stop_lv, 1);
	// write(1, "\n", 1);
