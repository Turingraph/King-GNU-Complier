# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 14:22:26 by phsottat          #+#    #+#              #
#    Updated: 2026/01/26 15:03:53 by phsottat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror
file_o = ft_printf.o ft_putnbr.o

# all command should be in the first line.
all: $(NAME)

re: fclean all

$(NAME): $(file_o)
	ar rcs $(NAME) $(file_o)

$(file_o): %.o: %.c
	$(CC) -c $^ -o $@

# delete object files
clean:
	rm -f $(file_o)

fclean: clean
	rm -f $(NAME)

# PHONY should be in the last line.
# make Makefile understand that those letter is not file name but instruction name.
.PHONY: re all clean fclean
