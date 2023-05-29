#include "main.h"

/**
 * init_ps.c - Reset buffer and clear struct field.
 * @ps: struct parameters.
 * @ptr: pointer arg.
 */
void init_ps(ps_t *ps, va_list ptr)
{
	ps->unsign = 0;
	ps->plus_flg = 0;
	ps->space_flg = 0;
	ps->hashtag_flg = 0;
	ps->zero_flg = 0;
	ps->minus_flg = 0;
	ps->width = 0;
	ps->precision = UINT_MAX;
	ps->h_modifier = 0;
	ps->l_modifier = 0;
	(void)ptr;
}
