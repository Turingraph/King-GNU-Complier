<!--
To Do List
1.	write milacle_acane file about the 7 cards spread.
2.	Fix the testing code in the `### Test `the_chariot()` function.` section
3.	Check norm
4.	Check everything. 
5.	Run `make fclean`, Delete `gnlTester/`, `gnl-station-tester/`, `test.c`, `milabo_acane` (if exists), and `a.out`.
6.	Submit.
-->

This project has been created as part of the 42 curriculum by Phuri Sottatipreedawong.

# Description

Implement the function `get_next_line(int fd)` in C, such that
1.	It return the text file pointed to by the file descriptor `fd`, one line at a time using `read()` function.
2.	If there us nothing left to read or if an error occurs, it should return `NULL`.
3.	Each return line should include `\n` except when read the last line of the file and the file does not end with a `\n`.
4.	It should read `BUFFER_SIZE` size everytime when use `read()` function.

# Test

In order to test if my code works as expected
1.	you can create `test.c` file and copy my test case in this section.
2.	run `make` in this directory.
3.	run `cc -Wall -Wextra -Werror -BUFFER_SIZE=21 test.c get_next_line.a`
4.	run `./a.out ...`
5.	run `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out` to check memory leak.

## Test `three_of_cups` function.

```
#include "get_next_line.h"

void	print_int(int long num)
{
	long long int	d;
	char			coef;

	if (num == 0)
		write(1, "0", 1);
	d = 1;
	while (d < num)
	{
		d *= 10;
	}
	if (d > num)
		d /= 10;
	while (d > 0)
	{
		coef = '0' + (num / d);
		write(1, &coef, 1);
		num %= d;
		d /= 10;
	}
}

int	main(int ac, char **ar)
{
	t_temperance	*line;

	line = ace_of_cup(1, 1);
	if (line == NULL)
		return (0);
	if (ac < 2)
		return (0);
	if (three_of_cups(&line, *(ar + 1)) == NULL)
		return (0);
	write(1, line->arr, line->length);
	write(1, "\n", 1);
	print_int(line->length);
	write(1, " <= ", 4);
	print_int(line->capacity);
	write(1, "\n", 1);
	free(line->arr);
	free(line);
	return (0);
}
```

### Test `the_chariot()` function.

```
#include "get_next_line.h"

int	main(void)
{
	size_t			i;
	int				fd;
	t_temperance	*line;

	line = ace_of_cup(1, 1);
	if (line == NULL)
		return (0);
	fd = open("milabo_acane", 'r');
	if (fd < 0)
		return (0);
	i = 0;
	while (i < 1)
	{
		if (the_chariot(fd, &line, "1") == 1)
			return (0);
		write(1, line->arr, line->length);
		write(1, "\n", 1);
		print_int(line->length);
		write(1, " <= ", 4);
		print_int(line->capacity);
		write(1, "\n", 1);
		free(line->arr);
		free(line);
		i += 1;
	}
	return (0);
}
```

## Test `get_next_line()` function.

Note that you can name file in `open()` function however you want.

```
#include "get_next_line.h"

int	main(void)
{
	size_t			i;
	int				fd;
	char			*line;
	char			ii;

	fd = open("milabo_acane", 'r');
	if (fd < 0)
		return (0);
	i = 0;
	while (i < 5)
	{
		ii = i + '0';
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		write(1, ">>> ", 4);
		write(1, &ii, 1);
		write(1, "\t:", 2);
		write(1, line, knight_of_coin(line, '\0'));
		write(1, "\n", 1);
		free(line);
		i += 1;
	}
	return (0);
}
```

## Target file. `milabo_acane`

You can use this target file `milabo_acane` to test my code.

```
Beautiful is better than ugly.
Explicit is better than implicit.
Simple is better than complex.
Complex is better than complicated.
Flat is better than nested.
Sparse is better than dense.
Readability counts.
SPECIALZ cases aren't special enough to break the rules.
Although practicality beats purity.
Errors should never pass silently.
Unless explicitly silenced.
In the face of ambiguity, refuse the temptation to guess.
There should be one-- and preferably only one --obvious way to do it.
Although that way may not be obvious at first unless you're Dutch.
Now is better than never.
Although never is often better than *right* now.
If the implementation is hard to explain, it's a bad idea.
If the implementation is easy to explain, it may be a good idea.
Namespaces are one honking great idea -- let's do more of those!

This poem is written by Tim Peters (https://peps.python.org/pep-0020/).
The title of this file is "miracle_arcana" .
```

# How my code works ?

## Purpose of each function

### `get_next_line_utils.c`

