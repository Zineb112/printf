#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: pointer.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int result = 0;
	va_list ptr;

	char *p, *start;
	ps_t ps = PS_INIT;

	va_start(ptr, format);
	if ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_ps(&ps, ptr);
		if (*p != '%')
		{
			result += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flg(p, &ps))
			p++;
		p = get_width(p, &ps, ptr);
		p = get_prc(p, &ps, ptr);

		if (get_modifier(p, &ps))
			p++;
		if (!get_specifier(p))
		{
			result += print_form_to(start, p,
			ps.l_modifier || ps.h_modifier ? p - 1 : 0);
		}
		else
		{
			result += get_print_func(p, ptr, &ps);
		}
	}
}

