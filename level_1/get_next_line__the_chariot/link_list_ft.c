/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:20:19 by phsottat          #+#    #+#             */
/*   Updated: 2025/10/18 16:11:43 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

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

char	*f_data(int fd, size_t qp)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (qp));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < qp - 1)
	{
		*(str + i) = '\0';
		i += 1;
	}
	*(str + i) = '\0';
	read(fd, str, qp);
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

struct s_ll_char	*f_ll_char(int fd, size_t qp)
{
	struct s_ll_char	*y;
	struct s_ll_char	*first;
	char				*data;
	size_t				i;

	data = f_data(fd, qp);
	if (data == NULL)
		return (NULL);
	if (f_init_ll(&y, data) == NULL)
	{
		free(data);
		return (NULL);
	}
	first = y;
	i = 0;
	while (f_strlen(data, '\0', &i) == qp && data != NULL)
	{
		data = f_data(fd, qp);
		if (data != NULL)
			f_insert_ll_end(&y, data);
		i = 0;
	}
	data = f_data(fd, qp);
	f_insert_ll_end(&y, data);
	return (first);
}

void	*f_free_ll(struct s_ll_char **head)
{
	struct s_ll_char	*temp;

	if (*head == NULL)
		return (NULL);
	temp = *head;
	*head = temp->next;
	free(temp);
	return (NULL);
}

size_t	f_len_line(struct s_ll_char *ll_char, size_t qp, size_t y)
{
	static size_t	current_i = 0;
	char			stop;
	size_t			init_i;

	init_i = current_i;
	stop = 1;
	while (stop != 0)
	{
		y += f_strlen(ll_char->str, '\n', &current_i) - init_i;
		if (*(ll_char->str + current_i - 1) == '\n'
			|| ft_strlen(ll_char->str) < qp)
			stop = 0;
		if (current_i == qp)
		{
			init_i = 0;
			current_i = 0;
		}
		ll_char = ll_char->next;
	}
	current_i = current_i % qp;
	return (y);
}

/*
// *** DEBUGGING MODE ***
// https://stackoverflow.com/questions/17774821
// /how-do-i-print-the-percent-sign-in-c
// size_t	y = 0;
size_t	f_len_line(struct s_ll_char *ll_char, size_t qp, size_t y)
{
	static size_t	current_i = 0;
	char			stop;
	size_t			init_i;

	init_i = current_i;
	stop = 1;
	// write(1, "f_len_line: ", 12);
	while (stop != 0)
	{
		y += f_strlen(ll_char->str, '\n', &current_i) - init_i;
		// write(1, "\nKing GNU Complier: ", 20);
		// ft_putnbr_fd(y, 1);
		// write(1, "\t = ", 4);
		// ft_putnbr_fd(current_i, 1);
		// write(1, "\t- ", 3);
		// ft_putnbr_fd(init_i, 1);
		// write(1, "\t|", 2);
		// ft_putnbr_fd(ft_strlen(ll_char->str), 1);
		// write(1, "\t*** ", 5);
		// write(1, ll_char->str, ft_strlen(ll_char->str));
		// write(1, " ***\t", 5);
		// if (*(ll_char->str + current_i - 1) != '\0')
		// 	write(1, (ll_char->str + current_i - 1), 1);
		// else
		// 	write(1, "\\0", 2);
		// write(1, "\n", 1);
		if (*(ll_char->str + current_i - 1) == '\n'
			// || *(ll_char->str + current_i - 1) == '\0')
			|| ft_strlen(ll_char->str) < qp)
		{
			// write(1, "HALT!!!\n", 8);
			stop = 0;
		}
		// else if (*(ll_char->str + current_i - 1) == '\0' && 1 <= current_i < qp)
			// stop = 0;
		if (current_i == qp)
		{
			init_i = 0;
			current_i = 0;
		}
		ll_char = ll_char->next;
	}
	// write(1, "\ny = ", 5);
	// ft_putnbr_fd(y, 1);
	// write(1, "\n", 1);
	// write(1, "current_i = ", 12);
	// ft_putnbr_fd(current_i, 1);
	// write(1, " % ", 3);
	// ft_putnbr_fd(qp, 1);
	// write(1, " = ", 3);
	// ft_putnbr_fd(current_i % qp, 1);
	// write(1, "\n", 1);
	current_i = current_i % qp;
	return (y);
}
*/

/*
// *** ORIGINAL VERSION ***
char	*f_get_line(struct s_ll_char **ll_char, size_t qp)
{
	char			*y;
	size_t			len_line;
	static size_t	init_i = 0;
	size_t			i;

	if (*ll_char == NULL)
		return (NULL);
	len_line = f_len_line(*ll_char, qp, 0);
	if (len_line == 0)
		return (NULL);
	y = (char *)malloc(sizeof(char) * (len_line + 1));
	if (y == NULL)
		return (y);
	i = 0;
	while (i < len_line)
	{
		*(y + i) = *((*ll_char)->str + (init_i + i) % qp);
		i += 1;
		while (*((*ll_char)->str + (init_i + i) % qp) != '\0'
			&& i < len_line
			&& (init_i + i) % qp != 0)
		{
			*(y + i) = *((*ll_char)->str + (init_i + i) % qp);
			i += 1;
		}
		if ((init_i + i) % qp == 0
			|| (*((*ll_char)->str + (init_i + i) % qp) == '\0'))
			f_free_ll(ll_char);
	}
	*(y + len_line) = '\0';
	init_i = (init_i + i) % qp;
	return (y);
}
*/

