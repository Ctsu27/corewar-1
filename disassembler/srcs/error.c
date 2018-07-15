/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:55:39 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/22 16:32:46 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"
#include "libft.h"

void	ft_panic(char opt)
{
	if (opt == 1)
		ke_putstr("error: malloc\n");
	if (opt == 2)
		ke_putstr("error: open\n");
	exit(EXIT_FAILURE);
}

void	ft_last_resort(t_lst *head)
{
	if (head != NULL)
		free_lst(head);
	ft_panic(1);
}
