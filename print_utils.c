/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:47:00 by atorma            #+#    #+#             */
/*   Updated: 2024/04/30 16:09:07 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(struct t_write_state *ws, int c)
{
	char p;

	p = c;
	return (ft_write(ws, &p, 1));
}

void	print_string(struct t_write_state *ws, char *str)
{
	if (!str)
	{
		ft_write(ws, "(null)", sizeof("(null)") - 1);
		return;
	}
	ft_write(ws, str, ft_strlen(str));
}

void	print_integer(struct t_write_state *ws, int n)
{
	long long	num;
	char		c;

	num = n;
	if (num < 0)
	{
		c = '-';
		ft_write(ws, &c, 1);
		num *= -1;
	}
	if (num >= 10)
		print_integer(ws, num / 10);
	c = '0' + (num % 10);
	ft_write(ws, &c, 1);
}

void	print_unsigned(struct t_write_state *ws, unsigned int n)
{
	unsigned long	num;
	char		c;

	num = n;
	if (num < 0)
	{
		c = '-';
		ft_write(ws, &c, 1);
		num *= -1;
	}
	if (num >= 10)
		print_integer(ws, num / 10);
	c = '0' + (num % 10);
	ft_write(ws, &c, 1);
}

void print_ptr(struct t_write_state *ws, unsigned long long ptr)
{
	print_string(ws, "0x");
	if (ptr == 0)
	{
		print_char(ws, '0');
		return;
	}
	print_hex_ptr(ws, ptr);
}
