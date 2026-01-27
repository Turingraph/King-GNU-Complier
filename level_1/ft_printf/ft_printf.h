/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:03:53 by phsottat          #+#    #+#             */
/*   Updated: 2026/01/27 16:14:35 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_strlen(char *str);
int	print_int(unsigned long num, char *base);
int	print_large(long long input, char *base);
int	ft_putnbr(long long num, char *base);
int	print_pointer(long long input);
int	ft_printf(const char *str, ...);

#endif
