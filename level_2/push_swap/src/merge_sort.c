/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:06:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/03/31 18:14:01 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
// slower
// time : O(n)
// space: O(1)
void		first_partial_sort(t_list_2h *list, char secret)
{
	while (list->a->time > 1)
	{
		if ((list->a->first->value > list->a->first->next->value
				&& i % 2 == 0)
			|| (list->a->first->value < list->a->first->next->value
				&& i % 2 == 1))
			say_swap(list, 'a', secret);
		say_push(list, 'b', secret, 1);
		say_push(list, 'b', secret, 1);
		i += 1;
	}
	if (list->a->first != NULL)
		say_push(list, 'b', secret, 1);
	list->tree_of_life = 4;
}
	// 34
*/

// time : O(n)
// space: O(1)
void		first_partial_sort(t_list_2h *list, char secret, size_t i)
{
	char	arc_a;
	char	arc_b;

	while (list->a->time > 1)
	{
		arc_a = i % 2;
		arc_b = i % 2;
		say_push(list, 'b', secret, 2);
		if (list->a->first->next != NULL
			&& list->a->first->value < list->a->first->next->value)
			arc_a = (i + 1) % 2;
		if (list->b->first->value < list->b->first->next->value)
			arc_b = (i + 1) % 2;
		if (arc_a != i % 2 && arc_b != i % 2)
			say_swap(list, 'c', secret);
		if (arc_a != i % 2 && arc_b == i % 2)
			say_swap(list, 'a', secret);
		if (arc_a == i % 2 && arc_b != i % 2)
			say_swap(list, 'b', secret);
		say_push(list, 'b', secret, 2);
		i += 1;
	}
	if (list->a->first != NULL)
		say_push(list, 'b', secret, 1);
	list->tree = 4;
}
