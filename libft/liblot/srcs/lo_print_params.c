/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:59:29 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:51 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_print_params(int argc, char **argv)
{
	int i;

	if (!argv)
		return ;
	i = 1;
	while (argc > i)
	{
		lo_putstr(argv[i]);
		lo_putchar('\n');
		i++;
	}
}
