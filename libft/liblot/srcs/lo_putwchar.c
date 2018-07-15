/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:53:54 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:54 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	filler(int time, char *ref, int i)
{
	int		j;
	int		val;
	char	*tmpchar;
	char	*hold_oct;

	val = 0;
	j = 0;
	while (j++ < time)
	{
		tmpchar = lo_strsub(ref, (unsigned int)val, 8);
		hold_oct = lo_base_conv(tmpchar, 2, 10);
		i = lo_atoi(hold_oct);
		write(1, &i, 1);
		lo_strdel_two(&tmpchar, &hold_oct);
		val += 8;
	}
}

static	void	two_oct(char *bin, int i, int j)
{
	char	*ref;

	ref = lo_strdup("110xxxxx10xxxxxx");
	i = lo_strlen(ref) - 1;
	j = lo_strlen(bin) - 1;
	while (j >= 0)
	{
		if (ref[i] == 'x')
		{
			ref[i] = bin[j];
			--j;
		}
		--i;
	}
	ref = lo_str_replace(ref, 'x', '0');
	filler(2, ref, i);
	lo_strdel(&ref);
}

static	void	three_oct(char *bin, int i, int j)
{
	char	*ref;

	ref = lo_strdup("1110xxxx10xxxxxx10xxxxxx");
	i = lo_strlen(ref) - 1;
	j = lo_strlen(bin) - 1;
	while (j >= 0)
	{
		if (ref[i] == 'x')
		{
			ref[i] = bin[j];
			--j;
		}
		--i;
	}
	ref = lo_str_replace(ref, 'x', '0');
	filler(3, ref, i);
	lo_strdel(&ref);
}

static	void	four_oct(char *bin, int i, int j)
{
	char	*ref;

	ref = lo_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	i = lo_strlen(ref) - 1;
	j = lo_strlen(bin) - 1;
	while (j >= 0)
	{
		if (ref[i] == 'x')
		{
			ref[i] = bin[j];
			--j;
		}
		--i;
	}
	ref = lo_str_replace(ref, 'x', '0');
	filler(4, ref, i);
	lo_strdel(&ref);
}

void			lo_putwchar(wchar_t wchar)
{
	char	*bin;

	bin = lo_itoa_base(wchar, 2);
	if (wchar <= 0x7f)
		lo_putchar((char)wchar);
	else if (wchar <= 0x7ff)
		two_oct(bin, 0, 0);
	else if (wchar <= 0xffff)
		three_oct(bin, 0, 0);
	else if (wchar <= 0x1FFFFF)
		four_oct(bin, 0, 0);
	lo_strdel(&bin);
}
