#include "main.h"

/**
 * get_specifier - find the form function.
 * @s: string.
 * Return: printed bytes number.
 */
int (*get_specifier(char *s))(va_list ptr, ps_t *ps)
{
	specifier_t specifiers[] = {
		{"o", print_octal},
		{"b", print_binary},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	int a = 0;

	while (specifiers[a].specifier)
	{
		if (*s == specifiers[a].specifier[0])
		{
			return (specifiers[a].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - find func form.
 * @s: string.
 * @ptr: pointer.
 * @ps: struct parameters.
 * Return: printed bytes numbers.
 */
int get_print_func(char *s, va_list ptr, ps_t *ps)
{
	int (*f)(va_list, ps_t *) = get_specifier(s);

	if (f)
	{
		return (f(ptr, ps));
	}
	return (0);
}

/**
 * get_flg - flag function.
 * @s: string.
 * @ps: struct parameters.
 * Return: if flag vallid.
 */
int get_flg(char *s, ps_t *ps)
{
	int x = 0;

	switch (*s)
	{
		case '+':
			x = ps->plus_flg = 1;
			break;
		case ' ':
			x = ps->space_flg = 1;
			break;
		case '#':
			x = ps->hashtag_flg = 1;
			break;
		case '-':
			x = ps->minus_flg = 1;
			break;
		case '0':
			x = ps->zero_flg = 1;
			break;
	}
	return (x);
}

/**
 * get_modifier - find func modifier.
 * @s:string.
 * @ps: struct parameters.
 * Return: if modifier valid.
 */
int get_modifier(char *s, ps_t *ps)
{
	int x = 0;

	switch (*s)
	{
		case 'h':
			x = ps->h_modifier = 1;
			break;
		case 'l':
			x = ps->l_modifier = 1;
			break;
	}

	return (x);
}

/**
 * get_width - get width from form string.
 * @s: string.
 * @ps: struct paramenters.
 * @ptr: pointer.
 * Return: pointer.
 */
char *get_width(char *s, ps_t *ps, va_list ptr)
{
	int x = 0;

	if (*s == '*')
	{
		x = va_arg(ptr, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			x = x * 10 + (*s++ - '0');
	}
	ps->width = x;
	return (s);
}



















