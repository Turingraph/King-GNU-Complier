# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 15:26:29 by phsottat          #+#    #+#              #
#    Updated: 2026/01/26 13:06:25 by phsottat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc -Wall -Wextra -Werror
file_o = get_next_line.o get_next_line_utils.o

# You should avoid relinking in makefile.
# The command all should be the first command.
all: $(NAME)

$(NAME): $(file_o)
	ar rcs $(NAME) $(file_o)

# This 2 following lines in the comment are wrong.
# $(file_o): %.o: %.c
# 	$(CC) -c $^ -o $@
# Recompile header file when constant in header file e.g. BUFFER_SIZE etc. is change.
# -I = include
# $@ = the target. In this case, it is o file.
# $< = first prerequisite. In this case, it is the c file.
$(file_o): %.o: %.c get_next_line.h
	$(CC) -c -I . $< -o $@

# delete object files
clean:
	rm -f $(file_o)

fclean: clean
	rm -f $(NAME)

re: fclean all

# PHONY should be on the last line.
# make Makefile understand that those letter is not file name but instruction name.
.PHONY: re all clean fclean
