#include "main.h"

/**
 * get_specifier - find the form function.
 * @s:  string.
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
