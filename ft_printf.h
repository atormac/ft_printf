/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:44:32 by atorma            #+#    #+#             */
/*   Updated: 2024/04/30 16:46:05 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct t_write_state
{
	ssize_t	bytes_written;
	ssize_t	ret_val;
}	t_write_state;

void	ft_write(struct t_write_state *ws, char *buf, size_t buf_size);
void	print_char(struct t_write_state *ws, int c);
void	print_string(struct t_write_state *ws, char *str);
void	print_integer(struct t_write_state *ws, int n);
void	print_unsigned(struct t_write_state *ws, unsigned int n);
void	print_ptr(struct t_write_state *ws, unsigned long long ptr);
void	print_hex(struct t_write_state *ws, unsigned int n, int is_lower);
void	hex_uint(struct t_write_state *ws, unsigned int n, int is_lower);
void	print_hex_ptr(struct t_write_state *ws, unsigned long long n);
int		ft_printf(const char *f, ...);

#endif
