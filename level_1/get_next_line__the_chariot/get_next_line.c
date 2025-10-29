/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:51:01 by phsottat          #+#    #+#             */
/*   Updated: 2025/10/19 15:27:42 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

/*
TO DO NOW

```
phsottat@z2t7c2 ~/Desktop/25_09/get_next_line__the_chariot
 % cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o prog libft.so
phsottat@z2t7c2 ~/Desktop/25_09/get_next_line__the_chariot
 % LD_LIBRARY_PATH="./" ./prog

y = 48
current_i = 6 % 42 = 6
https://www.reddit.com/r/tarot/comments/1o6tlud
zsh: segmentation fault (core dumped)  LD_LIBRARY_PATH="./" ./prog
phsottat@z1t3c1 ~/Desktop/25_09/get_next_line__the_chariot
```

*/

/*
Address 0x4aa70ff is 1 bytes before a block of size 43 alloc'd

It means Valgrind detected one block of memory you alloc'd 
(through malloc() or similar) for your program, and that you 
try to access the address which is 8 bytes before that.

https://stackoverflow.com/questions/29776831/
valgrind-address-is-8-bytes-before-a-block-of-size-16-allocd

However, I do not sure where is this error yet ?
*/

// -------------------------------------------------------------------------
// *** TEST FUNCTION ***
// -------------------------------------------------------------------------

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

void	display_int(int fd, int x)
{
	long	d;
	char	coef;

	d = 1;
	while (d < x)
		d *= 10;
	if (d > x)
		d /= 10;
	while (d > 0)
	{
		coef = x / d + '0';
		write(fd, &coef, 1);
		x = x % d;
		d /= 10;
	}
}

