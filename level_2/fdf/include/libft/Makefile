# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 14:21:45 by phsottat          #+#    #+#              #
#    Updated: 2026/03/17 16:55:18 by phsottat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This Makefile script compile static library.
# It is usually recommended to use Dynamic linking in most case for saving memory
# unless there is DLL HELL and/or performanced related issue,
# but static linking is better when the library is small, because it avoid 
# DLL HELL and it is usually easier to execute.
# https://stackoverflow.com/questions/1993390/static-linking-vs-dynamic-linking

NAME = libft.a

CC = cc -Wall -Wextra -Werror

OBJ = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
	ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o \
	ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o \
	ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o \
	ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o \
	ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o \
	ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o \
	ft_strmapi.o ft_striteri.o ft_putchar_fd.o \
	ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o

SRC = $(OBJ:%.o=%.c)

# To Compile my code run this.
# $(CC) main.c -L$(directory of $(NAME)) -l$(NAME) -o main_program

all: $(NAME)

# $@ = $(NAME)
# $^ = $(OBJ)
$(NAME): $(OBJ)
	ar rcs $@ $^

# $@ = %.o
# $^ = %.c
%.o: %.c
	$(CC) -c $^ -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

.PHONY: re all clean fclean

# https://makefiletutorial.com/
# https://www.geeksforgeeks.org/c/how-do-i-create-a-library-in-c/
