/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:02 by phsottat          #+#    #+#             */
/*   Updated: 2026/04/03 13:54:37 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct t_list
{
	int				value;
	struct t_list	*next;
}	t_list;

typedef struct t_list_h
{
	t_list	*first;
	t_list	*last;
	size_t	time;
}	t_list_h;

typedef struct t_list_2h
{
	t_list_h	*a;
	t_list_h	*b;
	size_t		tree_height;
}	t_list_2h;

// mode = a -> me
// mode = b -> b
// mode = c -> us

// arc.c
void		arc_swap(t_list *a, t_list *b, char whoami);
void		arc_push(t_list_h **dst, t_list_h **src, char whoami);
void		arc_rotate(t_list_h **list, char whoami);

// get_input.c a.k.a. backstory.c
t_list_h	*init_list_h(size_t time, int *src);
t_list_2h	*init_list_2h(size_t time, int *src);
size_t		swap_list_2h(t_list_h **a, t_list_h **b,
				t_list_2h *list, char *whoami);

// atoi.c a.k.a. biography.c
int			atoi(char *src, char *err);
int			*init_int_arr(size_t time, char **src, char *err);
void		free_list(t_list *src);
t_list		*init_list(int value);

// duplication.c a.k.a. dejavu.c
void		free_hash_table(t_list **hash_table, size_t prime);
t_list		**init_hash_table(size_t prime);
char		insert_hash_table(t_list **hash_table, int item, size_t prime);
char		is_in_hash_table(t_list **hash_table,
				int item, size_t prime);
char		duplication_check(int *src, size_t time);

// prime.c a.k.a. eclipse.c
size_t		get_next_prime(size_t time);
size_t		hash_function(int item, size_t prime);

// merge_sort.c a.k.a. the_illusion_of_separation.c
void		first_partial_sort(t_list_2h *list, char secret);
void		push_sub_list(t_list_h *a, t_list_h *b, char whoami, size_t time);
void		merge_list(t_list_h *a, t_list_h *b, char whoami, size_t time);
size_t		sub_merge_sort(t_list_h *a, t_list_h *b,
				size_t tree_height, char whoami);
void		merge_sort(t_list_2h *list, char secret);

#endif