void	display_int_sign(int fd, int x)
{
	if (x == 0)
	{
		write(fd, "0", 1);
	}
	else if (x > 0)
	{
		display_int(fd, x);
	}
	else if (x == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		write(fd, "-", 1);
		display_int(fd, (-1) * x);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	display_int_sign(fd, n);
}

void	f_moon(char str, size_t i)
{
	write(1, "The_Moon: ", 10);
	ft_putnbr_fd(i, 1);
	write(1, "\t", 1);
	if (str == '\n')
		write(1, "\\n", 2);
	else if (str == '\0')
		write(1, "\\0", 2);
	else
		write(1, &str, 1);
	write(1, "\n", 1);
}

// -------------------------------------------------------------------------
// *** WRONG SOLUTION ***
// -------------------------------------------------------------------------

/*
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

size_t	f_len_line(struct s_ll_char *ll_char, size_t mod, size_t y)
{
	static size_t	current_i = 0;
	char			stop;
	size_t			i1;
	size_t			nine_cup;

	nine_cup = 0;
	i1 = current_i;
	stop = 1;
	while (stop != 0)
	{
		y += f_strlen(ll_char->str, '\n', &current_i) - i1;
		if (*(ll_char->str + current_i - 1) == '\n'
			|| f_strlen(ll_char->str, &nine_cup) < mod)
			stop = 0;
		if (current_i == mod)
		{
			i1 = 0;
			current_i = 0;
		}
		ll_char = ll_char->next;
		nine_cup = 0;
	}
	current_i = current_i % mod;
	return (y);
}

	// write(1, "::: ", 4);
	// ft_putnbr_fd(y, 1);
	// write(1, "\n", 1);

char	*f_get_line(struct s_ll_char **ll_char, size_t mod, char *y, size_t len_line)
{
	static size_t	i1 = 0;
	size_t			i;

	i = 0;
	while (i < len_line)
	{
		*(y + i) = *((*ll_char)->str + (i1 + i) % mod);
		i += 1;
		while (*((*ll_char)->str + (i1 + i) % mod) != '\0'
			&& i < len_line
			&& (i1 + i) % mod != 0)
		{
			*(y + i) = *((*ll_char)->str + (i1 + i) % mod);
			i += 1;
		}
		if ((i1 + i) % mod == 0
			|| (*((*ll_char)->str + (i1 + i) % mod) == '\0'))
			f_free_ll(ll_char);
	}
	*(y + len_line) = '\0';
	i1 = (i1 + i) % mod;
	return (y);
}

char	*get_next_line(int fd)
{
	static char				first = 0;
	static struct s_ll_char	*ll_char = NULL;
	char					*y;
	size_t					len_line;

	if (first == 0)
	{
		ll_char = f_ll_char(fd, (size_t) BUFFER_SIZE);
		first = 1;
	}
	if (ll_char == NULL)
		return (NULL);
	len_line = f_len_line(ll_char, (size_t) BUFFER_SIZE, 0);
	if (len_line == 0)
		return (NULL);
	y = (char *)malloc(sizeof(char) * (len_line + 1));
	if (y == NULL)
		return (y);
	f_get_line(&ll_char, (size_t) BUFFER_SIZE, y, len_line);
	return (y);
}
*/

/*
// *** DEBUGGING MODE ***
// https://stackoverflow.com/questions/17774821
// /how-do-i-print-the-percent-sign-in-c
// size_t	y = 0;
size_t	f_len_line(struct s_ll_char *ll_char, size_t mod, size_t y)
{
	static size_t	current_i = 0;
	char			stop;
	size_t			i1;

	i1 = current_i;
	stop = 1;
	// write(1, "f_len_line: ", 12);
	while (stop != 0)
	{
		y += f_strlen(ll_char->str, '\n', &current_i) - i1;
		// write(1, "\nKing GNU Complier: ", 20);
		// ft_putnbr_fd(y, 1);
		// write(1, "\t = ", 4);
		// ft_putnbr_fd(current_i, 1);
		// write(1, "\t- ", 3);
		// ft_putnbr_fd(i1, 1);
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
			|| ft_strlen(ll_char->str) < mod)
		{
			// write(1, "HALT!!!\n", 8);
			stop = 0;
		}
		// else if (*(ll_char->str + current_i - 1) == '\0' && 1 <= current_i < mod)
			// stop = 0;
		if (current_i == mod)
		{
			i1 = 0;
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
	// ft_putnbr_fd(mod, 1);
	// write(1, " = ", 3);
	// ft_putnbr_fd(current_i % mod, 1);
	// write(1, "\n", 1);
	current_i = current_i % mod;
	return (y);
}
*/

/*
// *** DEBUGGING MODE ***
char	*f_get_line(struct s_ll_char **ll_char, size_t mod)
{
	char			*y;
	size_t			len_line;
	static size_t	i1 = 0;
	size_t			i;

	if (*ll_char == NULL)
		return (NULL);
	len_line = f_len_line(*ll_char, mod, 0);
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
		// ft_putnbr_fd((i1 + i) % mod, 1);
		// write(1, "\t", 1);
		// ft_putnbr_fd(i, 1);
		// write(1, "\t", 1);
		// write(1, ((*ll_char)->str + (i1 + i) % mod), 1);
		// write(1, "\n", 1);
		*(y + i) = *((*ll_char)->str + (i1 + i) % mod);
		i += 1;
		while (*((*ll_char)->str + (i1 + i) % mod) != '\0'
			&& i < len_line
			&& (i1 + i) % mod != 0)
		{
			// write(1, ">>> ", 4);
			// ft_putnbr_fd((i1 + i) % mod, 1);
			// write(1, "\t", 1);
			// ft_putnbr_fd(i, 1);
			// write(1, "\t", 1);
			// write(1, ((*ll_char)->str + (i1 + i) % mod), 1);
			// write(1, "\n", 1);
			*(y + i) = *((*ll_char)->str + (i1 + i) % mod);
			i += 1;
		}
		if ((i1 + i) % mod == 0
			|| (*((*ll_char)->str + (i1 + i) % mod) == '\0'))
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
	i1 = (i1 + i) % mod;
	// write(1, "i1 = ", 9);
	// ft_putnbr_fd(i1, 1);
	// write(1, "\n", 1);
	return (y);
}
*/

// -------------------------------------------------------------------------
// *** CORRECT SOLUTION ***
// -------------------------------------------------------------------------

/*
I forgot `free(temp->str);`
*/

void	*f_free_ll(struct s_ll_char **head)
{
	struct s_ll_char	*five_cups;

	if (*head == NULL)
		return (NULL);
	five_cups = *head;
	*head = five_cups->next;
	// write(1, "5 Cups: ", 8);
	// write(1, five_cups->str, ft_strlen(five_cups->str));
	// write(1, "::\n", 3);
	free(five_cups->str);
	free(five_cups);
	return (NULL);
}

// 9 cups means "I already have everythings and I do not need
// and/or open to this new things now"
// nine_cup is just argument place holder, such that I do not need to 
// write more simplier function in this specialized context.
size_t	f_len_line(struct s_ll_char *ll_char, size_t y, size_t mod)
{
	static size_t	current_i = 0;
	char			stop;
	size_t			i1;
	size_t			nine_cup;

	nine_cup = 0;
	i1 = current_i;
	stop = 1;
	while (stop != 0)
	{
		y += f_strlen(ll_char->str, '\n', &current_i, 1) - i1;
		if (*(ll_char->str + current_i - 1) == '\n'
			|| f_strlen(ll_char->str, '\0', &nine_cup, 0) < mod)
			stop = 0;
		if (current_i == mod)
		{
			i1 = 0;
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
	// ft_putnbr_fd(mod, 1);
	// write(1, " = ", 3);
	// ft_putnbr_fd(current_i % mod, 1);
	// write(1, "\n", 1);
	current_i = current_i % mod;
	return (y);
}

	// write(1, "::: ", 4);
	// ft_putnbr_fd(y, 1);
	// write(1, "\n", 1);

/*
char	*f_get_line(struct s_ll_char *ll_char, char *y, size_t len_line, size_t mod)
{
	static size_t	i1 = 0;
	size_t			i;

	i = 0;
	// write(1, "*** I am become Death, the destroyer of worlds. ***\n", 52);
	while (i < len_line)
	{
		*(y + i) = *((ll_char)->str + (i1 + i) % mod);
		i += 1;
		while (*((ll_char)->str + (i1 + i) % mod) != '\0'
			&& i < len_line
			&& (i1 + i) % mod != 0)
		{
			*(y + i) = *((ll_char)->str + (i1 + i) % mod);
			i += 1;
		}
		if ((i1 + i) % mod == 0
			|| (*((ll_char)->str + (i1 + i) % mod) == '\0'))
			f_free_ll(&ll_char);
	}
	// write(1, "----------------~ The Death 13 ~--\n", 35);
	*(y + len_line) = '\0';
	i1 = (i1 + i) % mod;
	return (y);
}
*/

char	*f_get_line(struct s_ll_char **ll_char, char *y, size_t len_line, size_t mod)
{
	static size_t	i1 = 0;
	size_t			i;

	i = 0;
	// write(1, "*** I am become Death, the destroyer of worlds. ***\n", 52);
	while (i < len_line)
	{
		*(y + i) = *((*ll_char)->str + (i1 + i) % mod);
		i += 1;
		while (*((*ll_char)->str + (i1 + i) % mod) != '\0'
			&& i < len_line
			&& (i1 + i) % mod != 0)
		{
			*(y + i) = *((*ll_char)->str + (i1 + i) % mod);
			i += 1;
		}
		if ((i1 + i) % mod == 0
			|| (*((*ll_char)->str + (i1 + i) % mod) == '\0'))
			f_free_ll(ll_char);
	}
	// write(1, "----------------~ The Death 13 ~--\n", 35);
	*(y + len_line) = '\0';
	i1 = (i1 + i) % mod;
	return (y);
}

// char	*get_next_line(int fd)
// {
// 	static struct s_ll_char	*ll_char = NULL;
// 	char					*y;
// 	static size_t			len_line = 10;

// 	if ((size_t) BUFFER_SIZE == 0)
// 		return (NULL);
// 	if (ll_char == NULL)
// 		ll_char = f_ll_char(fd, (size_t) BUFFER_SIZE);
// 	if (ll_char == NULL)
// 		return (NULL);
// 	if (len_line == 0)
// 		return (NULL);
// 	y = (char *)malloc(sizeof(char) * (len_line + 1));
// 	if (y == NULL)
// 		return (y);
// 	f_get_line(&ll_char, y, len_line, (size_t) BUFFER_SIZE);
// 	return (y);
// }

char	*get_next_line(int fd)
{
	static struct s_ll_char	*ll_char = NULL;
	char					*y;
	size_t					len_line;

	if ((size_t) BUFFER_SIZE == 0)
		return (NULL);
	if (ll_char == NULL)
		ll_char = f_ll_char(fd, (size_t) BUFFER_SIZE);
	if (ll_char == NULL)
		return (NULL);
	len_line = f_len_line(ll_char, 0, (size_t) BUFFER_SIZE);
	if (len_line == 0)
		return (NULL);
	y = (char *)malloc(sizeof(char) * (len_line + 1));
	if (y == NULL)
		return (y);
	f_get_line(&ll_char, y, len_line, (size_t) BUFFER_SIZE);
	return (y);
}

/*
COMMENT BY CHATGPT:
1.	Read as little data as possible each time get_next_line() is called.
	If a newline character is encountered, return the current line
	immediately. Don’t read the whole file and then process each line.
	I just copied everythings at once, before realizing this.
	So I have to fix my code.
	My friend said that he also copy everything too, but he past
	the Get_Next_Line assignment.
	He said that my issue more likely to be related to `free`.
2.	My previous algorithm is similar to linked list version of Rope
	which only copy 1 time, and is used for 
	2.1	Loading large datasets into memory for fast access
	2.2	Small Script Files
	2.3	etc.

Note: I'm not check if ChatGPT said about Rope correctly or not.
*/

// -------------------------------------------------------------------------
// *** TESTING FILES ***
// -------------------------------------------------------------------------

// milabo_acane.txt

/*
*   Shing02 -> 02Shing -> II Shing -> I Shing -> I Ching
*   Zutomayo's Milabo -> Acane's Milabo -> Milabo Acane -> Miracle Arcana
*   GNU Compiler -> King GNU -> King Guardian Knight Upright -> King of Swords
*/

// the_fool.txt

/*


*/

// major_arcana.txt

/*
https://www.reddit.com/r/tarot/comments/1o6tlud
/alternate_uses_for_tarot_that_arent_divination/

There are so many creative things to do with Tarot beyond artistic drawing,
divination, self reflection, and art based therapy.

One interesting artistic project that I have is to make 1-2 minute songs with
lyrics for each Tarot card for both blind audience and song lover audience,
such that they "feel" tarot card via hearing.

The another interesting idea is to add Sign language
(to animated GIF Tarot cards),
natural written language that is similar to Chinese
(e.g. Chinese, Japanese, Korean etc. with “visual” kanji similar character)
and/or Kanji/Sign language inspired conlang to Tarot cards.
Place n number of GIF "written" Tarot card according to some translated lyric
of favorite/popular song writer artists's songs
(e.g. Weezer, Radiohead, Tally Hall, WillWood,
Zutomayo, Yorushika, Nujabes, Shing02 etc.)
and/or quotes/conversation from the fictional characters/real
famous individuals in history.

Also do you know any Tarot artists doing this on YouTube,
Spotify, GitHub, and/or other social media ? Thank you.
*/

// minor_arcana.txt

/*
I'm interested in Tarot.
I selected a Tarot card randomly before doing this project.
I got "Queen of Pentacles" which is 13-th Pentacle Tarot cards.
means I put some effort and joy on this project.
*/

// 2_wands.txt

/*
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis porta enim ut purus sodales dictum sit amet ut justo. Interdum et malesuada fames ac ante ipsum primis in faucibus. Quisque aliquet tortor elementum, congue ante sit amet, congue eros. Nullam aliquet magna sed ante facilisis, ut mattis urna condimentum. Ut semper at ipsum nec volutpat. Nam dignissim accumsan massa a facilisis. Praesent placerat aliquet laoreet. Praesent finibus enim nisi, rhoncus sagittis nunc luctus non.

----------------------------------------------------------------------

 ^^      ..                                       ..
             []                                       []
           .:[]:_          ^^                       ,:[]:.
         .: :[]: :-.                             ,-: :[]: :.
       .: : :[]: : :`._                       ,.': : :[]: : :.
     .: : : :[]: : : : :-._               _,-: : : : :[]: : : :.
 _..: : : : :[]: : : : : : :-._________.-: : : : : : :[]: : : : :-._
 _:_:_:_:_:_:[]:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:_:[]:_:_:_:_:_:_
 !!!!!!!!!!!![]!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!![]!!!!!!!!!!!!!
 ^^^^^^^^^^^^[]^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^[]^^^^^^^^^^^^^
             []                                       []
             []                                       []
             []                                       []
  ~~^-~^_~^~/  \~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/  \~^-~_~^-~~-
 ~ _~~- ~^-^~-^~~- ^~_^-^~~_ -~^_ -~_-~~^- _~~_~-^_ ~^-^~~-_^-~ ~^
    ~ ^- _~~_-  ~~ _ ~  ^~  - ~~^ _ -  ^~-  ~ _  ~~^  - ~_   - ~^_~
      ~-  ^_  ~^ -  ^~ _ - ~^~ _   _~^~-  _ ~~^ - _ ~ - _ ~~^ -
 jgs  .  ~^ -_ ~^^ -_ ~ _ - _ ~^~-  _~ -_   ~- _ ~^ _ -  ~ ^-
             ~^~ - _ ^ - ~~~ _ - _ ~-^ ~ __- ~_ - ~  ~^_-
                 ~ ~- ^~ -  ~^ -  ~ ^~ - ~~  ^~ - ~
----------------------------------------------------------------------
*/

// -------------------------------------------------------------------------
// *** TESTING FUNCTION ***
// -------------------------------------------------------------------------

/*
char	*file = "42_with_nl";
char	*file = "major_arcana.txt";
char	*file = "milabo_acane.txt";
char	*file = "minor_arcana.txt";
char	*file = "one_pentacle.txt";
char	*file = "the_fool.txt";
*/

// 10 wands = a lot of hard works and read a lot of line of data.

/*
int	main(void)
{
	int					fd;
	char				*file = "one_pentacle.txt";
	struct s_ll_char	*ll_char;
	size_t				len_line;
	char				*ten_wands;

	ten_wands = NULL;
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		write(1, "(fd == -1)\n", 11);
		return (0);
	}
	ll_char = f_ll_char(fd, (size_t) BUFFER_SIZE);
	len_line = f_len_line(ll_char, 0, (size_t) BUFFER_SIZE);
	write(1, "len_line: ", 10);
	ft_putnbr_fd(len_line, 1);
	write(1, "\n", 1);
	ten_wands = (char *)malloc(sizeof(char) * (len_line + 1));
	f_get_line(&ll_char, ten_wands, len_line, (size_t) BUFFER_SIZE);
	write(1, ten_wands, ft_strlen(ten_wands));
	write(1, "\n", 1);
	free(ten_wands);
	while (ll_char != NULL)
	{
		// write(1, ll_char->str, ft_strlen(ll_char->str));
		f_free_ll(&ll_char);
	}
	return (0);
}
*/

int	main(void)
{
	int					fd;
	char				*file = "milabo_acane.txt";
	char				*ten_wands;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "(fd == -1)\n", 11);
		return (0);
	}
	ten_wands = get_next_line(fd);
	if (ten_wands != NULL)
	{
		// write(1, "Ace of Pentacle: ", 17);
		write(1, ten_wands, ft_strlen(ten_wands));
		write(1, "\n", 1);
	}
	while (ten_wands != NULL)
	{
		if (ten_wands != NULL)
			free(ten_wands);
		ten_wands = get_next_line(fd);
		if (ten_wands != NULL)
		{
			// write(1, "Ace of Pentacle: ", 17);
			write(1, ten_wands, ft_strlen(ten_wands));
			write(1, "\n", 1);
		}
	}
	close(fd);
}

/*
int	main(void)
{
	int					fd;
	char				*file = "milabo_acane.txt";
	// char				*ten_wands;
	struct s_ll_char	*shing02;

	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		write(1, "(fd == -1)\n", 11);
		return (0);
	}
	write(1, "-----------------------------------------\n", 42);
	write(1, "I told you that story to tell you this one\n", 43);
	write(1, "55+Check this out, this goes out to my G\n\n", 42);
	shing02 = f_ll_char(fd, '\n');
	while (shing02 != NULL)
	{
		write(1, "*** ", 4);
		write(1, shing02->str, ft_strlen(shing02->str));
		write(1, " ***\n", 5);
		f_free_ll(&shing02);
	}

	write(1, "-----------------------------------------\n", 42);
	write(1, "Relax\n", 6);
	write(1, "~~~ Here we go, part two, check me out\n\n", 40);
	shing02 = f_ll_char(fd, '\n');
	while (shing02 != NULL)
	{
		write(1, "*** ", 4);
		write(1, shing02->str, ft_strlen(shing02->str));
		write(1, " ***\n", 5);
		f_free_ll(&shing02);
	}
	write(1, "~ End\n", 6);
	return (0);
}
*/

/*
int	main(void)
{
	struct s_ll_char	*ll_char;
	size_t				mod;
	// size_t				i;
	int				    fd;
	char				*file = "milabo_acane.txt";
	char				*ten_wands;

	mod = 13;
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		write(1, "(fd == -1)\n", 11);
		return (0);
	}
	ll_char = f_ll_char(fd, mod);

	// i = 0;
	while (ll_char != NULL)
	// while (i < 12)
	{
		ten_wands = f_get_line(&ll_char, mod);
		if (ten_wands == NULL)
		{
			write(1, "\n\nten_wands == NULL\n", 18);
			return (0);
		}
		// write(1, ":::::::: ", 9);
		write(1, ten_wands, ft_strlen(ten_wands));
		// write(1, "\n", 1);
		free(ten_wands);
		// i += 1;
	}
	// write(1, "\n*** ", 5);
	// write(1, ll_char->str, ft_strlen(ll_char->str));
	// write(1, " ***\n", 5);

	// len = f_len_line(ll_char, mod, 0);
	// ft_putnbr_fd((int) len, 1);
	// write(1, "\n", 1);

	// ten_wands = f_get_line(ll_char, mod);
	// if (ten_wands == NULL)
	// {
	// 	write(1, "ten_wands == NULL\n", 16);
	// 	return (0);
	// }
	// write(1, ten_wands, ft_strlen(ten_wands));
	// free(ten_wands);

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
	size_t				mod;
	int				    fd;
	char			    *file = "ii_shing.txt";

	mod = 13;
	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		write(1, "(fd == -1)\n", 11);
		return (0);
	}
	ll_char = NULL;
	data = f_data(fd, mod);
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
	while (ft_strlen(data) == mod)
	{
		data = f_data(fd, mod);
		f_insert_ll_end(&y, data);
	}
	data = f_data(fd, mod);
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

/*
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o prog libft.so

LD_LIBRARY_PATH="./" ./prog
Mumu CheChe Tata 42Code
*/

/*
TESTER
*	https://github.com/kodpe/gnl-station-tester
*	https://github.com/Tripouille/gnlTester
*/
