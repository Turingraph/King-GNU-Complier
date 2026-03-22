/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:56:28 by phsottat          #+#    #+#             */
/*   Updated: 2025/09/12 17:15:34 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//------------------------------------------------
// *** RIGHT VERSION ***
//------------------------------------------------

/*
What is the different between memmove vs memcpy ?

Use memmove when dest and src might be "overlap" (use the same block of memory).
Use memcpy when you sure that dest and src are not "overlap".

// https://youtu.be/DGwdAQauEV4?si=fvlITql0BQbDCVu5

What is the output data type of sizeof() operator ?

The sizeof operator evaluates to a value of type size_t. 
This type is unsigned and typically larger than an int.

// https://stackoverflow.com/questions/54463692/
// output-data-type-of-sizeof-operator
*/

// I must use unsigned char for id and is because 
// unsigned char use 1 byte.
// unsigned int use 4 bytes.

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*is;
	unsigned char	*temp;

	temp = (unsigned char *)malloc(sizeof(unsigned char) * n);
	if ((dest == NULL) || (src == NULL) || (temp == NULL))
		return (dest);
	i = 0;
	while (i < n)
	{
		is = (unsigned char *)(src + i);
		*(temp + i) = *is;
		i += 1;
	}
	i = 0;
	while (i < n)
	{
		is = (unsigned char *)(dest + i);
		*is = *(temp + i);
		i += 1;
	}
	free(temp);
	return (dest);
}

//------------------------------------------------
// *** MY TEST ***
//------------------------------------------------

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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

int	main(int av, char **array)
{
	char	*my_input;
	int		len;

	if (av < 2)
		return (0);
	len = f_strlen(*(array + 1));
	if (len < 4)
		return (0);

	write(1, "Input :\t", 8);
	write(1, *(array + 1), len);
	write(1, "\n", 1);

	my_input = (char *)malloc(len);
	f_strncpy(my_input, *(array + 1), len);

	//      +--[len - 2 = 6]
	// 01234567
	//    ^---[my_input + 3]
	// *(my_input + len) = '\0'; means to make 5 := '\0'
	ft_memmove(my_input + 3, my_input, len - 2);
	*(my_input + len) = '\0';
	write(1, "My Result:\t", 11);
	write(1, my_input, f_strlen(my_input));
	write(1, "\n", 1);

	memmove(*(array + 1) + 3, *(array + 1), len - 2);
	*(*(array + 1) + len) = '\0';
	write(1, "True Result:\t", 13);
	write(1, *(array + 1), f_strlen(*(array + 1)));
	write(1, "\n", 1);

	free(my_input);
	return (0);
}
*/

/*
// 1st Example
z2t12c3% ./a.out 01234567
Input : 01234567
My Result:      01201234
True Result:    01201234

// 2nd Example
z2t12c3% ./a.out Zutomayo ZutZutom
Input : Zutomayo
My Result:      ZutZutom
True Result:    ZutZutom
*/

//------------------------------------------------
// *** WAR MACHINE TEST ***
//------------------------------------------------
