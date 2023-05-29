#include "main.h"

/**
 * _puts - print string.
 * @str: string.
 */
int _puts(char *str)
{
	char *x = str;

	while (*str)
	{
		_putcha(*str++);
	}
	return (str - x);
}

/**
 * _putchar - check code.
 * @c: character.
 * Return: 1 on success and -1 on error.
 */
int _putchar(int c)
{
	static int x;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || x >= OUTPUT_BUT_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[x++] = c;
	}
	return (1);
}
