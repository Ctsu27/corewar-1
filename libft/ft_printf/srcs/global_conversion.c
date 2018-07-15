/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:42:51 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 16:36:38 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printf_percent_conv(t_ptf *env, va_list *ap, int usls)
{
	(void)usls;
	(void)ap;
	++(env->index);
	(env->neg == 0) ? printf_handle_width_other(env, 1) : 0;
	printf_lo_putchar_buff(env, '%');
	(env->neg == 1) ? printf_handle_width_other(env, 1) : 0;
	++(env->size);
}

void		printf_c_conv(t_ptf *env, va_list *ap, int c)
{
	if (env->l_long == 1)
	{
		printf_ac_conv(env, ap, c);
		return ;
	}
	++(env->index);
	c = va_arg(*ap, int);
	(env->neg == 0) ? printf_handle_width_other(env, 1) : 0;
	printf_lo_putchar_buff(env, c);
	printf_reset_buf(env);
	c == 0 ? lo_putchar('\0') : 0;
	(env->neg == 1) ? printf_handle_width_other(env, 1) : 0;
	++(env->size);
}

void		printf_s_conv(t_ptf *env, va_list *ap, int null)
{
	char	*str;
	int		bigger;

	if (env->l_long == 1)
	{
		printf_as_conv(env, ap, 0);
		return ;
	}
	++(env->index);
	str = va_arg(*ap, char*);
	if (str == NULL)
	{
		if (!(str = lo_strdup("(null)")))
			return ;
		null = 1;
	}
	bigger = lo_strlen(str);
	if (env->precision_on == 1 && env->precision < bigger)
		bigger = env->precision;
	(env->neg == 0) ? printf_handle_width_other(env, bigger) : 0;
	env->precision_on ? printf_handle_precision_str(env, str)
	: printf_lo_putstr_buff(env, str);
	(env->neg == 1) ? printf_handle_width_other(env, bigger) : 0;
	env->size += bigger;
	null == 1 ? lo_strdel(&str) : 0;
}

void		printf_p_conv(t_ptf *env, va_list *ap, int bigger)
{
	char		*ptr;
	uintptr_t	x;

	++(env->index);
	x = va_arg(*ap, uintptr_t);
	if (env->precision_on == 1 && env->precision <= 0 && x == 0)
		ptr = lo_strdup("");
	else
		ptr = lo_itoa_base(x, 16);
	if (!ptr)
		return ;
	bigger = ((lo_strlen(ptr)) > env->precision) ?
	lo_strlen(ptr) + 2 : env->precision + 2;
	if (env->neg == 0 && env->zero == 0)
		printf_handle_width_other(env, bigger);
	printf_lo_putstr_buff(env, "0x");
	if (env->neg == 0 && env->zero == 1)
		printf_handle_width_other(env, bigger);
	printf_handle_precision_int(env, lo_strlen(ptr));
	printf_lo_putstr_buff(env, ptr);
	(env->neg == 1) ? printf_handle_width_other(env, bigger) : 0;
	(env->size) += bigger;
	lo_strdel(&ptr);
}

void		printf_reset_buf(t_ptf *env)
{
	env->buff[env->index_buff] = '\0';
	lo_putstr(env->buff);
	env->index_buff = 0;
}
