#include "main.h"

/**
 * _isdigit - check if digit.
 * @c: character.
 * Return: 1 or 0.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - lenght of the string.
 * @s: string.
 * Return: integer.
 */
int _strlen(char *s)
{
	int x = 0;

	while (*s++)
	{
		x++;
	}
	return (x);
}


/**
 * print_num - print a number.
 * @str: string.
 * @ps: struct paramrter.
 * Return: characters.
 */
int print_num(char *str, ps_t *ps)
{
	unsigned int x = _strlen(str);
	int n = (!ps->unsign && *str == '-');

	if (!ps->precision && *str == '0' && !str[1])
		str = "";
	if (n)
	{
		str++;
		x--;
	}

	if (ps->precision != UINT_MAX)
		while (x++ < ps->precision)
			*--str = '0';
	if (n)
		*--str = '-';
	if (!ps->minus_flg)
		return (print_num_rights(str, ps));
	else
		return (print_num_lefts(str, ps));

}

/**
 * print_num_rights - print number.
 * @str: string.
 * @ps: struct parameter.
 * Return: pointer.
 */
int print_num_rights(char *str, ps_t *ps)
{
	unsigned int a = 0, N1, N2, b = _strlen(str);
	char char_p = ' ';

	if (ps->zero_flg && !ps->minus_flg)
		char_p = '0';
	N1 = N2 = (!ps->unsign && *str == '-');
	if (N1 && b < ps->width && char_p == '0' && !ps->minus_flg)
		str++;
	else
		N1 = 0;
	if ((ps->plus_flg && !N2) ||
	    (!ps->plus_flg && ps->space_flg && !N2))
		b++;
	if (N1 && char_p == '0')
		a += _putchar('-');
	if (ps->plus_flg && !N2 && char_p == '0' && !ps->unsign)
		a += _putchar('+');
	else if (!ps->plus_flg && ps->space_flg && !N2
			&& !ps->unsign && s->zero_flg)
		a += _putchar(' ');
	while (b++ < ps->width)
		a += _putchar(char_p);
	if (N1 && char_p == ' ')
		a += _putchar('-');
	if (ps->plus_flg && !N2 && char_p == ' ' && !ps->unsign)
		a += _putchar('+');
	else if (!ps->plus_flg && ps->space_flg && !N2 &&
			!ps->unsign && !ps->zero_flg)
		a += _putchar(' ');
	a += _puts(str);
	return (a);
}




































