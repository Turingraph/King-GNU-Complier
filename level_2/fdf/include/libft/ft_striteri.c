/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:58:48 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/18 11:00:26 by phsottat         ###   ########.fr       */
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

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (i < f_strlen(s))
	{
		f((unsigned int) i, s);
		i += 1;
	}
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
I have to use f((unsigned int) i, (s + i));
instead of f((unsigned int) i, s);
to """Applies the function ’f’ to each character of the
string passed as argument, passing its index as
the first argument.""".
In other words, I have to update i-th char of s, for every i.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (i < f_strlen(s))
	{
		f((unsigned int) i, (s + i));
		i += 1;
	}
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	f_toupper(unsigned int j, char *c)
{
	char	a;

	a = *(c + j);
	if ('a' <= a && a <= 'z')
		*(c + j) = (a - 'a' + 'A');
}

// https://stackoverflow.com/questions/9410/
// how-do-you-pass-a-function-as-a-parameter-in-c

int	main(int av, char **ac)
{
	if (av < 2)
		return (0);
	ft_striteri(*(ac + 1), f_toupper);
	write(1, *(ac + 1), f_strlen(*(ac + 1)));
	write(1, "\n", 1);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <string.h>

void	iter(unsigned int i, char *c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int		main(void)
{
	char	*str;

	// alarm(5);
	str = (char *)malloc(sizeof(*str) * 12);
	strcpy(str, "LoReM iPsUm");
	ft_striteri(str, &iter);
	write(1, str, 11);
	return (0);
}
*/

//------------------------------------------------
// *** LIBFT TESTER TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <string.h>

void
iter(unsigned int i, char * s) {
	*s += i;
}

int main(void)
{
	char s[] = "0000000000";
	ft_striteri(s, iter);
	write(1, s, strlen(s));
	write(1, "\n", 1);
	return (0);
}
*/
