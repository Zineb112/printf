#include "main.h"

/**
 * print_from_to - print from to function.
 * @start: start address.
 * @stop: stop address.
 * @except: excpt adress.
 * Return: printed bytes number.
 */
int print_from_to(char *start, char *stop, char *except)
{
	int res = 0;

	while (start <= stop)
	{
		if (start != except)
		{
			if (start != except)
				res += _putchar(*start);
			start++;
		}
	}
	return (res);
}

/**
 * print_rev - revers strings.
 * @ptr: string.
 * @ps: struct parameters.
 * Return: printed bytes num.
 */
int print_rev(va_list ptr, ps_t *ps)
{
	int l, s = 0;
	char *sr = va_arg(ptr, char *);
	(void)ps;

	if (sr)
	{
		for (l = 0; *sr; sr++)
			l++;
		sr--;
		for (; l > 0; l--, sr++)
			s += _putchar(*sr);
	}
	return (s);
}

/**
 * print_rot13 - print rot13 string.
 * @ptr: string.
 * @ps: struct paramenters.
 * Return: bytes numbers.
 */
int print_rot13(va_list ptr, ps_t *ps)
{
	int a, b;
	int count = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM       nopqrstuvwxyzabcdefghijklm";
	char *x = va_arg(ptr, char *);
	(void)ps;

	a = 0;
	b = 0;
	while (x[a])
	{
		if ((x[a] >= 'A' && x[a] <= 'Z')
				|| (x[a] >= 'a' && x[a] <= 'z'))
			b = x[a] - 65;
			count += _putchar(array[b]);
		else
			count += _putchar(x[a]);
		a++;
	}
	return (count);
}










