char	*f_get_line(struct s_ll_char **ll_char, size_t qp, char *y, size_t len_line)
{
	static size_t	init_i = 0;
	size_t			i;

	i = 0;
	while (i < len_line)
	{
		*(y + i) = *((*ll_char)->str + (init_i + i) % qp);
		i += 1;
		while (*((*ll_char)->str + (init_i + i) % qp) != '\0'
			&& i < len_line
			&& (init_i + i) % qp != 0)
		{
			*(y + i) = *((*ll_char)->str + (init_i + i) % qp);
			i += 1;
		}
		if ((init_i + i) % qp == 0
			|| (*((*ll_char)->str + (init_i + i) % qp) == '\0'))
			f_free_ll(ll_char);
	}
	*(y + len_line) = '\0';
	init_i = (init_i + i) % qp;
	return (y);
}

char	*get_next_line(int fd, size_t qp)
{
	static char				first = 0;
	static struct s_ll_char	*ll_char = NULL;
	char					*y;
	size_t					len_line;

	if (first == 0)
	{
		ll_char = f_ll_char(fd, qp);
		first = 1;
	}
	if (ll_char == NULL)
		return (NULL);
	len_line = f_len_line(ll_char, qp, 0);
	if (len_line == 0)
		return (NULL);
	y = (char *)malloc(sizeof(char) * (len_line + 1));
	if (y == NULL)
		return (y);
	f_get_line(&ll_char, qp, y, len_line);
	return (y);
}

/*
// *** DEBUGGING MODE ***
char	*f_get_line(struct s_ll_char **ll_char, size_t qp)
{
	char			*y;
	size_t			len_line;
	static size_t	init_i = 0;
	size_t			i;

	if (*ll_char == NULL)
		return (NULL);
	len_line = f_len_line(*ll_char, qp, 0);
	if (len_line == 0)
		return (NULL);
	// write(1, "\n?!?! Time Left ?!?!\n", 21);
	// write(1, "len_line = ", 11);
	// ft_putnbr_fd(len_line, 1);
	// write(1, "\n", 1);
	y = (char *)malloc(sizeof(char) * (len_line + 1));
	if (y == NULL)
		return (y);
	i = 0;
	while (i < len_line)
	{
		// write(1, ">>> ", 4);
		// ft_putnbr_fd((init_i + i) % qp, 1);
		// write(1, "\t", 1);
		// ft_putnbr_fd(i, 1);
		// write(1, "\t", 1);
		// write(1, ((*ll_char)->str + (init_i + i) % qp), 1);
		// write(1, "\n", 1);
		*(y + i) = *((*ll_char)->str + (init_i + i) % qp);
		i += 1;
		while (*((*ll_char)->str + (init_i + i) % qp) != '\0'
			&& i < len_line
			&& (init_i + i) % qp != 0)
		{
			// write(1, ">>> ", 4);
			// ft_putnbr_fd((init_i + i) % qp, 1);
			// write(1, "\t", 1);
			// ft_putnbr_fd(i, 1);
			// write(1, "\t", 1);
			// write(1, ((*ll_char)->str + (init_i + i) % qp), 1);
			// write(1, "\n", 1);
			*(y + i) = *((*ll_char)->str + (init_i + i) % qp);
			i += 1;
		}
		if ((init_i + i) % qp == 0
			|| (*((*ll_char)->str + (init_i + i) % qp) == '\0'))
		{
			// write(1, "*** ", 4);
			// ft_putnbr_fd(i, 1);
			// write(1, "\t", 1);
			// write(1, (*ll_char)->str, ft_strlen((*ll_char)->str));
			// write(1, " ***\n", 5);
			f_free_ll(ll_char);
		}
	}
	*(y + len_line) = '\0';
	// write(1, "\n*** ", 5);
	// ft_putnbr_fd(i, 1);
	// write(1, "\t", 1);
	// write(1, (*ll_char)->str, ft_strlen((*ll_char)->str));
	// write(1, " ***\n", 5);
	init_i = (init_i + i) % qp;
	// write(1, "init_i = ", 9);
	// ft_putnbr_fd(init_i, 1);
	// write(1, "\n", 1);
	return (y);
}
*/

// -------------------------------------------------------------------------
// *** TESTING FILES ***

// milabo_acane.txt

