
# Description

The goal of this project is to implement `int ft_printf(const char *, ...);` that works as same as `printf` from `stdio.h`. This function  has to handle the following conversions: `cspdiuxX%`
*	`%c` Prints a single character.
*	`%s` Prints a string (as defined by the common C convention).
*	`%p` The void * pointer argument has to be printed in hexadecimal format.
*	`%d` Prints a decimal (base 10) number.
*	`%i` Prints an integer in base 10.
*	`%u` Prints an unsigned decimal (base 10) number.
*	`%x` Prints a number in hexadecimal (base 16) lowercase format.
*	`%X` Prints a number in hexadecimal (base 16) uppercase format.
*	`%%` Prints a percent sign.

# Instruction

In order to test if my code works as expected
1.	you can create `test.c` file and copy my test case in this section.

```
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:17:53 by phsottat          #+#    #+#             */
/*   Updated: 2026/01/27 15:54:36 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <string.h>

	// write(1, "type = ", 7);
	// write(1, *type, strlen(type));
	// write(1, "\n", 1);
	// write(1, "input = ", 8);
	// write(1, input, strlen(input));
	// write(1, "\n", 1);

void	test_print(int tc, void *input, char *type)
{
	int	exp;
	int	res;

	printf("Testcase%d\n", tc);

	write(1, "Expected: ", 11);
	exp = printf(type, input);
	printf("\n");
	write(1, "Result  : ", 11);
	res = ft_printf(type, input);
	printf("\n");
	printf("Expected cnt: %d\n", exp);
	printf("Result   cnt: %d\n", res);
	printf("\n");
}

/*
	//...
	char	type[] = "%c";
	// ------------------------------
	test_print(1, "A", "%c");

	// ------------------------------
	int	exp;
	int	res;

	printf("Testcase%d\n", 1);

	write(1, "Expected: ", 11);
	exp = printf(type, 'A');
	printf("\n");
	write(1, "Result  : ", 11);
	res = ft_printf(type, "A");
	printf("\n");
	printf("Expected cnt: %d\n", exp);
	printf("Result   cnt: %d\n", res);
	printf("\n");
	//...
*/

/*
cc -Wall -Wextra -Werror test.c libftprintf.a
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
*/

int	main(void)
{
	/*-------------------- unit test char --------------------
	char	input_6 = 0;
	char	input_7 = 127;

	test_print(1, (void *) 'A', "%c");
	test_print(2, (void *) 'z', "%c");
	test_print(3, (void *) '0', "%c");
	test_print(4, (void *) ' ', "%c");
	test_print(5, (void *) '\n', "%c");
	test_print(6, (void *) (size_t) input_6, "%c");
	test_print(7, (void *) (size_t) input_7, "%c");
	test_print(8, (void *) 'X', "%c");
	test_print(9, (void *) '%', "%c");
	//--------------------------------------------------------*/

	/*------------------- unit test string -------------------
	test_print(1, "Hello", "%s");
    test_print(2, "", "%s");
    test_print(3, "42 Bangkok", "%s");
    test_print(4, NULL, "%s");
    test_print(5, "A", "%s");
    test_print(6, "This is a longer string for testing.", "%s");
	printf("Hello, I am %c\nI got grade %s\n", 'A', "Ohm");
	write(1, "\n", 1);
	ft_printf("Hello, I am %c\nI got grade %s\n", 'A', "Ohm");
	//--------------------------------------------------------*/

	/*------------------- unit test int ----------------------
	test_print(1, (void *) 0, "%d");
	test_print(2, (void *) 42, "%d");
	test_print(3, (void *) -42, "%d");
	test_print(4, (void *) 2147483647, "%d");
	test_print(5, (void *) -2147483648, "%d");
	test_print(6, (void *) 0, "%d");
	test_print(7, (void *) 123, "%d");
	test_print(8, (void *) -123, "%d");
	test_print(9, (void *) 2147483647, "%d");
	test_print(10, (void *) -2147483648, "%d");
	//--------------------------------------------------------*/

	/*------------------- integration test -------------------
	printf(
    "Hello, my name is %s\nI am %d years old. My grade is %c\n, gpa of %i\n",
    "Ohm", 20, 'A', 4);
	write(1, "\n", 1);
    ft_printf(
    "Hello, my name is %s\nI am %d years old. My grade is %c\n, gpa of %i\n",
    "Ohm", 20, 'A', 4);
	//--------------------------------------------------------*/

	/*------------------ unit test pointer -------------------
	int		x = 42;
	int		y = 0;
	char	c = 'A';

	test_print(1, &x, "%p");
	test_print(2, &y, "%p");
	test_print(3, &c, "%p");
	test_print(4, NULL, "%p");
	test_print(5, &x, "%p");
	test_print(6, (void *)42, "%p");
	test_print(7, (void *)9223372036854775807, "%p");
	test_print(8, (void *)-9223372036854775807, "%p");
	test_print(9, (void *)18446744073709551615u, "%p");
	//--------------------------------------------------------*/

	/*------------------- unit test unsigned -----------------
	printf("Expected: %u\n", 0);
	ft_printf("Result  : %u\n", 0);

	printf("Expected: %u\n", 42);
	ft_printf("Result  : %u\n", 42);

	printf("Expected: %u\n", 4294967295u);
	ft_printf("Result  : %u\n", 4294967295u);

	test_print(1, (void *) 0, "%u");
	test_print(2, (void *) 42, "%u");
	test_print(3, (void *) -1, "%u");
	test_print(4, (void *) -42, "%u");
	test_print(5, (void *) 2147483647, "%u");
	test_print(6, (void *) -2147483648, "%u");
	test_print(7, (void *) 4294967295u, "%u");
	//--------------------------------------------------------*/

	/*----------------- unit test hexadecimal x --------------
	test_print(1, (void *) 0, "%x");
	test_print(2, (void *) 42, "%x");
	test_print(3, (void *) 255, "%x");
	test_print(4, (void *) 4096, "%x");
	test_print(5, (void *) 4294967295u, "%x");
	//--------------------------------------------------------*/

	/*----------------- unit test hexadecimal X --------------
	test_print(1, (void *) 0, "%X");
	test_print(2, (void *) 42, "%X");
	test_print(3, (void *) 255, "%X");
	test_print(4, (void *) 4096, "%X");
	test_print(5, (void *) 4294967295u, "%X");
	//--------------------------------------------------------*/
}
```

2.	run `make` in this directory.
3.	run `cc -Wall -Wextra -Werror test.c libftprintf.a`
4.	run `./a.out`
5.	run `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out` to check memory leak.

# Resource

1.	Variadic Function
	1.	https://www.geeksforgeeks.org/c/variadic-functions-in-c/
2.	42 Coding School PrintFT Assignment Tester
	1.	https://github.com/qbornet/printfTester
