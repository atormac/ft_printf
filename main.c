#include "ft_printf.h"

int main(void)
{
	void *p = main;

	int counter = ft_printf("format: %s, %%, %s, %c, %d, %i, %u, %X, %p\n", NULL, "str", 'b', 12345, -123, UINT_MAX, -12416782, p);
	ft_printf("counter: %d\n", counter);
	ft_printf("null p: %p\n", 0);
	ft_printf("null x: %x\n", 0);
	ft_printf("LONG_MAX: %x\n", LONG_MAX);
	write(1, "\n", 1);
	int printf_counter = printf("format: %s, %%, %s, %c, %d, %i, %u, %X, %p\n", NULL, "str", 'b', 12345, -123, UINT_MAX, -12416782, p);
	printf("printf_counter: %d\n", printf_counter);
	printf("null p: %p\n", 0);
	printf("null x: %x\n", 0);
	printf("LONG_MAX: %x\n", LONG_MAX);
	return (0);
}