/*
One interesting artistic project that I have is
inspired by Linear Algebra Done Right and Tarot card,
by using numbers between 0-1 to assign the
"subjective interpretation" based score on how much percent
the given n numbers of characters’s motivation similar to the
given Major Acarna cards in 22 dimensional vector space over
real number, before and after some particular arc.
Then apply various matrix related algorithms e.g. SVD, PCA etc. to analyze
fictional stories e.g. Frieren, Dandadan, Studio Ghibli, Bojack Horseman,
Everything everywhere all at once etc.

I can also replace R^22 with F_2^22 for {inactive, active} states instead.
*/

// minor_arcana.txt

/*
I'm interested in Tarot.
I selected a Tarot card randomly before doing this project.
I got "Queen of Pentacles" which is 13-th Pentacle Tarot cards.
means I put some effort and joy on this project.
*/

// major_arcana.txt

/*
*   Shing02 -> 02Shing -> II Shing -> I Shing -> I Ching
*   Zutomayo's Milabo -> Acane's Milabo -> Milabo Acane -> Miracle Arcana
*/

// null_space.txt

/*


*/

// -------------------------------------------------------------------------
// *** TESTING FUNCTION ***

/*
char	*file = "major_arcana.txt";
char	*file = "milabo_acane.txt";
char	*file = "minor_arcana.txt";
char	*file = "null_space.txt";
*/

int	main(void)
{
	size_t				qp;
	int				    fd;
	char				*file = "milabo_acane.txt";
	char				*nujabes;

	qp = 13;
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		write(1, "(fd == -1)\n", 11);
		return (0);
	}
	nujabes = get_next_line(fd, qp);
	if (nujabes != NULL)
		write(1, nujabes, ft_strlen(nujabes));
	while (nujabes != NULL)
	{
		if (nujabes != NULL)
			free(nujabes);
		nujabes = get_next_line(fd, qp);
		if (nujabes != NULL)
			write(1, nujabes, ft_strlen(nujabes));
	}
	write(1, "~ End\n", 6);
	return (0);
}

/*
int	main(void)
{
	struct s_ll_char	*ll_char;
	size_t				qp;
	// size_t				i;
	int				    fd;
	char				*file = "milabo_acane.txt";
	char				*nujabes;

	qp = 13;
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		write(1, "(fd == -1)\n", 11);
		return (0);
	}
	ll_char = f_ll_char(fd, qp);

	// i = 0;
	while (ll_char != NULL)
	// while (i < 12)
	{
		nujabes = f_get_line(&ll_char, qp);
		if (nujabes == NULL)
		{
			write(1, "\n\nnujabes == NULL\n", 18);
			return (0);
		}
		// write(1, ":::::::: ", 9);
		write(1, nujabes, ft_strlen(nujabes));
		// write(1, "\n", 1);
		free(nujabes);
		// i += 1;
	}
	// write(1, "\n*** ", 5);
	// write(1, ll_char->str, ft_strlen(ll_char->str));
	// write(1, " ***\n", 5);

	// len = f_len_line(ll_char, qp, 0);
	// ft_putnbr_fd((int) len, 1);
	// write(1, "\n", 1);

	// nujabes = f_get_line(ll_char, qp);
	// if (nujabes == NULL)
	// {
	// 	write(1, "nujabes == NULL\n", 16);
	// 	return (0);
	// }
	// write(1, nujabes, ft_strlen(nujabes));
	// free(nujabes);

	// while (ll_char != NULL)
	// {
	// 	write(1, ">>> ", 4);
	// 	write(1, ll_char->str, ft_strlen(ll_char->str));
	// 	write(1, "\n", 1);
	// 	f_free_ll(&ll_char);
	// }

	write(1, "~ End\n", 6);
	return (0);
}
*/

/*
int	main(void)
{
	struct s_ll_char	*y;
	struct s_ll_char	*ll_char;
	char				*data;
	size_t				qp;
	int				    fd;
	char			    *file = "ii_shing.txt";

	qp = 13;
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		write(1, "(fd == -1)\n", 11);
		return (0);
	}
	ll_char = NULL;
	data = f_data(fd, qp);
	if (data == NULL)
	{
		write(1, "(data == NULL)\n", 15);
		return (0);
	}
	if (f_init_ll(&y, data) == NULL)
	{
		write(1, "(f_init_ll(&y, data) == NULL)\n", 30);
		return (0);
	}
	ll_char = y;
	while (ft_strlen(data) == qp)
	{
		data = f_data(fd, qp);
		f_insert_ll_end(&y, data);
	}
	data = f_data(fd, qp);
	f_insert_ll_end(&y, data);
	while (ll_char != NULL)
	{
		write(1, ">>> ", 4);
		write(1, ll_char->str, ft_strlen(ll_char->str));
		write(1, "\n", 1);
		f_free_ll(&ll_char);
	}
	write(1, "~ End\n", 6);
	return (0);
}
*/

// DYNAMIC LIBRARY VERSION

/*
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 link_list_ft.c -o prog libft.so

LD_LIBRARY_PATH="./" ./prog
Mumu CheChe Tata 42Code
*/

// STATIC LIBRARY VERSION

/*
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 link_list_ft.c -o prog

./prog
Mumu CheChe Tata 42Code
*/