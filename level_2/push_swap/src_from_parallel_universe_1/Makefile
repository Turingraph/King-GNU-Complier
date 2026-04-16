# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/16 12:40:31 by phsottat          #+#    #+#              #
#    Updated: 2026/04/16 13:09:13 by phsottat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap_lib

CC = cc -Wall -Wextra -Werror

OBJ = arc.o backstory.o biography.o dejavu.o eclipse.o hero_journey.o

BUILD_OBJ = $(OBJ:%.o=build/%.o)

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
