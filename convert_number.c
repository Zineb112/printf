#include "main.h"

/**
 * print_hex - print lowercase hex.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: bytes.
 */
int print_hex(va_list ptr, ps_t *ps)
{
	int i = 0;
	char *str;
	unsigned long x;

	if (ps->l_modifier)
		x = (unsigned long)va_arg(ptr, unsigned long);
	else if (ps->h_modifier)
		x = (unsigned short int)va_arg(ptr, unsigned int);
	else
		x = (unsigned int)va_arg(ptr, unsigned int);
	str = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, ps);
	if (ps->hashtag_flg && x)
	{
		*--str = 'x';
		*--str = '0';
	}
	ps->unsign = 1;
	return (i += print_num(str, ps));
}

/**
 * print_HEX - print uppercase hex.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: bytes.
 */
int print_HEX(va_list ptr, ps_t *ps)
{
	int i = 0;
	char *str;
	unsigned long x;

	if (ps->l_modifier)
		x = (unsigned long)va_arg(ptr, unsigned long);
	else if (ps->h_modifier)
		x = (unsigned short int)va_arg(ptr, unsigned int);
	else
		x = (unsigned int)va_arg(ptr, unsigned int);

	str = convert(x, 16, CONVERT_UNSIGNED, ps);
	if (ps->hashtag_flg && x)
	{
		*--str = 'x';
		*--str = '0';
	}
	ps->unsign = 1;
	return (i += print_num(str, ps));
}

/**
 * print_binary - print binary.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: bytes.
 */
int print_binary(va_list ptr, ps_t *ps)
{
	int x = 0;
	unsigned int i = va_arg(ptr, unsigned int);
	char *str = convert(i, 2, CONVERT_UNSIGNED, ps);

	if (ps->hashtag_flg && i)
		*--str = '0';
	ps->unsign = 1;
	return (x += print_num(str, ps));
}


/**
 * print_octal - print octal.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: bytes.
 */
int print_octal(va_list ptr, ps_t *ps)
{
	int x = 0;
	char *str;
	unsigned long i;

	if (ps->l_modifier)
		i = (unsigned long)va_arg(ptr, unsigned long);
	else if (ps->h_modifier)
		i = (unsigned short int)va_arg(ptr, unsigned int);
	else
		i = (unsigned int)va_arg(ptr, unsigned int);
	str = convert(i, 8, CONVERT_UNSIGNED, ps);

	if (ps->hashtag_flg && i)
		*--str = '0';
	ps->unsign = 1;
	return (x += print_num(str, ps));
}




















