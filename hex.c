/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:47:00 by atorma            #+#    #+#             */
/*   Updated: 2024/04/30 14:48:44 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(struct write_state *ws, unsigned int n, int is_lower)
{
	int		i;
	int		counter;
	char	tmp;
	char	result[32];

	i = 0;
	while (n != 0)
	{
		tmp = n % 16;
		if ((n % 16) < 10)
			tmp += 48;
		else
			tmp += 55;
		result[i++] = tmp;
		n /= 16;
	}
	counter = i;
	while (i-- > 0)
	{
		if (is_lower)
			result[i] = ft_tolower(result[i]);
		print_char(ws, result[i]);
	}
	return (counter);
}

int	hex_uint(struct write_state *ws, unsigned int n, int is_lower)
{
	if (n == 0)
	{
		print_char(ws, '0');
		return (1);
	}
	return (print_hex(ws, n, is_lower));
}

int	print_hex_ptr(struct write_state *ws, unsigned long long n)
{
	int		i;
	int		counter;
	char	tmp;
	char	result[32];

	i = 0;
	while (n != 0)
	{
		tmp = n % 16;
		if ((n % 16) < 10)
			tmp += 48;
		else
			tmp += 55;
		result[i++] = tmp;
		n /= 16;
	}
	counter = i;
	while (i-- > 0)
	{
		result[i] = ft_tolower(result[i]);
		print_char(ws, result[i]);
	}
	return (counter);
}
