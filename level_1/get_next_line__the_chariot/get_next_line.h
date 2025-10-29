/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:02:48 by phsottat          #+#    #+#             */
/*   Updated: 2025/10/19 16:25:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// IMPLEMENTATION
# include <stdlib.h>

// TEST
# include <stdio.h>
# include <unistd.h>

// -------------------------------------------------------------------------
// *** IMPLEMENTATION ***

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

/*
I got "Ace of Cup", so I set BUFFER_SIZE as 1.
I used to hate debugging, but I grow to enjoy it when doing get_next_line.
It seem surprising that Tarot card align with my feeling.
*/

struct	s_ll_char
{
	char				*str;
	struct s_ll_char	*next;
};

// get_next_line_utils.c
struct s_ll_char	**f_init_ll(struct s_ll_char **head, char *data);
struct s_ll_char	**f_insert_ll_end(struct s_ll_char **head, char *data);
char				*f_data(int fd, char **dst, size_t mod);
size_t				f_strlen(char *str, char stop, size_t *init_y, char nine_cups);
struct s_ll_char	*f_ll_char(int fd, size_t mod);

// get_next_line.c
void				*f_free_ll(struct s_ll_char **head);
size_t				f_len_line(struct s_ll_char *ll_char, size_t y, size_t mod);
void	f_moon(char str, size_t i);
char				*f_get_line(
					struct s_ll_char **ll_char,
					char *y,
					size_t len_line,
					size_t mod);
char				*get_next_line(int fd);


// -------------------------------------------------------------------------
// *** MY TEST ***

/*
HOW TO USE DYNAMIC LIBRARY ?

# In normal case.
# % cc -Wall -Wextra -Werror get_next_line.c -o prog libft.so

# In case where you have to use `-D BUFFER_SIZE=42`.
cc -Wall -Wextra -Werror -D BUFFER_SIZE=13 get_next_line.c get_next_line_utils.c -o prog libft.so

# In case where there are inputs.
# % LD_LIBRARY_PATH="./" ./prog "input_01" "input_02" ...

# In case where there is no inputs.
LD_LIBRARY_PATH="./" ./prog

NOTE
*	You are not allowed to use your libft in this project.
*	Only use libft for testing.
*/

// #ifndef LIBFT_H
// # define LIBFT_H

void	display_int(int fd, int x);
void	display_int_sign(int fd, int x);
// int		ft_atoi(const char *nptr);
// void	ft_bzero(void *s, size_t n);
// void	*ft_calloc(size_t nmemb, size_t size);
// int		ft_isalnum(int c);
// int		ft_isalpha(int c);
// int		ft_isascii(int c);
// int		ft_isdigit(int c);
// int		ft_isprint(int c);
// char	*ft_itoa(int n);
// void	*ft_memchr(const void *s, int c, size_t n);
// int		ft_memcmp(const void *s1, const void *s2, size_t n);
// void	*ft_memcpy(void *dest, const void *src, size_t n);
// void	*ft_memmove(void *dest, const void *src, size_t n);
// void	*ft_memset(void *s, int c, size_t n);
// void	ft_putchar_fd(char c, int fd);
// void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
// void	ft_putstr_fd(char *s, int fd);
// char	**ft_split(char const *s, char c);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strdup(const char *s);
// void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_strlcat(char *dst, const char *src, size_t size);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// char	*ft_strnstr(const char *big, const char *little, size_t len);
// char	*ft_strrchr(const char *s, int c);
// char	*ft_strtrim(char const *s1, char const *set);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// int		ft_tolower(int c);
// int		ft_toupper(int c);

#endif

// -------------------------------------------------------------------------

// How I create dynamic library ?

