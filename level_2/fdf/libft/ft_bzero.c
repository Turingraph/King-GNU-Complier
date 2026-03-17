/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:54:10 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:03:58 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// https://stackoverflow.com/questions/16016920/
// type-casting-integer-to-void

// https://stackoverflow.com/questions/18851835/
// create-my-own-memset-function-in-c

/*
I would stick with memset simply because bzero is deprecated and reduces 
portability. I doubt you would see any real gains from using one over the other.
https://stackoverflow.com/questions/17096990/why-use-bzero-over-memset
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*y;

	y = s;
	i = 0;
	while (i < n)
	{
		*(y + i) = '\0';
		i += 1;
	}
}

/*
#include <unistd.h>
#include <bsd/string.h>

char	*f_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i += 1;
	}
	*(dst + i) = '\0';
	return (dst);
}

int	f_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

int	main(int av, char **ac)
{
	char	*vu;
	int		len;

	if (av < 2)
		return (0);
	len = f_strlen(*(ac + 1));
	vu = (char *)malloc(len + 1);
	f_strncpy(vu, *(ac + 1), len);
	ft_bzero(vu, 5);
	bzero(*(ac + 1), 5);
	write(1, "My Result:\t", 11);
	write(1, vu, len);
	write(1, "\n", 1);
	write(1, "True Result:\t", 13);
	write(1, *(ac + 1), len);
	write(1, "\n", 1);
	free(vu);
	return (0);
}
*/

//----------------------------------------------------------------------------
// *** UTILITY ***
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

/*
# create_files.sh
for file in $(cat name.txt); do
  cat comment_main.c >> "ft_$file.c"
done

# https://stackoverflow.com/questions/52901012/what-is-a-list-in-bash
# https://stackoverflow.com/questions/67121496/
# iterate-over-a-list-in-a-txt-file-on-bash
*/

//----------------------------------------------------------------------------

/*
# delete_files.sh
find . -name "ft_*.c" # show which files will be deleted.
# find . -name "ft_*.c" -exec rm {} \; # delete files actively.
# https://superuser.com/questions/482435/
# how-to-remove-all-files-starting-with-a-certain-string-in-linux
*/

//----------------------------------------------------------------------------

/*
# name.txt
isalpha
isdigit
isalnum
isascii
isprint
strlen
memset
bzero
memcpy
memmove
strlcpy
strlcat
toupper
tolower
strchr
strrchr
strncmp
memchr
memcmp
strnstr
atoi
calloc
strdup
substr
strjoin
strtrim
split
itoa
strmapi
striteri
putchar_fd
putstr_fd
putendl_fd
putnbr_fd
*/
