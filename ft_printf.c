/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:24 by atorma            #+#    #+#             */
/*   Updated: 2024/04/22 18:31:33 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

void	write_str(char *s)
{
	while (*s)
		write(1, s++, 1);
}

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
}
int ft_printf(const char *f, ...)
{
	va_list ap;
	int	arg_count;

	arg_count = count_args(f);
	va_start(ap, f);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			format_print(ap, f);
		}
		else
			ft_putchar_fd(*f, 1);
		f++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	void *p = format_print;

	ft_printf("format: %%, %s, %c, %s, %d, %i\n", "str", 'b', "second", 12345, 123);
	ft_printf("no args\n");
	write(1, "\n", 1);
	printf("format: %%, %s, %c, %s, %d, %i, %p\n", "str", 'b', "second", 12345, 123, p);
	return (0);
}
