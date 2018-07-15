/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicod_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:25:17 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 16:36:40 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printf_ac_conv(t_ptf *env, va_list *ap, int c)
{
	wchar_t wchar;

	(void)c;
	wchar = va_arg(*ap, wchar_t);
	(env->neg == 0) ? printf_handle_width_other(env, 1) : 0;
	printf_reset_buf(env);
	lo_putwchar(wchar);
	(env->neg == 1) ? printf_handle_width_other(env, 1) : 0;
	if (wchar <= 0x7f)
		(env->size) += 1;
	else if (wchar <= 0x7ff)
		(env->size) += 2;
	else if (wchar <= 0xffff)
		(env->size) += 3;
	else if (wchar <= 0x1FFFFF)
		(env->size) += 4;
	++(env->index);
}

static int	get_all_oct(wchar_t *str)
{
	int i;
	int oct;

	oct = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= 0x7f)
			oct += 1;
		else if (str[i] <= 0x7ff)
			oct += 2;
		else if (str[i] <= 0xffff)
			oct += 3;
		else if (str[i] <= 0x1FFFFF)
			oct += 4;
		++i;
	}
	return (oct);
}

void		printf_handle_width_unicod(t_ptf *env, int size)
{
	while (env->width > size)
	{
		if (env->zero && env->precision == 0)
			printf_lo_putchar_buff(env, '0');
		else
			printf_lo_putchar_buff(env, ' ');
		++size;
		++(env->size);
	}
}

static void	filler_null(int bigger, t_ptf *env)
{
	char *ptr;

	if (!(ptr = lo_strdup("(null)")))
		return ;
	bigger = lo_strlen(ptr);
	if (env->precision_on && env->precision < bigger)
		bigger = env->precision;
	(env->neg == 0) ? printf_handle_width_other(env, bigger) : 0;
	env->precision_on ? printf_handle_precision_str(env, ptr)
		: printf_lo_putstr_buff(env, ptr);
	(env->neg == 1) ? printf_handle_width_other(env, bigger) : 0;
	env->size += bigger;
	lo_strdel(&ptr);
}

void		printf_as_conv(t_ptf *env, va_list *ap, int bigger)
{
	wchar_t	*str;

	++(env->index);
	str = va_arg(*ap, wchar_t*);
	if (str == NULL)
		filler_null(bigger, env);
	else
	{
		bigger = get_all_oct(str);
		(env->precision_on == 1 && env->precision < bigger)
			? bigger = env->precision : 0;
		(env->neg == 0) ? printf_handle_width_unicod(env, bigger) : 0;
		env->precision_on ? 0 : (env->size += bigger);
		if (env->precision_on)
			printf_handle_precision_wstr(env, str);
		else
		{
			printf_reset_buf(env);
			lo_putwstr(str);
		}
		(env->neg == 1) ? printf_handle_width_unicod(env, bigger) : 0;
	}
}
