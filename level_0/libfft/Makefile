# https://makefiletutorial.com/
# https://www.geeksforgeeks.org/c/how-do-i-create-a-library-in-c/
# file:///home/phsottat/Downloads/en.norm.pdf

NAME = libft.a

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

# Create the Static Library.
all: $(NAME)

# $(What_do_we_want_to_create): $(What_we_should_have_in_order_to_create_this)
# 	$(How_do_we_create_this)

$(NAME): $(OBJO)
	ar rcs $@ $(OBJO)

# Compile the Object Files.
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# https://www.geeksforgeeks.org/c/how-do-i-create-a-library-in-c/

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

# Compile c file with static library.
# https://stackoverflow.com/questions/
# 1705961/how-to-link-to-a-static-library-in-c
# cc -o test test.c libft.a