/*
# Makedy.mk

# https://makefiletutorial.com/
# https://www.geeksforgeeks.org/c/how-do-i-create-a-library-in-c/
# file:///home/phsottat/Downloads/en.norm.pdf

NAME = libft.so

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

OBJO = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
	ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o \
	ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o \
	ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o \
	ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o \
	ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o \
	ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o \
	ft_strmapi.o ft_striteri.o ft_putchar_fd.o \
	ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o

OBJC = $(OBJO:.c=.o)

# Create the Dynamic Library.
all: $(NAME)

# Note: The -fPIC flag ensures that the code is position-independent. 
# This means it wouldn’t matter where the computer loads the code into memory.
# The -c options just ensure that each .o object file isn’t linked yet.
$(NAME): $(OBJO)
	$(CC) $(CFLAGS) -fPIC -shared $(OBJO) -o $(NAME)

# Compile the Object Files.
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -fPIC

# Delete Object file
clean:
	-rm -f $(OBJO)

# Delete all files that are created by Makefile
fclean: clean
	-rm -f $(NAME)

# Recompile makefile
re: fclean all

# Adding .PHONY to a target will prevent Make from confusing the phony target with a file name.
.PHONY : all clean fclean re

# Reference
# https://youtu.be/YtiPCPtmZrs?si=oXWlFxS0_bOEM7hS
# https://stackoverflow.com/questions/12057852/
#	multiple-makefiles-in-one-directory

#--------------------------------------------------------------------------

# How to create dynamic library ?
# % make -f Makedy.mk
# % cc -Wall -Wextra -Werror main.c -o prog libft.so
# % LD_LIBRARY_PATH="./" ./prog "input_01" "input_02" ...

#--------------------------------------------------------------------------

# % tree       
# .
# ├── ft_atoi.c
# ├── ft_bzero.c
# ├── ft_calloc.c
# ├── ft_isalnum.c
# ├── ft_isalpha.c
# ...
# ├── ft_toupper.c
# ├── libft.h
# ├── main.c
# ├── main.o
# ├── Makedy.mk
# ├── Makefile
# └── prog

#--------------------------------------------------------------------------

# main.c

#include "libft.h"
#include <stdio.h>

# int	main(int av, char **ac)
# {
# 	char	*y;
# 	int		len_y;
# 
# 	if (av < 3)
# 		return (0);
# 	y = ft_strtrim(*(ac + 1), *(ac + 2));
# 	if (y == NULL)
# 	{
# 		write(1, "NULL\n", 5);
# 		return (0);
# 	}
# 	write(1, "len(y) = ", 9);
# 	len_y = (int) ft_strlen(y);
# 	ft_putnbr_fd(len_y, 1);
# 	write(1, "\n", 1);
# 	write(1, y, ft_strlen(y));
# 	write(1, "\n", 1);
# 	free(y);
# 	return (0);
# }

#--------------------------------------------------------------------------

# When to use dynamic vs static library ?

# Static libraries increase the size of the code in your binary. 
# ...
# Dynamic libraries were considered to be the better approach most of the time, 
# but originally they had a major flaw (google DLL hell)

# https://stackoverflow.com/questions/140061/
# when-to-use-dynamic-vs-static-libraries

#--------------------------------------------------------------------------
*/

// -------------------------------------------------------------------------

// WHAT IS READ ?

/*
int read(int fileDescriptor, void *buffer, size_t bytesToRead)
1.	`fileDescriptor` = the open() function returns when opening a file.
2.	`buffer` = This pointer points to a buffer where data that is read will be 
	stored.
3.	`bytesToRead` = the maximum number of bytes we want to read from the file.

returns an integer value that refers to the number of bytes read.

```
include <unistd.h>

int	main(void)
{
	return (0);
}
```

Reference
* https://www.educative.io/answers/read-data-from-a-file-using-read-in-c
*/

// -------------------------------------------------------------------------

// WHAT ARE FILE DESCRIPTORS ?

/*
In simple words, when you open a file, the operating system creates an entry
to represent that file and store the information about that opened file. 
Each entries are represented as unique integer.

Reference
*	https://stackoverflow.com/questions/5256599/
	what-are-file-descriptors-explained-in-simple-terms
*/

// -------------------------------------------------------------------------
// *** HOW STATIC WORKS IN C ? ***

/*
#include <stdio.h>

void foo()
{
    int a = 10;
    static int sa = 10;
    
    a += 5;
    sa += 5;
    
    printf("a = %d, sa = %d\n", a, sa);
}


int main()
{
    int i;
    
    for (i = 0; i < 10; ++i)
        foo();
}
*/

/*
a = 15, sa = 15
a = 15, sa = 20
a = 15, sa = 25
a = 15, sa = 30
a = 15, sa = 35
a = 15, sa = 40
a = 15, sa = 45
a = 15, sa = 50
a = 15, sa = 55
a = 15, sa = 60

// https://stackoverflow.com/questions/572547/
    what-does-static-mean-in-c
*/

// -------------------------------------------------------------------------

// -------------------------------------------------------------------------
// *** VALGRIND TUTORIAL ***
// -------------------------------------------------------------------------

/*
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o prog
*/

/*
% valgrind ./prog						// simple valgrind
% valgrind --help ./prog				// open tutorial
% valgrind --show-leak-kinds=all ./prog	// what line of code is leak ?
% valgrind --leak-check=full ./prog		// check every type of leak.	
% valgrind --verbose ./prog				// related to F_2 (minishell & hard)
% valgrind --track-origins=yes ./prog	// ???, read at help. (minishell & hard)
% valgrind --show-leak-kinds=all --leak-check=full ./prog
*/

// -------------------------------------------------------------------------

// https://www.geeksforgeeks.org/c/linked-list-in-c/
// https://stackoverflow.com/questions/19769542/
//  reading-from-file-using-read-function
