#include "main.h"

/**
 * print_char - print char.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: chars number.
 */
int print_char(va_list ptr, ps_t *ps)
{
	char char_p = ' ';
	unsigned int pd = 1, res = 0, c = va_arg(ptr, int);

	if (ps->minus_flg)
	{
		res += _putchar(c);
	}
	while (pd++ < ps->width)
		res += _putchar(char_p);
	if (!ps->minus_flg)
		res += _putchar(c);
	return (res);
}

/**
 * print_string - print string.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: char number.
 */
int print_string(va_list ptr, ps_t *ps)
{

	unsigned int pd = 0, res = 0, x = 0, y;
	char *str = va_arg(ptr, char *), char_p = ' ';

	(void)ps;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;
	y = pd = _strlen(str);
	if (ps->precision < pd)
		y = pd = ps->precision;
	if (ps->minus_flg)
	{
		if (ps->precision != UINT_MAX)
			for (x = 0; x < pd; x++)
				res += _putchar(*str++);
		else
			res += _puts(str);
	}
	while (y++ < ps->width)
		res += _putchar(char_p);
	if (!ps->minus_flg)
	{
		if (ps->precision != UINT_MAX)
			for (x = 0; x < pd; x++)
				res += _putchar(*str++);
		else
			res += _puts(str);
	}
	return (res);

}

/**
 * print_percent - print string.
 * @ptr: pointer.
 * @ps: struct parametrs.
 * Return: chars.
 */
int print_percent(va_list ptr, ps_t *ps)
{
	(void)ptr;
	(void)ps;
	return (_putchar('%'));
}

/**
 * print_int - print integer.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: char number.
 */
int print_int(va_list ptr, ps_t *ps)
{
	long a;

	if (ps->l_modifier)
		a = va_arg(ptr, long);
	else if (ps->h_modifier)
		a = (short int)va_arg(ptr, int);
	else
		a = (int)va_arg(ptr, int);
	return (print_num(convert(a, 10, 0, ps), ps));
}

/**
 * print_s -  custom specifier.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: chars.
 */
int print_s(va_list ptr, ps_t *ps)
{
	int res = 0;
	char *str = va_arg(ptr, char *);
	char *hex;

	if ((int) (!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			res += _putchar('\\');
			res += _putchar('x');
			hex = convert(*str, 16, 0, ps);
			if (!hex[1])
				res += _putchar('0');
			res += _puts(hex);
		}
		else
		{
			res += _putchar(*str);
		}
	}
	return (res);
}

