/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:24 by atorma            #+#    #+#             */
/*   Updated: 2024/04/26 14:46:48 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint(unsigned int n)
{
	unsigned int num;

	num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, 1);
	ft_putchar_fd('0' + (num % 10), 1);
}

int	num_len(long long num)
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

static int	format_print(va_list ap, const char *f)
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
		counter += print_uint(va_arg(ap, unsigned int));
	else if (*f == 'x')
		counter += print_hex(va_arg(ap, int), 1);
	else if (*f == 'X')
		counter += print_hex(va_arg(ap, int), 0);
	else if (*f == 'p')
		counter += print_ptr(va_arg(ap, unsigned long long));
	return (counter);
}

int	ft_printf(const char *f, ...)
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
