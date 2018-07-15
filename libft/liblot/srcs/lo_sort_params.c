/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:22:19 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:55 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		lo_sort_params(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		return ;
	while ((i <= argc - 2))
	{
		if (lo_strcmp(argv[i + 1], argv[i]) == -1)
		{
			lo_swap_str(argv[i + 1], argv[i]);
			i = 0;
		}
		i++;
	}
	i = 1;
	while (i <= argc - 1)
	{
		lo_putstr(argv[i]);
		lo_putchar('\n');
		i++;
	}
}
