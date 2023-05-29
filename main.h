#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED  2

/**
* struct parameters - parameters struct.
* @unsign: flag in case the value is unsigned.
* @plus_flg: plus flag.
* @space_flg:space flag.
* @hashtag_flg: hashtag flag.
* @zero_flg: zero falg.
* @minus_flg: minus flag.
* @width: field width specified
* @precision: field precision specified
* @h_modifier: h modifier.
* @l_modifier: l modifier.
*
*/

typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flg : 1;
	unsigned int space_flg : 1;
	unsigned int hashtag_flg : 1;
	unsigned int zero_flg : 1;
	unsigned int minus_flg : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} ps_t;

/* print_functions.c */
int print_char(va_list ptr, ps_t *ps);
int print_string(va_list ptr, ps_t *ps);
int print_percent(va_list ptr, ps_t *ps);
int print_int(va_list ptr, ps_t *ps);
int print_s(va_list ptr, ps_t *ps);

/**
 * struct specifier - struct token.
 * @specifier: token form.
 * @f: associated function.
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, ps_t *);
} specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* specifier.c */
int (*get_specifier(char *s)) (va_list ptr, ps_t *ps);
int get_print_func(char *s, va_list ptr, ps_t *ps);
int get_flg(char *s, ps_t *ps);
int get_modifier(char *s, ps_t *ps);
char *get_width(char *s, ps_t *ps, va_list ap);

/* number.c */
char *convert(long int num, int base, int flgs, ps_t *ps);
int print_unsigned(va_list ptr, ps_t *ps);
int print_address(va_list ptr, ps_t *ps);

/* convert_number.c */
int print_hex(va_list ptr, ps_t *ps);
int print_HEX(va_list ptr, ps_t *ps);
int print_binary(va_list ptr, ps_t *ps);
int print_octal(va_list ptr, ps_t *ps);

/* print_num.c */
int _isdigit(int c);
int _strlen(char *s);
int print_num(char *str, ps_t *ps);
int print_num_rights(char *str, ps_t *ps);
int print_num_lefts(char *str, ps_t *ps);

/* simple_printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rotl3(va_list ptr, ps_t *ps);
int print_rev(va_list ptr, ps_t *ps);

/* ps.c*/
void init_ps(ps_t *ps, va_list ptr);

/* str_fields.c */
char *get_prc(char *p, ps_t *ps, va_list ptr);

/* _printf.c Prototype */
int _printf(const char *format, ...);

#endif