1.	`char *ace_of_coin(char *src, size_t length, size_t capacity)`
*	Purpose: Initializing or copy string as `char` type array.
*	time:	`O(n)`
*	space:	`O(n)`
2.	`t_temperance *ace_of_cup(size_t capacity, char create_arr);`
*	Purpose: Initializing `char` type dynamic array (a.k.a. `t_temperence`)
*	time: 	`O(n)`
*	space:	`O(n)`
3.	`static inline t_temperance *two_of_cups(t_temperance **left_cup, char c);`
*	Purpose: Append `c` in dynamic array `left_cup`.
*	time: 	`O(1)`
*	space:	`O(1)`
*	worse time : `O(n)`
*	worse space: `O(n)`
4.	`t_temperance **three_of_cups(t_temperance **group, char *friends);`
*	Purpose: Concat `friends` string in dynamic array `group`.
*	time: 	`O(n)`
*	space:	`O(n)`

### `get_next_line.c`

1.	`size_t knight_of_coin(char *str, char stop)`
*	Purpose: Count how many `char` in string that comes before `'\0'` and `'\n'`.
*	time: 	`O(n)`
*	space:	`O(1)`
2.	`char the_chariot(int fd, t_temperance **angel, char *ambition)`
*	Purpose: Read as many data from the target file as possible before facing `'\n'` or `'\0'`
*	time:	`O(n)`
*	space:	`O(n)`
3.	`char *get_next_line(int fd)`
*	Purpose: Return the text file pointed to by the file descriptor `fd`, one line at a time using `read()` function.
*	time:	`O(n)`
*	space:	`O(n)`

## Purpose of each variable in `get_next_line()`

1.	`t_temperance	*angel;` : This variable is `char` type dynamic array.
2.	`char			*knight;` : This variable is output string.
3.	`size_t			length;` : is used for counting how many `char` of `angel` that come before `'\n'`
4.	`static char		*coin = NULL;` : is used for storing the `char` of `angel` that comes after `'\n'`
5.	`static char		ambition = '1';` : is used to check if `read()` already read last line. If `read()` already read last line, then we stop using function `read()`.

## How `get_next_line()` is executed ?

### How `get_next_line()` works when this function read the first line ?

1.	Initializing dynamic array using `angel = ace_of_cup(1, 1);`
2.	`char the_chariot(int fd, t_temperance **angel, char *ambition);` use `read` to read as many data before facing `'\n'` or `'\0'`. If `the_chariot()` return `1`, then it stop to prevent `NULL` pointer related issue. If `BUFFER_SIZE` is large enough, such that `get_next_line()` read the last `char` of the target file, then `ambition` is edited as `'0'` as the indication that it is not worth time to read data anymore, and `the_chariot()` won't be activated again in future call.
3.	Create the slice of `angel` that is the first line of the target text as `knight`.
4.	Create the slice of `angel` that comes after the first `'\n'` as `coin`.
5.	free dynamic array `angel`.
6.	Return `knight`.

### How `get_next_line()` works when this function read the i-th line ?

1.	Initializing dynamic array `angel`.
2.	Concat `coin` in empty dynamic array `angel` if it is valid to do so, using `three_of_cups()`, Then free `coin`.
3.	activate `the_chariot()`
4.	Create the slice of `angel` that is the first line of the target text as `knight`.
5.	Create the slice of `angel` that comes after the first `'\n'` as `coin`.
6.	free dynamic array `angel`.
7.	Return `knight`.

### How `get_next_line()` works when this function read the last time ?

1.	Initializing dynamic array `angel`.
2.	Activate `three_of_cups()`.
3.	activate `the_chariot()`
4.	Create the slice of `angel` that is the last line of the target text as `knight`.
5.	Given that `angel->length - length == 0`, implies that `coin = NULL`.
6.	free dynamic array `angel`.
7.	Return `knight`.

### How `get_next_line()` works when this function is called after it read last line ?

1.	Initializing dynamic array `angel`.
2.	`three_of_cups()` is not active because `coin == NULL`.
3.	`the_chariot()` is not active because `ambition == '0'`.
4.	`length = 0`
5.	`knight == NULL` because `length == 0`.
6.	Given that `angel->length - length == 0`, implies that `coin = NULL`.
7.	free dynamic array `angel`.
8.	Return `NULL`.

# Resources

1.  Static Variable
	1.	https://www.geeksforgeeks.org/c/static-variables-in-c/
	2.	https://stackoverflow.com/questions/572547/what-does-static-mean-in-c
2.	Read function
	1.	https://www.w3schools.com/c/c_files_read.php
	2.	https://stackoverflow.com/questions/68144753/using-read-for-reading-a-file-in-c
3.	Macro
	1.	https://www.geeksforgeeks.org/c/macros-and-its-types-in-c-cpp/
4.	Optimization
	1.	https://stackoverflow.com/questions/110684/what-coding-techniques-do-you-use-for-optimising-c-programs
	2.	https://www.geeksforgeeks.org/c/inline-function-in-c/
5.	Dynamic Array
	1.	https://youtu.be/jzJlq35dQII?si=3XmgIwp8fBMDTPTE
6.	42 Coding School Get Next Line Assignment Tester.
	1.	https://github.com/Tripouille/gnlTester
	2.	https://github.com/kodpe/gnl-station-tester
