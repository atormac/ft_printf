/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:24 by atorma            #+#    #+#             */
/*   Updated: 2024/04/22 19:28:31 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

void	print_uint(unsigned int n)
{
	unsigned int num;

	num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, 1);
	ft_putchar_fd('0' + (num % 10), 1);
}

int	ft_int_len(long long num)
{
	int	length;

	length = 1;
	if (num < 0)
	{
		length++;
		num *= -1;
	}
	while (num >= 10)
	{
		num /= 10;
		length++;
	}
	return (length);
}
int print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	len;

	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int print_integer(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_int_len(n));
}

int	format_print(va_list ap, const char *f)
{
	int	counter;

	counter = 0;
	if (*f == 'c')
		counter += print_char(va_arg(ap, int));
	else if (*f == '%')
		counter += print_char('%');
	else if (*f == 's')
		counter += print_string(va_arg(ap, char*));
	else if (*f == 'd' || *f == 'i')
		counter += print_integer(va_arg(ap, int));
	else if (*f == 'u')
		print_uint(va_arg(ap, unsigned int));
	return (counter);
}

int ft_printf(const char *f, ...)
{
	va_list ap;
	int		counter;

	va_start(ap, f);
	counter = 0;
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			counter += format_print(ap, f);
		}
		else
		{
			ft_putchar_fd(*f, 1);
			counter++;
		}
		f++;
	}
	va_end(ap);
	return (counter);
}

int main(void)
{
	void *p = format_print;

	int counter = ft_printf("format: %%, %s, %c, %s, %d, %i, %u\n", "str", 'b', "second", 12345, 123, UINT_MAX);
	ft_printf("counter: %d\n", counter);
	write(1, "\n", 1);
	int printf_counter = printf("format: %%, %s, %c, %s, %d, %i, %u\n", "str", 'b', "second", 12345, 123, UINT_MAX);
	printf("printf_counter: %d\n", printf_counter);
	return (0);
}
