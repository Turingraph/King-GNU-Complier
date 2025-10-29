/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:56:02 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 10:57:10 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

/*
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*y;

	if (f_strlen(little) > f_strlen(big))
		return (NULL);
	i = 0;
	while (i < len && *(big + i) != '\0')
	{
		if (*(big + i) == *(little + 0))
		{
			j = 0;
			while (*(big + i + j) == *(little + j))
			{
				j += 1;
			}
			y = (char *)(big + i);
			if (j == f_strlen(little))
				return (y);
		}
		i += 1;
	}
	return (NULL);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

// #include <bsd/string.h>
// #include <unistd.h>
// #include <string.h>

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}
/*
// If little is an empty string, big is returned.
if (f_strlen(little) == 0)
	return ((char *) big);
// Add i + j < len, to make sure that the searched 
// string is identical to each other up to len, for example
// ft_strnstr("Radiohead", "head", 10) = "head"
// ft_strnstr("Radiohead", "head", 7) = NULL
// ft_strnstr("Radiohead", "head", 2) = NULL
while (*(big + i + j) == *(little + j) && i + j < len)
	j += 1;
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*y;

	if (f_strlen(little) > f_strlen(big))
		return (NULL);
	if (f_strlen(little) == 0)
		return ((char *) big);
	i = 0;
	while (i < len && *(big + i) != '\0')
	{
		if (*(big + i) == *(little + 0))
		{
			j = 0;
			while (*(big + i + j) == *(little + j) && i + j < len)
				j += 1;
			y = (char *)(big + i);
			if (j == f_strlen(little))
				return (y);
		}
		i += 1;
	}
	return (NULL);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <bsd/string.h>
#include <unistd.h>
#include <string.h>

int	main(int av, char **ac)
{
	char	*batoni;
	char	*oczy;

	if (av < 3)
		return (0);
	// batoni = *(ac + 1);
	batoni = strnstr(*(ac + 1), *(ac + 2), 28);
	oczy = ft_strnstr(*(ac + 1), *(ac + 2), 28);
	if (batoni != NULL)
	{
		write(1, batoni, strlen(batoni));
		write(1, "\n", 1);
	}
	else
		write(1, "NULL\n", 5);
	if (oczy != NULL)
	{
		write(1, oczy, strlen(oczy));
		write(1, "\n", 1);
	}
	else
		write(1, "NULL\n", 5);
	return (0);
}

// cc -Wall -Wextra -Werror -lbsd ft_strnstr.c 
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
int	main(void)
{
	const char *str;

	// if (!(str = strnstr("lorem ipsum dolor sit amet", "", 10)))
	// 	write(1, "NULL\n", 5);
	// else
	// {
	// 	write(1, str, strlen(str));
	// 	write(1, "\n", 1);
	// }
	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15)))
		write(1, "NULL\n", 5);
	else
	{
		write(1, str, strlen(str));
		write(1, "\n", 1);
	}
	return (0);
}
*/
