/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:07:13 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:41 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			lo_free_strtab(char ***tab)
{
	int i;

	if (!*tab || !tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		lo_strdel(&((*tab)[i]));
		i++;
	}
	free(*tab);
	tab = NULL;
}
