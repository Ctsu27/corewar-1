/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:00:49 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 16:36:38 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		printf_lo_putchar_buff(t_ptf *env, char c)
{
	if (env->index_buff < BUFF_SIZE - 1)
		env->buff[env->index_buff++] = c;
	if (env->index_buff + 1 == BUFF_SIZE)
		printf_reset_buf(env);
}

void		printf_lo_putstr_buff(t_ptf *env, char *str)
{
	int h;

	h = 0;
	if (!str)
		return ;
	while (env->index_buff < BUFF_SIZE - 1 && str[h])
	{
		env->buff[env->index_buff++] = str[h];
		++h;
		if (env->index_buff + 1 == BUFF_SIZE)
			printf_reset_buf(env);
	}
}

static	int	lo_filler(const char *format, t_ptf *env, va_list *ap)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (format[env->index])
	{
		if (format[env->index] == '%')
		{
			if (printf_launch_scan(env, ap) == -1)
				return (-1);
			printf_reset_value(env);
		}
		else if (format[env->index] == '{')
			printf_check_color(env, format);
		else
		{
			++(env->size);
			printf_lo_putchar_buff(env, format[env->index++]);
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_ptf	*env;
	int		bool;
	int		return_val;

	bool = 0;
	if ((env = printf_initialize_env()) == NULL)
		return (-1);
	va_start(ap, format);
	if (!(env->frmt = lo_strdup(format)))
		return (-1);
	bool = lo_filler(format, env, &ap);
	env->buff[env->index_buff] = '\0';
	if (env->index_buff > 0)
		lo_putstr(env->buff);
	va_end(ap);
	lo_strdel(&env->frmt);
	return_val = env->size;
	free(env);
	return (bool == -1 ? -1 : return_val);
}

int			printf_launch_scan(t_ptf *env, va_list *ap)
{
	++env->index;
	printf_attrib_start(env);
	printf_field_width_start(env);
	printf_precision_start(env);
	printf_flag_start(env);
	if (printf_convertion_start(env, ap) == -1)
		return (-1);
	return (1);
}
