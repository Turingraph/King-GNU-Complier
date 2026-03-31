/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:18:37 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/31 18:41:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// time : O(1)
// space: O(1)
void	arc_swap(t_list *a, t_list *b)
{
	int	temp;

	if (a != NULL & b != NULL)
	{
		temp = a->value;
		a->value = b->value;
		b->value = temp;
	}
}

// time : O(1)
// space: O(1)
void	arc_push_helper(t_list **dst, t_list **src,
			size_t *dst_time, size_t *src_time)
{
	t_list	*temp;

	if ((*src) != NULL)
	{
		temp = (*dst);
		(*dst) = (*src);
		(*src) = (*src)->next;
		(*dst)->next = temp;
		*dst_time += 1;
		*src_time -= 1;
	}
}

// time : O(1)
// space: O(1)
void	arc_push(t_list_h **dst, t_list_h **src)
{
	t_list	*temp;

	if ((*src) != NULL && (*src)->first != NULL)
	{
		if ((*dst) == NULL)
		{
			(*dst) = init_list_h(1, NULL);
			if ((*dst) != NULL)
				arc_push(dst, src);
			else
				free((*dst));
		}
		else if ((*dst) != NULL && (*dst)->first == NULL)
		{
			(*dst)->first = init_list((*src)->first->value);
			(*dst)->last = (*dst)->first;
			temp = (*src)->first;
			(*src)->first = (*src)->first->next;
			free(temp);
			(*src)->time -= 1;
		}
		else if ((*dst) != NULL && (*dst)->first != NULL)
			arc_push_helper(&(*dst)->first, &(*src)->first,
				&(*dst)->time, &(*src)->time);
	}
}

// time : O(1)
// space: O(1)
void	arc_rotate(t_list_h **list)
{
	t_list	*temp;

	(*list)->last->next = (*list)->first;
	temp = (*list)->first;
	(*list)->first = (*list)->first->next;
	(*list)->last = temp;
	(*list)->last->next = NULL;
}
