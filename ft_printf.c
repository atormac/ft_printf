/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:24 by atorma            #+#    #+#             */
/*   Updated: 2024/04/22 18:59:37 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

int	count_args(const char *f)
{
	int	count;

	count = 0;
	while (*f)
	{
		if (*f == '%')
		{
			count++;
		}
		f++;
	}
	return (count);
}

void	print_uint(unsigned int n)
{
	unsigned int num;

	num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, 1);
	ft_putchar_fd('0' + (num % 10), 1);
}

void	format_print(va_list ap, const char *f)
{
	if (*f == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*f == '%')
		ft_putchar_fd('%', 1);
	else if (*f == 's')
		ft_putstr_fd(va_arg(ap, char*), 1);
	else if (*f == 'd' || *f == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*f == 'u')
		print_uint(va_arg(ap, unsigned int));
}
int ft_printf(const char *f, ...)
{
	va_list ap;
	int	count_printed;

	va_start(ap, f);
	count_printed = 0;
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			format_print(ap, f);
		}
		else
		{
			ft_putchar_fd(*f, 1);
			count_printed++;
		}
		f++;
	}
	va_end(ap);
	return (count_printed);
}

int main(void)
{
	void *p = format_print;

	ft_printf("format: %%, %s, %c, %s, %d, %i, %u\n", "str", 'b', "second", 12345, 123, UINT_MAX);
	ft_printf("no args\n");
	write(1, "\n", 1);
	printf("format: %%, %s, %c, %s, %d, %i, %u\n", "str", 'b', "second", 12345, 123, UINT_MAX);
	return (0);
}
