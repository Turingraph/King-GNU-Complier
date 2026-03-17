/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:06:26 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:30:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//------------------------------------------------
// *** WRONG VERSION ***
//------------------------------------------------

/*
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*y;

	i = 0;
	while (*(s + i) != '\0')
	{
		y = (char *)(s + i);
		if (*(s + i) == c)
			return (y);
		i += 1;
	}
	return (0);
}
*/

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

/*
// This is used in case where c >= 256
if (c >= 256)
	c = c % 256;

// This is used in case when c == '\0'
// We have to return the last item of y which 
// is pointer of '\0' = *(y + i)
if (c == '\0')
{
	while (*(s + i) != '\0')
		i += 1;
	y = (char *)(s + i);
	return (y);
}
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*y;

	i = 0;
	if (c >= 256)
		c = c % 256;
	if (c == '\0')
	{
		while (*(s + i) != '\0')
			i += 1;
		y = (char *)(s + i);
		return (y);
	}
	while (*(s + i) != '\0')
	{
		y = (char *)(s + i);
		if (*(s + i) == c)
			return (y);
		i += 1;
	}
	return (0);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <string.h>
#include <unistd.h>

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
	char	*my_y;
	char	*th_y;

	if (av < 3)
		return (0);
	my_y = strchr(*(ac + 1), **(ac + 2) + 256);
	th_y = strchr(*(ac + 1), **(ac + 2) + 256);
	if (my_y == NULL || th_y == NULL)
	{
		if (my_y == NULL)
			write(1, "my_y == NULL\n", 13);
		if (th_y == NULL)
			write(1, "th_y == NULL\n", 13);
		return (0);
	}
	write(1, my_y, f_strlen(my_y));
	write(1, "\n", 1);
	write(1, th_y, f_strlen(th_y));
	write(1, "\n", 1);
	return (0);
}
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------

/*
int	main(void)
{
	char		*str;
	char		str2[] = "bonjour";

	if (!(str = strchr(str2, '\0')))
		write(1, "NULL\n", 5);
	else
	{
		write(1, "42School\n", 9);
		write(1, str, strlen(str));
		write(1, "\n", 1);
		if (str != str2 + 7)
			write(1, "Return value is false\n", 23);
	}
	return (0);
}
*/
