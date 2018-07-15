/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 05:03:47 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:52 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_putendl_fd(char const *s, int fd)
{
	if (!(s))
		return ;
	while (*s)
	{
		lo_putchar_fd(*s, fd);
		s++;
	}
	lo_putchar_fd('\n', fd);
}
