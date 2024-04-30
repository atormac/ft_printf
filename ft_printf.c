/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:47:24 by atorma            #+#    #+#             */
/*   Updated: 2024/04/30 14:49:28 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




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

static void	format_print(struct write_state *ws, va_list ap, const char *f)
{
	if (*f == 'c')
		print_char(ws, va_arg(ap, int));
	else if (*f == '%')
		print_char(ws, '%');
	else if (*f == 's')
		print_string(ws, va_arg(ap, char *));
	else if (*f == 'd' || *f == 'i')
		print_integer(ws, va_arg(ap, int));
	else if (*f == 'u')
		print_unsigned(ws, va_arg(ap, unsigned int));
	else if (*f == 'x')
		hex_uint(ws, va_arg(ap, int), 1);
	else if (*f == 'X')
		hex_uint(ws, va_arg(ap, int), 0);
	else if (*f == 'p')
		print_ptr(ws, va_arg(ap, unsigned long long));
}


int	ft_printf(const char *f, ...)
{
	va_list	ap;
	struct	write_state ws;

	va_start(ap, f);
	ws.bytes_written = 0;
	ws.ret_val = 0;
	while (*f)
	{
		if (*f == '%' && ft_strchr("cspdiuxX%", *(f + 1)))
		{
			f++;
			format_print(&ws, ap, f);
		}
		else
			ft_write(&ws, (char*)f, 1);
		if (ws.ret_val == -1)
			break;
		f++;
	}
	va_end(ap);
	if (ws.ret_val == -1)
		return (-1);
	return (ws.bytes_written);
}
