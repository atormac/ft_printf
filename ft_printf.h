/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:44:32 by atorma            #+#    #+#             */
/*   Updated: 2024/04/26 14:44:50 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

void	ft_putuint(unsigned int n);
int		num_len(long long num);
int		print_char(int c);
int		print_string(char *str);
int		print_integer(int n);
int		print_uint(unsigned int n);
int		print_ptr(unsigned long long ptr);
int		print_hex(unsigned int n, int is_lower);
int		print_hex_ptr(unsigned long long n);
int		ft_printf(const char *f, ...);

#endif
