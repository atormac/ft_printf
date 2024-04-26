#include "ft_printf.h"

int main(void)
{
	void *p = main;

	int counter = ft_printf("format: %s, %%, %s, %c, %d, %i, %u, %X, %p\n", NULL, "str", 'b', 12345, -123, UINT_MAX, -12416782, p);
	ft_printf("counter: %d\n", counter);
	write(1, "\n", 1);
	int printf_counter = printf("format: %s, %%, %s, %c, %d, %i, %u, %X, %p\n", NULL, "str", 'b', 12345, -123, UINT_MAX, -12416782, p);
	printf("printf_counter: %d\n", printf_counter);
	return (0);
}
