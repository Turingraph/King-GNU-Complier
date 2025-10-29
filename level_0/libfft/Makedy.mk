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
# ├── libdy.h
# ├── libft.h
# ├── main.c
# ├── main.o
# ├── Makedy.mk
# ├── Makefile
# └── prog

#--------------------------------------------------------------------------

# main.c

#include "libdy.h"
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
