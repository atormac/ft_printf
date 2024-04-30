/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:44:32 by atorma            #+#    #+#             */
/*   Updated: 2024/04/30 14:54:33 by atorma           ###   ########.fr       */
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

typedef struct write_state
{
	ssize_t	bytes_written;
	ssize_t	ret_val;
} write_state;

void	ft_write(struct write_state *ws, char *buf, size_t buf_size);
void	ft_putuint(unsigned int n);
void	print_char(struct write_state *ws, int c);
void	print_string(struct write_state *ws, char *str);
void	print_integer(struct write_state *ws, int n);
void	print_unsigned(struct write_state *ws, unsigned int n);
void	print_ptr(struct write_state *ws, unsigned long long ptr);
int		print_hex(struct write_state *ws, unsigned int n, int is_lower);
int		hex_uint(struct write_state *ws, unsigned int n, int is_lower);
int		print_hex_ptr(struct write_state *ws, unsigned long long n);
int		ft_printf(const char *f, ...);

#endif
