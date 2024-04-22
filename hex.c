
#include "ft_printf.h"

int	print_hex(unsigned int n, int is_lower)
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
		write(1, &result[i], 1);
	}
	return (counter);
}

int	print_hex_ptr(unsigned long long n)
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
		write(1, &result[i], 1);
	}
	return (counter);
}
