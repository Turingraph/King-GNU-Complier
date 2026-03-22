/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:05:46 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 10:59:46 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

/*
size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*y;

	y = (char *)malloc(f_strlen(s1) + f_strlen(s2));
	if (y == NULL)
		return (y);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(y + i) = *(s1 + i);
		i += 1;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(y + i + j) = *(s2 + j);
		j += 1;
	}
	*(y + i + j) = '\0';
	return (y);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i += 1;
	return (i);
}

/*
I use y = (char *)malloc(f_strlen(s1) + f_strlen(s2) + 1);
because I have make sure that the last char of y is '\0'.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*y;

	y = (char *)malloc(f_strlen(s1) + f_strlen(s2) + 1);
	if (y == NULL)
		return (y);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(y + i) = *(s1 + i);
		i += 1;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(y + i + j) = *(s2 + j);
		j += 1;
	}
	*(y + i + j) = '\0';
	return (y);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <stdio.h>

int	main(int av, char **ac)
{
	char	*y;

	if (av < 3)
		return (0);
	y = ft_strjoin(*(ac + 1), *(ac + 2));
	if (y == NULL)
	{
		write(1, "NULL\n", 5);
		return (0);
	}
	write(1, y, f_strlen(y));
	free(y);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
#include <string.h>
#include <unistd.h>

int		main(int argc, const char *argv[])
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	char	*strjoin;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(strjoin = ft_strjoin(s1, s2)))
			write(1, "NULL", 4);
		else
			write(1, strjoin, strlen(strjoin));
		if (strjoin == s1 || strjoin == s2)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 2)
	{
		s1[0] = '\0';
		if (!(strjoin = ft_strjoin(s1, s2)))
			write(1, "NULL", 4);
		else
			write(1, strjoin, strlen(strjoin));
		if (strjoin == s1 || strjoin == s2)
			write(1, "\nA new string was not returned", 30);
	}
	else if (arg == 3)
	{
		s2[0] = '\0';
		if (!(strjoin = ft_strjoin(s1, s2)))
			write(1, "NULL", 4);
		else
			write(1, strjoin, strlen(strjoin));
		if (strjoin == s1 || strjoin == s2)
			write(1, "\nA new string was not returned", 30);
	}
	write(1, "\n", 1);
	// else if (arg == 4)
	// {
	// 	s1[0] = '\0';
	// 	s2[0] = '\0';
	// 	if (!(strjoin = ft_strjoin(s1, s2)))
	// 		write(1, "NULL", 4);
	// 	else
	// 		write(1, strjoin, strlen(strjoin));
	// 	if (strjoin == s1 || strjoin == s2)
	// 		write(1, "\nA new string was not returned", 30);
	// }
	return (0);
}
*/
