# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 15:26:29 by phsottat          #+#    #+#              #
#    Updated: 2026/01/21 09:39:53 by phsottat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
CC = cc -Wall -Wextra -Werror
file_o = get_next_line.o get_next_line_utils.o

# make Makefile understand that those letter is not file name but instruction name.
.PHONY: re all clean fclean

re: fclean all

all: $(NAME)

$(NAME): $(file_o)
	ar rcs $(NAME).a $(file_o)

$(file_o): %.o: %.c
	$(CC) -c $^ -o $@

# delete object files
clean:
	rm -f $(file_o)

fclean: clean
	rm -f $(NAME).a
