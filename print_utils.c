/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:47:00 by atorma            #+#    #+#             */
/*   Updated: 2024/04/26 15:13:09 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int print_integer(int n)
{
	ft_putnbr_fd(n, 1);
	return (num_len(n));
}

int	print_uint(unsigned int n)
{
	ft_putuint(n);
	return (num_len(n));
}

int	print_ptr(unsigned long long ptr)
{
	ft_putstr_fd("0x", 1);
	return print_hex_ptr(ptr) + 2;
}
