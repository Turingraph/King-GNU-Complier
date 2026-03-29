# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/29 11:52:57 by phsottat          #+#    #+#              #
#    Updated: 2026/03/29 12:10:51 by phsottat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc -Wall -Wextra -Werror

OBJ = arc.o backstory.o biography.o dejavu.o eclipse.o tale.o
BUILD_OBJ = $(OBJ:%.o=build/%.o)

# the_illusion_of_separation.o

SRC = $(OBJ:%.o=%.c)

# To Compile my code run this.
# $(CC) main.c -L$(directory of $(NAME)) -l$(NAME) -o main_program

all: $(NAME)

# $@ = $(NAME)
# $^ = $(OBJ)
$(NAME): $(BUILD_OBJ)
	ar rcs $@ $^

# $@ = %.o
# $^ = %.c
build/%.o: %.c
	$(CC) -c $^ -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(BUILD_OBJ)

.PHONY: re all clean fclean
