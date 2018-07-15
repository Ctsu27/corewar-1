/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strdel_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:48:53 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:58 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_strdel_two(char **as, char **asbis)
{
	if (as == NULL || !(*as))
		return ;
	free(*as);
	*as = NULL;
	if (asbis == NULL || !(*asbis))
		return ;
	free(*asbis);
	*asbis = NULL;
}
