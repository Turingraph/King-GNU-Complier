/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:03:53 by phsottat          #+#    #+#             */
/*   Updated: 2026/01/27 15:43:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_strlen(char *str);
int	print_int(unsigned long num, char *base);
int	print_large(long long input, char *base);
int	ft_putnbr(int long num, char *base);
int	ft_printf(const char *str, ...);

#endif
