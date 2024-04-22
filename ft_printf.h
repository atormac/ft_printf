#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
# include "libft.h"

int	print_hex(unsigned int n, int is_lower);
int	print_hex_ptr(unsigned long long n);

#endif
