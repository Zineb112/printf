#include "main.h"

/**
 * convert - convert number.
 * @num: a number.
 * @base: the base.
 * @flgs: flags.
 * @ps: struct paramater.
 * Return: string.
 */
char *convert(long int num, int base, int flgs, ps_t *ps)
{
	static char *arr;
	static char buff[50];
	char sin = 0;
	char *ptr;
	unsigned long x = num;
	(void)ps;

	if (!(flgs & CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		sin = '-';
	}
	arr = flgs & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do {
		*--ptr = arr[x % base];
		x /= base;
	} while (x != 0);
	if (sin)
		*--ptr = sin;
	return (ptr);
}

/**
 * print_unsigned - gives an integer numbers.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: bytes.
 */
int print_unsigned(va_list ptr, ps_t *ps)
{
	unsigned long n;

	if (ps->l_modifier)
	{
		n = (unsigned long)va_arg(ptr, unsigned long);
	}
	else if (ps->h_modifier)
	{
		n = (unsigned short int)va_arg(ptr, unsigned int);
	}
	else
		n = (unsigned int)va_arg(ptr, unsigned int);
	ps->unsign = 1;
	return (print_number(convert(n, 10, CONVERT_UNSIGNED, ps), ps));
}


/**
 * print_address - print adress.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: bytes.
 */
int print_address(va_list ptr, ps_t *ps)
{
	unsigned long int x = va_arg(ptr, unsigned long int);
	char *s;

	if (!x)
		return (_puts("(nil)"));
	s = convert(x, 16, CONVERT_UNSIGNED | CONVER_LOWERCASE, ps);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, ps));
}








































































