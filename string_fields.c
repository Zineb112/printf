#include "main.h"

/**
 * get_prc - get-prc function.
 * @p: string.
 * @ps: struct parameters.
 * @ptr: pointer.
 * Return: pointer.
 */
char *get_prc(char *p, ps_t *ps, va_list ptr)
{
	int x = 0;

	if (*p != '.')
	{
		return (p);
	}
	p++;
	if (*p == '*')
	{
		x = va_arg(ptr, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
		{
			x = x * 10 + (*p++ - '0');
		}
	}
	ps->precision = x;
	return (p);
}
