/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:23:30 by atorma            #+#    #+#             */
/*   Updated: 2024/04/30 16:14:52 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_write(struct t_write_state *ws, char *buf, size_t buf_size)
{
	size_t	ret;

	if (buf_size == 0 || ws->ret_val == -1)
		return ;
	ret = write(1, buf, buf_size);
	if (ret < 0)
		ws->ret_val = -1;
	ws->bytes_written += ret;
}
